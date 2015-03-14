//
//  StateManager.cpp
//  WordGame
//
//  Created by Fakhir Shaheen on 01/11/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#include "StateManager.h"
#include "State.h"
//#include "../ProcessManager/ProcessManager.h"
//#include "../EventManager/EventManager.h"


namespace FEngine
{

    StateManager * StateManager::_instance = (StateManager *)0;


    StateManager::StateManager()
    {

    }

    StateManager::~StateManager()
    {
        if(_instance) delete _instance;
        _instance = NULL;
    }

    StateManager * StateManager::Get()
    {
        if(!_instance)
        {
            _instance = new StateManager();
            _instance->Init();
        }
        return _instance;
    }

    bool StateManager::Init()
    {
        return true;
    }

    void StateManager::ChangeState(StatePtr newState)
    {
        if (!_statesList.empty()) {
            _statesList.back()->Free();
            _statesList.back()->UnLoad();
            _statesList.pop_back();
        }
        
        _statesList.push_back(newState);
        _statesList.back()->Load();
        _statesList.back()->Init();
    }

    void StateManager::PushState(StatePtr newState)
    {
        // First pause current state
        if (!_statesList.empty())
        {
            _statesList.back()->Pause();
        }
        
        // Store and Initialize new state
        _statesList.push_back(newState);
        _statesList.back()->Load();
        _statesList.back()->Init();
    }

    void StateManager::PopState()
    {
        // Cleanup current state and pop it out of the state stack
        if (!_statesList.empty())
        {
            _statesList.back()->Free();
            _statesList.back()->UnLoad();
            _statesList.pop_back();
        }
        
        // Resume previous state
        if (!_statesList.empty())
        {
            _statesList.back()->Resume();
        }
    }

    void StateManager::Update(float dt)
    {
        if (!_statesList.empty())
        {
            _statesList.back()->Update(dt);
            //_statesList.back()->_processMgr->Update(dt);
            //_statesList.back()->_eventMgr->Update(dt);
        }
    }

    void StateManager::Render(float dt)
    {
        if (!_statesList.empty())
        {
            _statesList.back()->Render(dt);
        }
    }
/*
    void StateManager::TouchDown(int x, int y)
    {
        if (!_statesList.empty())
        {
            _statesList.back()->TouchDown(x, y);
        }
    }

    void StateManager::TouchUp(int x, int y)
    {
        if (!_statesList.empty())
        {
            _statesList.back()->TouchUp(x, y);
        }
    }

    void StateManager::TouchMoved(int x, int y)
    {
        if (!_statesList.empty())
        {
            _statesList.back()->TouchMoved(x, y);
        }
    }

    void StateManager::TouchCancelled(int x, int y)
    {
        if (!_statesList.empty())
        {
            _statesList.back()->TouchCancelled(x, y);
        }
    }
*/
    /*
    ProcessManagerPtr StateManager::GetProcessManager()
    {
        if (!_statesList.empty())
        {
            return _statesList.back()->_processMgr;
        }
        
        // Return a NULL_PTR if there are no states to process...
        // This will RARELY happen though !!!
        return boost::shared_ptr<Fakhir::ProcessManager>();
    }

    EventManagerPtr StateManager::GetEventManager()
    {
        if (!_statesList.empty())
        {
            return _statesList.back()->_eventMgr;
        }
        
        // Return a NULL_PTR if there are no states to process...
        // This will RARELY happen though !!!
        return boost::shared_ptr<Fakhir::EventManager>();

    }
    
    SceneNode * StateManager::GetRootSceneNode()
    {
        if (!_statesList.empty())
        {
            return _statesList.back()->_rootSceneNode;
        }
        
        return NULL;
    }
*/
    
};