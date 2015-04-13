//
//  PhysicsFactory.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 28/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "PhysicsFactory.h"


#include <string>
#include <iostream>
#include <list>
//#include <cstdlib>


#include "../../ActorManager/Actor.h"
#include "../../ActorManager/Components/PhysicsComponent.h"
#include "../../ActorManager/Components/TransformComponent.h"
#include "../../ActorManager/Components/ViewComponent.h"
#include "../../ActorManager/Components/InputComponent.h"

#include "../../EventDispatcher/EventDispatcher.h"
#include "../../EventDispatcher/DefaultEvents.h"
#include "../../StateManager/StateManager.h"

#include "../../2D/SpriteNode.h"
#include "../../2D/SceneNode2D.h"
#include "../../2D/SceneNodeProperties2D.h"
#include "../../2D/DebugCircleNode2D.h"
#include "../../2D/DebugBoxNode2D.h"

#include "../../PhysicsManager/PhysicsManager.h"

#include "../../Utility/Math.h"
#include "../../ResourceCache/IOManager.h"
#include "../../System/App.h"

#include "View2DFactory.h"
#include "ProgramFactory.h"


extern FEngine::App * gApp;

namespace FEngine
{

    using namespace tinyxml2;
    using namespace std;
    
    
    PhysicsFactory::PhysicsShape::PhysicsShape()
    {
        fixtureProp = boost::make_shared<FixtureProperties>();
    }
    
    PhysicsFactory::PhysicsShape::~PhysicsShape()
    {
        //if(fixtureShape) delete fixtureShape;
        //fixtureShape = NULL;
    }
    
    
    PhysicsFactory::PhysicsFactory()
    {

    }
    
    PhysicsFactory::~PhysicsFactory()
    {
    
    }
    
    PhysicsComponentPtr PhysicsFactory::CreatePhysicsComponent(std::string xmlFilePath)
    {
        
        IOManager * ioMgr = gApp->GetIOManager();
        
        std::vector<char> metaData;
        
        // Get full path to meta data
        std::string fullMetaPath = gApp->GetAssetPath() + xmlFilePath;
        // Read raw byte stream from the source file
        ioMgr->GetAssetStream(fullMetaPath, metaData);
        
        std::string metaString;
        for (int i = 0; i < metaData.size(); i++){
            metaString += metaData[i];
        }
        
        // Load atlas meta data from raw XML stream
        
        XMLDocument coordXMLdoc;
        XMLError xmlErr;
        
        xmlErr = coordXMLdoc.Parse(metaString.c_str());
        
        if(xmlErr != XML_SUCCESS){
            std::cout << "ActorFactory::CreateActor -> Failed to parse actor XML " << xmlFilePath << std::endl;
            // Return a NULL pointer
            return PhysicsComponentPtr();
        }
        
        // Root node (Physics)
        XMLNode * rootNode = coordXMLdoc.FirstChild();
        
        const XMLElement * e = rootNode->ToElement();
        
        PhysicsComponentPtr physicsComponent = boost::make_shared<PhysicsComponent>();
        physicsComponent->_bodyProperties->name = e->Attribute("name");
        
        b2BodyDef body;
        
        std::string bodyTypeStr = e->Attribute("bodyType");
        b2BodyType bodyType = b2_staticBody;
        if(bodyTypeStr == "Dynamic")
        {
            bodyType = b2_dynamicBody;
        }
        else if(bodyTypeStr == "Static")
        {
            bodyType = b2_staticBody;
        }
        else if(bodyTypeStr == "Kinematic")
        {
            bodyType = b2_kinematicBody;
        }
        else
        {
            std::cout << "Invalid body type: " << bodyTypeStr << std::endl;
            return PhysicsComponentPtr();
        }
        
        body.type = bodyType;
        
        
        std::vector<boost::shared_ptr<PhysicsFactory::PhysicsShape> > shapesArray;
        
        e = e->FirstChildElement();
        
        while(e)
        {
            if(string(e->Value()) == string("Transform"))
            {
                float x, y, angle;
                sscanf(e->Attribute("x"), "%f", &x);
                sscanf(e->Attribute("y"), "%f", &y);
                sscanf(e->Attribute("angle"), "%f", &angle);
                
                body.position.Set(x / PhysicsManager::PTM_RATIO, y / PhysicsManager::PTM_RATIO);
                body.angle =  Math::DegToRad(angle);
            }
            else if(string(e->Value()) == string("Shape"))
            {
                shapesArray.push_back(CreateShape(e));
            }
            else if(string(e->Value()) == string("Bullet"))
            {
                if(string(e->Attribute("value")) == string("true")){
                    body.bullet = true;
                }
            }
            
            e = e->NextSiblingElement();
        }
        
        physicsComponent->_bodyProperties->body = StateManager::Get()->GetPhysicsManager()->GetWorld()->CreateBody(&body);
        
        for (int i = 0; i < shapesArray.size(); i++) {
            
            FixturePropertiesPtr fPtr = boost::make_shared<FixtureProperties>();
            
            fPtr->fixture = physicsComponent->_bodyProperties->body->CreateFixture(&((shapesArray[i])->fixtureDef));
            fPtr->fixture->SetUserData((void *)fPtr.get());
            
            if(shapesArray[i]->fixtureProp->debugNode){
                fPtr->debugNode = shapesArray[i]->fixtureProp->debugNode;
            }
            
            physicsComponent->_bodyProperties->body->SetUserData((void *)physicsComponent.get());
            
            physicsComponent->_bodyProperties->fixtureList.push_back(fPtr);
        }
        
        return physicsComponent;
    }
    
