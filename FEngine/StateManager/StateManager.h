//
//  StateManager.h
//  WordGame
//
//  Created by Fakhir Shaheen on 01/11/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//


#pragma once

#include <vector>
#include <stack>

#include "../PointerDefs.h"
#include "../../3rdParty/glm-0.9.6.3/glm/glm.hpp"


namespace FEngine
{

    // PLEASE ADD COMMENTS About how to use this class
    
    /**
     *    Every State has its OWN Process Scheduler, Event Dispatcher and SceneGraph.
     */
    
    class StateManager
    {
    public:
        ~StateManager();
        
        static StateManager * const Get         ();
        
        bool                Init                ();
        
        void                ChangeState         (StatePtr newState);
        
        // Push the current state and Load new state on top of it
        void                PushState           (StatePtr newState);
        void                PopState            ();

        void                Update              (float dt);
        void                Render              (float dt = 0.0f);
        
        ActorManagerPtr     GetActorManager     ();
        ProcessSchedulerPtr GetProcessScheduler ();
        EventDispatcherPtr  GetEventDispatcher  ();
        PhysicsManagerPtr   GetPhysicsManager   ();
        SceneNode2DPtr      GetRootSceneNode2D  ();
        SceneNode2DPtr      GetDebugNode2D      ();
        
        // 3D Scene graph ... To be implemented later
        //SceneNodePtr        GetRootSceneNode    ();
        
        void                PushTransform2D     (glm::mat4  transformMatrix);
        glm::mat4           PeekTransform2D     ();
        void                PopTransform2D      ();
        
    private:
        StateManager();
        
        static StateManager *   _instance;
        
        std::vector<StatePtr>   _statesList;

        std::stack<glm::mat4>   _matrixStack2D;
        
    };

};

