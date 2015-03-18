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

//#include "../Graphics2D/RootSceneNode.h"

namespace FEngine
{

    State::State()
    {
        _isPaused           =   false;
        _processScheduler   =   boost::make_shared<FEngine::ProcessScheduler>();
        _eventDispatcher    =   boost::make_shared<FEngine::EventDispatcher>();
        //_rootSceneNode = new RootSceneNode();
    }

    State::~State()
    {

    }

    bool State::IsPaused()
    {
        return _isPaused;
    }

};