    boost::shared_ptr<PhysicsFactory::PhysicsShape> PhysicsFactory::CreateShape(const tinyxml2::XMLElement * physicsElement)
    {
        boost::shared_ptr<PhysicsFactory::PhysicsShape> pShape = boost::make_shared<PhysicsFactory::PhysicsShape>();
        
        if(string(physicsElement->Attribute("shapeType")) == string("Box"))
        {
            pShape->shapeType = "Box";
            CreateBox(physicsElement, pShape);
        }
        else if(string(physicsElement->Attribute("shapeType")) == string("Circle"))
        {
            pShape->shapeType = "Circle";
            CreateCircle(physicsElement, pShape);
        }
        
        return pShape;
    }
    
    void PhysicsFactory::CreateBox(const tinyxml2::XMLElement * physicsElement, boost::shared_ptr<PhysicsFactory::PhysicsShape> & fixture)
    {
        const XMLElement * e = physicsElement->FirstChildElement();
        
        while (e) {
            if(string(e->Value()) == string("View"))
            {
                // TODO: To be supported in the future
                fixture->fixtureProp->viewName = e->Attribute("nodeName");
            }
            else if(string(e->Value()) == string("Offset"))
            {
                float offX, offY;
                sscanf(e->Attribute("x"), "%f", &offX);
                sscanf(e->Attribute("y"), "%f", &offY);
                
                fixture->offset.x = offX;
                fixture->offset.y = offY;
            }
            else if(string(e->Value()) == string("Dimensions"))
            {
                float width, height;
                sscanf(e->Attribute("width"), "%f", &width);
                sscanf(e->Attribute("height"), "%f", &height);
                
                //fixture.fixtureShape = new b2PolygonShape();
                fixture->fixtureShape = boost::make_shared<b2PolygonShape>();
                boost::shared_ptr<b2PolygonShape> p = boost::static_pointer_cast<b2PolygonShape>(fixture->fixtureShape);
                //p->m_centroid = b2Vec2(1, 1);
                p->SetAsBox(width / 2.0f / PhysicsManager::PTM_RATIO, height / 2.0f / PhysicsManager::PTM_RATIO);
                fixture->fixtureDef.shape = (b2Shape *)p.get();
                
                if(gApp->IsDebugModeOn()){
                    
                    ProgramFactory pf;
                    fixture->fixtureProp->debugNode = boost::make_shared<DebugBoxNode2D>();
                    fixture->fixtureProp->debugNode->GetSceneNodeProperties()->program = pf.CreateProgram("SimpleVertex2D");
                    fixture->fixtureProp->debugNode->GetSceneNodeProperties()->width = width;
                    fixture->fixtureProp->debugNode->GetSceneNodeProperties()->height = height;
                    //fixture->fixtureProp->debugNode->GetSceneNodeProperties()->x = x;
                    //fixture->fixtureProp->debugNode->GetSceneNodeProperties()->y = y;
                    fixture->fixtureProp->debugNode->GetSceneNodeProperties()->alpha = 0.4;
                    fixture->fixtureProp->debugNode->SetID(gApp->GetNextGUID());
                    
                    SceneNode2DPtr dRoot = StateManager::Get()->GetDebugNode2D();
                    dRoot->AddChild(fixture->fixtureProp->debugNode);
                    
                }
                
            }
            else if(string(e->Value()) == string("Properties"))
            {
                float density, friction, restitution;
                sscanf(e->Attribute("density"), "%f", &density);
                sscanf(e->Attribute("friction"), "%f", &friction);
                sscanf(e->Attribute("restitution"), "%f", &restitution);
                
                fixture->fixtureDef.density = density;
                fixture->fixtureDef.friction = friction;
                fixture->fixtureDef.restitution = restitution;
            }
            else if(string(e->Value()) == string("Sensor"))
            {
                if(string(e->Attribute("value")) == string("true")){
                    fixture->fixtureDef.isSensor = true;
                }
            }
            
            e = e->NextSiblingElement();
        }
        
    }
    
