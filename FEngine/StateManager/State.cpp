//
//  FState.cpp
//  WordGame
//
//  Created by Fakhir Shaheen on 01/11/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#include "State.h"

#include "../Common.h"
#include "../ProcessScheduler/ProcessScheduler.h"
#include "../EventDispatcher/EventDispatcher.h"
#include "../ActorManager/ActorManager.h"

#include "../2D/RootSceneNode2D.h"

namespace FEngine
{

    State::State()
    {
        _isPaused           =   false;
        _actorManager       =   boost::make_shared<FEngine::ActorManager>();
        _processScheduler   =   boost::make_shared<FEngine::ProcessScheduler>();
        _eventDispatcher    =   boost::make_shared<FEngine::EventDispatcher>();
        _rootSceneNode2D    =   boost::make_shared<FEngine::RootSceneNode2D>();
        _debugNode2D        =   boost::make_shared<FEngine::RootSceneNode2D>();
    }

    State::~State()
    {

    }

    bool State::IsPaused()
    {
        return _isPaused;
    }

    
    
};