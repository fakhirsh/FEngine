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

#include "../../3rdParty/PennerEasing/PennerEasing/Linear.h"
#include "../../3rdParty/PennerEasing/PennerEasing/Elastic.h"
#include "../../3rdParty/PennerEasing/PennerEasing/Expo.h"
#include "../../3rdParty/PennerEasing/PennerEasing/Quad.h"

#include <iostream>

namespace FEngine
{
    ProcessDelay::ProcessDelay()
    {
        _pID        =   1;
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

    /*----------------------------------------------------------------------------------------------------
     *----------------------------------------------------------------------------------------------------
     *----------------------------------------------------------------------------------------------------
     *             Gameplay Related Processes...
     *----------------------------------------------------------------------------------------------------
     *----------------------------------------------------------------------------------------------------
     *----------------------------------------------------------------------------------------------------*/

    
    ProcessRotate::ProcessRotate()
    {
        _pID        =   1;
        _elapsed    =   0.0f;
        DURATION    =   0.0f;
        ANGLE_START =   0.0f;
        ANGLE_END   =   0.0f;
    }
    
    ProcessRotate::~ProcessRotate(){}
    
    void ProcessRotate::Update(float dt)
    {
        _elapsed += dt;
        
        float A = Elastic::easeOut(_elapsed, ANGLE_START, ANGLE_END, DURATION);
        
        node->GetSceneNodeProperties()->angle = A;
        
        if(_elapsed >= DURATION)
        {
            Succeed();
        }
    }

    
////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    ProcessTranslate::ProcessTranslate()
    {
        _pID        =   1;
        _elapsed    =   0.0f;
        DURATION    =   0.0f;
    }
    
    ProcessTranslate::~ProcessTranslate(){}
    
    void ProcessTranslate::Update(float dt)
    {
        _elapsed += dt;

        float X = Quad::easeIn(_elapsed, POINT_START.x, POINT_END.x, DURATION);
        float Y = Quad::easeIn(_elapsed, POINT_START.y, POINT_END.y, DURATION);
        
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
        _pID        =   1;
        _elapsed    =   0.0f;
        DURATION    =   0.0f;
    }
    
    ProcessScale::~ProcessScale(){}
    
    void ProcessScale::Update(float dt)
    {
        _elapsed += dt;
        
        float X = Elastic::easeOut(_elapsed, SCALE_START.x, SCALE_END.x, DURATION);
        float Y = Elastic::easeOut(_elapsed, SCALE_START.y, SCALE_END.y, DURATION);
        
        node->GetSceneNodeProperties()->scaleX = X;
        node->GetSceneNodeProperties()->scaleY = Y;
        
        if(_elapsed >= DURATION)
        {
            Succeed();
        }
    }

    
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
        boost::shared_ptr<EventCandyConsumed> e = boost::make_shared<EventCandyConsumed>();
        StateManager::Get()->GetEventDispatcher()->DispatchEvent(e);
        
        Succeed();
    }
    
    
}