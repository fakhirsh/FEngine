//
//  State.h
//  WordGame
//
//  Created by Fakhir Shaheen on 01/11/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "../PointerDefs.h"

#include "../../3rdParty/glm-0.9.6.3/glm/glm.hpp"

namespace FEngine
{

    //typedef std::vector<class ScreenElement *> ScreenElementList;
    
    class State
    {
        friend class StateManager;
        
    public:
        // Please add some comments
        State();
        virtual ~State();
        
        // Loads game assets and sounds etc
        virtual bool    Load            ()  =   0;
        virtual bool    UnLoad          ()  =   0;
        
        // Initialises important data structures.
        virtual bool    Init            ()  =   0;
        virtual void    Free            ()  =   0;
        
        virtual void    Pause           ()  =   0;
        virtual void    Resume          ()  =   0;
        
        virtual void    Update          (float dt)           =   0;
        virtual void    Render          (float dt = 0.0f)    =   0;

        bool            IsPaused        ();
        
    protected:
        
        bool                    _isPaused;
        ActorManagerPtr         _actorManager;
        ProcessSchedulerPtr     _processScheduler;
        EventDispatcherPtr      _eventDispatcher;
        PhysicsManagerPtr       _physicsManager;
        SceneNode2DPtr          _rootSceneNode2D;
        SceneNode2DPtr          _debugNode2D;
        
        //std::stack<glm::mat4>   _matrixStack2D;
        
        // 3D Scene graph
        //SceneNodePtr          _rootSceneNode;
        
        //ScreenElementList     _screenElements;
        
    };

};


