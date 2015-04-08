//
//  Physics.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 28/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "PhysicsManager.h"
//#include "GLES2DebugDraw.h"

#include <iostream>

#include "../System/App.h"

#include "../2D/SceneNodeProperties2D.h"
#include "../2D/SceneNode2D.h"
#include "../ActorManager/Components/PhysicsComponent.h"

extern FEngine::App * gApp;

namespace FEngine
{
    
    const float PhysicsManager::PTM_RATIO = 32.0f;
    
    PhysicsManager::PhysicsManager()
    {
        Init();
    }
    
    PhysicsManager::~PhysicsManager()
    {
        delete _world;
        _world = NULL;
        
    }
        
    bool PhysicsManager::Init()
    {
        b2Vec2 gravity(0, -9.8);
        bool doSleep = true;
        
        _world = new b2World(gravity);
        _world->SetAllowSleeping(doSleep);
        
        //if(gApp->IsDebugModeOn())
        //{
        //    GLES2DebugDraw debugDraw;
        //    _world->SetDebugDraw( &debugDraw );
        //    debugDraw.SetFlags( b2Draw::e_shapeBit );
        //}
        
        return true;
    }
        
    b2World * const PhysicsManager::GetWorld()
    {
        return _world;
    }
    
    void PhysicsManager::Update(float dt)
    {
        int32 velocityIterations = 10;   //how strongly to correct velocity
        int32 positionIterations = 10;   //how strongly to correct position
        
        _world->Step( dt, velocityIterations, positionIterations);
        
        if(gApp->IsDebugModeOn())
        {
            for ( b2Body* b = _world->GetBodyList(); b; b = b->GetNext())
            {
                PhysicsComponent * pptr = (PhysicsComponent * )b->GetUserData();
                BodyPropertiesPtr bptr = pptr->GetBodyProperties();
                
                if(bptr){
                    FixturePropertiesPtr fptr = bptr->fixtureList[0];
                    fptr->debugNode->GetSceneNodeProperties()->x = b->GetPosition().x * PTM_RATIO;
                    fptr->debugNode->GetSceneNodeProperties()->y = b->GetPosition().y * PTM_RATIO;
                    fptr->debugNode->GetSceneNodeProperties()->angle = Math::RadToDeg(b->GetAngle());
                }
        
            }
        }
    }
    
}

