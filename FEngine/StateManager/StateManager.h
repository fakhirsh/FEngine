//
//  StateManager.h
//  WordGame
//
//  Created by Fakhir Shaheen on 01/11/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#ifndef __WordGame__StateManager__
#define __WordGame__StateManager__


#include "../Common.h"


namespace FEngine
{

    // PLEASE ADD COMMENTS About how to use this class
    
    /**
     *    Every State has its OWN Process Manager, Event Manager and SceneGraph.
     */
    
    class StateManager
    {
    public:
        ~StateManager();
        
        static StateManager * Get();
        
        bool    Init();
        
        void    ChangeState(StatePtr newState);
        // Push the current state and Load new state on top of it
        void    PushState(StatePtr newState);
        void    PopState();

        void    Update(float dt);
        void    Render(float dt = 0.0f);
        
        //ProcessManagerPtr  GetProcessManager();
        //EventManagerPtr    GetEventManager();
        //class SceneNode *    GetRootSceneNode();
        
        //void    TouchDown(int x, int y);
        //void    TouchUp(int x, int y);
        //void    TouchMoved(int x, int y);
        //void    TouchCancelled(int x, int y);
        
    private:
        StateManager();
        
        static StateManager *  _instance;
        
        std::vector<StatePtr>  _statesList;

    };

};

#endif /* defined(__WordGame__StateManager__) */
