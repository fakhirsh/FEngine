//
//  StateManager.cpp
//  WordGame
//
//  Created by Fakhir Shaheen on 01/11/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#include "StateManager.h"

#include "../Common.h"
#include "State.h"
#include "../ProcessScheduler/ProcessScheduler.h"
#include "../EventDispatcher/EventDispatcher.h"
#include "../ActorManager/ActorManager.h"
#include "../2D/RootSceneNode2D.h"


namespace FEngine
{

    StateManager * StateManager::_instance = NULL;


    StateManager::StateManager()
    {

    }

    StateManager::~StateManager()
    {
        if(_instance) delete _instance;
        _instance = NULL;
    }

    StateManager * const StateManager::Get()
    {
        if(!_instance)
        {
            _instance = new StateManager();
            //_instance = boost::make_shared<FEngine::StateManager>();
            
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
            _statesList.back()->_actorManager->Update(dt);
            _statesList.back()->_processScheduler->Update(dt);
            _statesList.back()->_eventDispatcher->Update(dt);
        }
    }

    void StateManager::Render(float dt)
    {
        if (!_statesList.empty())
        {
            _statesList.back()->_rootSceneNode2D->Render(dt);
            _statesList.back()->Render(dt);
            
        }
    }
    
    ProcessSchedulerPtr StateManager::GetProcessScheduler()
    {
        if (!_statesList.empty())
        {
            return _statesList.back()->_processScheduler;
        }
        
        // Return a NULL_PTR if there are no states to process...
        // This will RARELY happen though !!!
        return ProcessSchedulerPtr();
    }

    EventDispatcherPtr StateManager::GetEventDispatcher()
    {
        if (!_statesList.empty())
        {
            return _statesList.back()->_eventDispatcher;
        }
        
        // Return a NULL_PTR if there are no states to process...
        // This will RARELY happen though !!!
        return EventDispatcherPtr();

    }
    
    SceneNode2DPtr StateManager::GetRootSceneNode2D ()
    {
        if (!_statesList.empty())
        {
            return _statesList.back()->_rootSceneNode2D;
        }
        
        return SceneNode2DPtr();
    }

    ActorManagerPtr StateManager::GetActorManager ()
    {
        if (!_statesList.empty())
        {
            return _statesList.back()->_actorManager;
        }
        
        return ActorManagerPtr();
    }
    
    void StateManager::PushTransform2D (glm::mat4  transformMatrix)
    {
        _matrixStack2D.push(transformMatrix);
    }
    
    glm::mat4 StateManager::PeekTransform2D ()
    {
        return _matrixStack2D.top();
    }
    
    void StateManager::PopTransform2D ()
    {
        _matrixStack2D.pop();
    }

    
};