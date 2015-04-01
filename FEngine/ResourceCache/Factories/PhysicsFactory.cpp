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
        
        // Root node (Actor)
        XMLNode * rootNode = coordXMLdoc.FirstChild();
        
        const XMLElement * e = rootNode->FirstChildElement();
        
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

        e = e->NextSiblingElement();
        
        PhysicsComponentPtr physicsComponent = boost::make_shared<PhysicsComponent>();
        
        if(string(e->Attribute("value")) == string("Circle"))
        {
            float x, y, radius, angle;
            sscanf(e->Attribute("x"), "%f", &x);
            sscanf(e->Attribute("y"), "%f", &y);
            sscanf(e->Attribute("radius"), "%f", &radius);
            sscanf(e->Attribute("angle"), "%f", &angle);
            
            b2BodyDef myBodyDef;
            myBodyDef.type  =   bodyType;
            myBodyDef.position.Set(x / PhysicsManager::PTM_RATIO, y / PhysicsManager::PTM_RATIO);
            myBodyDef.angle =  Math::DegToRad(angle);
            
            b2CircleShape circleShape;
            circleShape.m_p.Set(0, 0); //position, relative to body position
            circleShape.m_radius = radius / PhysicsManager::PTM_RATIO; //radius
            
            b2FixtureDef myFixtureDef;
            myFixtureDef.shape = &circleShape; //this is a pointer to the shape above
            myFixtureDef.density = 1.0f;
            myFixtureDef.friction = 0.9f;
            //myFixtureDef.restitution = 1.0f;
            
            
            physicsComponent->_body = StateManager::Get()->GetPhysicsManager()->GetWorld()->CreateBody(&myBodyDef);
            
            physicsComponent->_body->CreateFixture(&myFixtureDef); //add a fixture to the body
            
            if(gApp->IsDebugModeOn())
            {
                ProgramFactory pf;
            
                SceneNode2DPtr pdnPtr = boost::make_shared<DebugCircleNode2D>();
                pdnPtr->GetSceneNodeProperties()->program = pf.CreateProgram("SimpleVertex2D");
                pdnPtr->GetSceneNodeProperties()->width = radius;
                pdnPtr->GetSceneNodeProperties()->height = radius;
                pdnPtr->GetSceneNodeProperties()->x = x;
                pdnPtr->GetSceneNodeProperties()->y = y;
                pdnPtr->GetSceneNodeProperties()->alpha = 0.4;

                pdnPtr->SetID(gApp->GetNextGUID());
                
                SceneNode2DPtr dRoot = StateManager::Get()->GetDebugNode2D();
                dRoot->AddChild(pdnPtr);
                
                // ---- WARNING ----
                // Send raw pointer in userdata. The local smart pointers will be destroyed
                //    right after exiting this scope...
                physicsComponent->_body->SetUserData((void *)pdnPtr.get());
            }
        
        }
        else if(string(e->Attribute("value")) == string("Box"))
        {
            float x, y, width, height, angle;
            sscanf(e->Attribute("x"), "%f", &x);
            sscanf(e->Attribute("y"), "%f", &y);
            sscanf(e->Attribute("width"), "%f", &width);
            sscanf(e->Attribute("height"), "%f", &height);
            sscanf(e->Attribute("angle"), "%f", &angle);
            
            b2BodyDef myBodyDef;
            myBodyDef.type  =   bodyType;
            myBodyDef.position.Set(0.0f, 0.0f);
            myBodyDef.angle =   Math::DegToRad(angle);

            b2PolygonShape polygonShape;
            polygonShape.SetAsBox(width / 2.0f / PhysicsManager::PTM_RATIO, height / 2.0f / PhysicsManager::PTM_RATIO);
            myBodyDef.position.Set(x / PhysicsManager::PTM_RATIO, y / PhysicsManager::PTM_RATIO);
            
            b2FixtureDef myFixtureDef;
            myFixtureDef.shape = &polygonShape; //this is a pointer to the shape above
            myFixtureDef.density = 1.0f;
            myFixtureDef.friction = 0.9f;
            //myFixtureDef.restitution = 1.0f;
            
            physicsComponent->_body = StateManager::Get()->GetPhysicsManager()->GetWorld()->CreateBody(&myBodyDef);
            
            physicsComponent->_body->CreateFixture(&myFixtureDef); //add a fixture to the body
            
            if(gApp->IsDebugModeOn())
            {
                ProgramFactory pf;
                
                SceneNode2DPtr pdnPtr = boost::make_shared<DebugBoxNode2D>();
                pdnPtr->GetSceneNodeProperties()->program = pf.CreateProgram("SimpleVertex2D");
                pdnPtr->GetSceneNodeProperties()->width = width;
                pdnPtr->GetSceneNodeProperties()->height = height;
                pdnPtr->GetSceneNodeProperties()->x = x;
                pdnPtr->GetSceneNodeProperties()->y = y;
                pdnPtr->GetSceneNodeProperties()->alpha = 0.4;
                
                SceneNode2DPtr dRoot = StateManager::Get()->GetDebugNode2D();
                dRoot->AddChild(pdnPtr);
                
                // ---- WARNING ----
                // Send raw pointer in userdata. The local smart pointers will be destroyed
                //    right after exiting this scope...
                physicsComponent->_body->SetUserData((void *)pdnPtr.get());
            }

        }
        
        return physicsComponent;
    }
    
}