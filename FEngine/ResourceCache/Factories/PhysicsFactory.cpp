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
        //fixtureShape = NULL;
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
        
        const XMLElement * e = rootNode->FirstChildElement();
        
        PhysicsComponentPtr physicsComponent = boost::make_shared<PhysicsComponent>();

        b2BodyDef body;
        std::vector<PhysicsShape> shapesArray;
        
        while(e)
        {
            if(string(e->Value()) == string("Type"))
            {
                b2BodyType bodyType = b2_staticBody;
                string bodyTypeStr = e->Attribute("value");
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
                
                body.type = bodyType;
            }
            else if(string(e->Value()) == string("Transform"))
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
        
        physicsComponent->_body = StateManager::Get()->GetPhysicsManager()->GetWorld()->CreateBody(&body);
        
        for (int i = 0; i < shapesArray.size(); i++) {
            physicsComponent->_body->CreateFixture(&((shapesArray[i]).fixtureDef));
            
            if((shapesArray[i]).debugNode){
                physicsComponent->_body->SetUserData((void *)(shapesArray[i]).debugNode.get());
            }
        }
        
        return physicsComponent;
    }
    
    PhysicsFactory::PhysicsShape PhysicsFactory::CreateShape(const tinyxml2::XMLElement * physicsElement)
    {
        PhysicsShape pShape;
        
        if(string(physicsElement->Attribute("value")) == string("Box"))
        {
            pShape.shapeType = "Box";
            CreateBox(physicsElement, pShape);
        }
        else if(string(physicsElement->Attribute("value")) == string("Circle"))
        {
            pShape.shapeType = "Circle";
            CreateCircle(physicsElement, pShape);
        }
        
        return pShape;
    }
    /*
    b2FixtureDef PhysicsFactory::CreateShape(const tinyxml2::XMLElement * physicsElement)
    {
        b2FixtureDef shape;
        
        if(string(physicsElement->Attribute("value")) == string("Box"))
        {
            //CreateBox(physicsElement, shape);
        }
        else if(string(physicsElement->Attribute("value")) == string("Circle"))
        {
            //CreateCircle(physicsElement, shape);
        }
        
        return shape;
    }
    */
    void PhysicsFactory::CreateBox(const tinyxml2::XMLElement * physicsElement, PhysicsShape & fixture)
    {
        const XMLElement * e = physicsElement->FirstChildElement();
        
        while (e) {
            if(string(e->Value()) == string("Dimensions"))
            {
                float width, height;
                sscanf(e->Attribute("width"), "%f", &width);
                sscanf(e->Attribute("height"), "%f", &height);
                
                //fixture.fixtureShape = new b2PolygonShape();
                fixture.fixtureShape = boost::make_shared<b2PolygonShape>();
                boost::shared_ptr<b2PolygonShape> p = boost::static_pointer_cast<b2PolygonShape>(fixture.fixtureShape);
                //p->m_centroid = b2Vec2(1, 1);
                p->SetAsBox(width / 2.0f / PhysicsManager::PTM_RATIO, height / 2.0f / PhysicsManager::PTM_RATIO);
                fixture.fixtureDef.shape = (b2Shape *)p.get();
                
                
                if(gApp->IsDebugModeOn()){
                    
                    ProgramFactory pf;
                    fixture.debugNode = boost::make_shared<DebugBoxNode2D>();
                    fixture.debugNode->GetSceneNodeProperties()->program = pf.CreateProgram("SimpleVertex2D");
                    fixture.debugNode->GetSceneNodeProperties()->width = width;
                    fixture.debugNode->GetSceneNodeProperties()->height = height;
                    //fixture.debugNode->GetSceneNodeProperties()->x = x;
                    //fixture.debugNode->GetSceneNodeProperties()->y = y;
                    fixture.debugNode->GetSceneNodeProperties()->alpha = 0.4;
                    fixture.debugNode->SetID(gApp->GetNextGUID());
                    
                    SceneNode2DPtr dRoot = StateManager::Get()->GetDebugNode2D();
                    dRoot->AddChild(fixture.debugNode);
                    
                }
                
            }
            else if(string(e->Value()) == string("Properties"))
            {
                float density, friction, restitution;
                sscanf(e->Attribute("density"), "%f", &density);
                sscanf(e->Attribute("friction"), "%f", &friction);
                sscanf(e->Attribute("restitution"), "%f", &restitution);
                
                fixture.fixtureDef.density = density;
                fixture.fixtureDef.friction = friction;
                fixture.fixtureDef.restitution = restitution;
            }
            else if(string(e->Value()) == string("Sensor"))
            {
                if(string(e->Attribute("value")) == string("true")){
                    fixture.fixtureDef.isSensor = true;
                }
            }
            
            e = e->NextSiblingElement();
        }
        
    }
    
    void PhysicsFactory::CreateCircle(const tinyxml2::XMLElement * physicsElement, PhysicsShape & fixture)
    {
        const XMLElement * e = physicsElement->FirstChildElement();
     
        while (e) {
            if(string(e->Value()) == string("Dimensions"))
            {
                float radius;
                sscanf(e->Attribute("radius"), "%f", &radius);

                fixture.fixtureShape = boost::make_shared<b2CircleShape>();
                boost::shared_ptr<b2CircleShape> p = boost::static_pointer_cast<b2CircleShape>(fixture.fixtureShape);
                p->m_p.Set(0, 0); //position, relative to body position
                p->m_radius = radius / PhysicsManager::PTM_RATIO; //radius
                fixture.fixtureDef.shape = (b2Shape *)p.get();
                
                if(gApp->IsDebugModeOn()){
                
                    ProgramFactory pf;
                    fixture.debugNode = boost::make_shared<DebugCircleNode2D>();
                    fixture.debugNode->GetSceneNodeProperties()->program = pf.CreateProgram("SimpleVertex2D");
                    fixture.debugNode->GetSceneNodeProperties()->width = radius;
                    fixture.debugNode->GetSceneNodeProperties()->height = radius;
                    //fixture.debugNode->GetSceneNodeProperties()->x = x;
                    //fixture.debugNode->GetSceneNodeProperties()->y = y;
                    fixture.debugNode->GetSceneNodeProperties()->alpha = 0.4;
                    
                    fixture.debugNode->SetID(gApp->GetNextGUID());
                    
                    SceneNode2DPtr dRoot = StateManager::Get()->GetDebugNode2D();
                    dRoot->AddChild(fixture.debugNode);
                    
                }
                
            }
            else if(string(e->Value()) == string("Properties"))
            {
                float density, friction, restitution;
                sscanf(e->Attribute("density"), "%f", &density);
                sscanf(e->Attribute("friction"), "%f", &friction);
                sscanf(e->Attribute("restitution"), "%f", &restitution);
                
                fixture.fixtureDef.density = density;
                fixture.fixtureDef.friction = friction;
                fixture.fixtureDef.restitution = restitution;
            }
            else if(string(e->Value()) == string("Sensor"))
            {
                if(string(e->Attribute("value")) == string("true")){
                    fixture.fixtureDef.isSensor = true;
                }
            }
            
            e = e->NextSiblingElement();
        }

    }
    
}