    void PhysicsFactory::CreateCircle(const tinyxml2::XMLElement * physicsElement, boost::shared_ptr<PhysicsFactory::PhysicsShape> & fixture)
    {
        const XMLElement * e = physicsElement->FirstChildElement();
     
        while (e) {
            if(string(e->Value()) == string("View"))
            {
                // TODO: To be supported in the future
                fixture->fixtureProp->viewName = e->Attribute("nodeName");
            }
            else if(string(e->Value()) == string("Offset"))
            {
                float offX, offY;
                sscanf(e->Attribute("x"), "%f", &offX);
                sscanf(e->Attribute("y"), "%f", &offY);
                
                fixture->offset.x = offX;
                fixture->offset.y = offY;
            }
            else if(string(e->Value()) == string("Dimensions"))
            {
                float radius;
                sscanf(e->Attribute("radius"), "%f", &radius);

                fixture->fixtureShape = boost::make_shared<b2CircleShape>();
                boost::shared_ptr<b2CircleShape> p = boost::static_pointer_cast<b2CircleShape>(fixture->fixtureShape);
                p->m_p.Set(0, 0); //position, relative to body position
                p->m_radius = radius / PhysicsManager::PTM_RATIO; //radius
                fixture->fixtureDef.shape = (b2Shape *)p.get();
                
                if(gApp->IsDebugModeOn()){
                
                    ProgramFactory pf;
                    fixture->fixtureProp->debugNode = boost::make_shared<DebugCircleNode2D>();
                    fixture->fixtureProp->debugNode->GetSceneNodeProperties()->program = pf.CreateProgram("SimpleVertex2D");
                    fixture->fixtureProp->debugNode->GetSceneNodeProperties()->width = radius;
                    fixture->fixtureProp->debugNode->GetSceneNodeProperties()->height = radius;
                    //fixture->fixtureProp->debugNode->GetSceneNodeProperties()->x = x;
                    //fixture->fixtureProp->debugNode->GetSceneNodeProperties()->y = y;
                    fixture->fixtureProp->debugNode->GetSceneNodeProperties()->alpha = 0.4;
                    
                    fixture->fixtureProp->debugNode->SetID(gApp->GetNextGUID());
                    
                    SceneNode2DPtr dRoot = StateManager::Get()->GetDebugNode2D();
                    dRoot->AddChild(fixture->fixtureProp->debugNode);
                    
                }
                
            }
            else if(string(e->Value()) == string("Properties"))
            {
                float density, friction, restitution;
                sscanf(e->Attribute("density"), "%f", &density);
                sscanf(e->Attribute("friction"), "%f", &friction);
                sscanf(e->Attribute("restitution"), "%f", &restitution);
                
                fixture->fixtureDef.density = density;
                fixture->fixtureDef.friction = friction;
                fixture->fixtureDef.restitution = restitution;
            }
            else if(string(e->Value()) == string("Sensor"))
            {
                if(string(e->Attribute("value")) == string("true")){
                    fixture->fixtureDef.isSensor = true;
                }
            }
            
            e = e->NextSiblingElement();
        }

    }
    
}