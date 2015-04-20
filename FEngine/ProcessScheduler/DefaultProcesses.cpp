//
//  DefaultProcesses.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 17/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "DefaultProcesses.h"

#include "../EventDispatcher/DefaultEvents.h"
#include "../EventDispatcher/EventDispatcher.h"
#include "../StateManager/StateManager.h"
#include "../2D/SceneNodeProperties2D.h"
#include "../2D/SceneNode2D.h"

#include "../ActorManager/Actor.h"
#include "../ActorManager/Components/PhysicsComponent.h"

#include "../../3rdParty/PennerEasing/PennerEasing/Linear.h"
#include "../../3rdParty/PennerEasing/PennerEasing/Elastic.h"
#include "../../3rdParty/PennerEasing/PennerEasing/Expo.h"
#include "../../3rdParty/PennerEasing/PennerEasing/Quad.h"


#include <iostream>

namespace FEngine
{
    ProcessDelay::ProcessDelay()
    {
        _elapsed    =   0.0f;
        DELAY       =   0.0f;
    }
    
    ProcessDelay::~ProcessDelay(){}
    
    void ProcessDelay::Update(float dt)
    {
        _elapsed += dt;
        
        if(_elapsed >= DELAY)
        {
            Succeed();
        }
    }
    
////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    ProcessRotate::ProcessRotate()
    {
        _elapsed    =   0.0f;
        DURATION    =   0.0f;
        START       =   0.0f;
        ROTATE_BY   =   0.0f;
    }
    
    ProcessRotate::~ProcessRotate(){}
    
    void ProcessRotate::Update(float dt)
    {
        _elapsed += dt;
        
        float A = Elastic::easeOut(_elapsed, START, ROTATE_BY, DURATION);
        
        node->GetSceneNodeProperties()->angle = A;
        
        if(_elapsed >= DURATION)
        {
            Succeed();
        }
    }

    
////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    ProcessTranslate::ProcessTranslate()
    {
        _elapsed    =   0.0f;
        DURATION    =   0.0f;
    }
    
    ProcessTranslate::~ProcessTranslate(){}
    
    void ProcessTranslate::Update(float dt)
    {
        _elapsed += dt;

        float X = Quad::easeIn(_elapsed, START.x, TRANSLATE_BY.x, DURATION);
        float Y = Quad::easeIn(_elapsed, START.y, TRANSLATE_BY.y, DURATION);
        
        node->GetSceneNodeProperties()->x = X;
        node->GetSceneNodeProperties()->y = Y;
        
        if(_elapsed >= DURATION)
        {
            Succeed();
        }
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    ProcessScale::ProcessScale()
    {
        _elapsed    =   0.0f;
        DURATION    =   0.0f;
    }
    
    ProcessScale::~ProcessScale(){}
    
    void ProcessScale::Update(float dt)
    {
        _elapsed += dt;
        
        float X = Elastic::easeOut(_elapsed, START.x, SCALE_BY.x, DURATION);
        float Y = Elastic::easeOut(_elapsed, START.y, SCALE_BY.y, DURATION);
        
        node->GetSceneNodeProperties()->scaleX = X;
        node->GetSceneNodeProperties()->scaleY = Y;
        
        if(_elapsed >= DURATION)
        {
            Succeed();
        }
    }

////////////////////////////////////////////////////////////////////////////////////////////////////////

    ProcessCallFn::ProcessCallFn()
    {
        _elapsed    =   0.0f;
        DELAY       =   0.0f;
    }
    
    ProcessCallFn::~ProcessCallFn(){}
    
    void ProcessCallFn::Update(float dt)
    {
        _elapsed += dt;

        if(_elapsed >= DELAY)
        {
            pFn();
            
            Succeed();
        }
    }
    
////////////////////////////////////////////////////////////////////////////////////////////////////////

    /*----------------------------------------------------------------------------------------------------
     *----------------------------------------------------------------------------------------------------
     *----------------------------------------------------------------------------------------------------
     *             Gameplay Related Processes...
     *----------------------------------------------------------------------------------------------------
     *----------------------------------------------------------------------------------------------------
     *----------------------------------------------------------------------------------------------------*/

    
        
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    ProcessPrint::ProcessPrint()
    {
        
    }
    
    ProcessPrint::~ProcessPrint()
    {
        
    }
    
    void ProcessPrint::Update(float dt)
    {
        //boost::shared_ptr<EventCandyConsumed> e = boost::make_shared<EventCandyConsumed>();
        //StateManager::Get()->GetEventDispatcher()->DispatchEvent(e);
        
        Succeed();
    }
    
    
}