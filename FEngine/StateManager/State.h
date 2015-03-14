//
//  State.h
//  WordGame
//
//  Created by Fakhir Shaheen on 01/11/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#ifndef __WordGame__State__
#define __WordGame__State__

//#include "../Common.h"

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
        virtual bool Load()     =   0;
        virtual bool UnLoad()   =   0;
        
        // Initialises important data structures.
        virtual bool Init()     =   0;
        virtual void Free()     =   0;
        
        virtual void Pause()    =   0;
        virtual void Resume()   =   0;
        
        virtual void Update(float dt)           =   0;
        virtual void Render(float dt = 0.0f)    =   0;

        bool    IsPaused();
        
    protected:
        
        bool                _isPaused;
        //ProcessManagerPtr  _processMgr;
        //EventManagerPtr    _eventMgr;
        //class SceneNode *   _rootSceneNode;
        //ScreenElementList _screenElements;
        
    };

};

#endif /* defined(__WordGame__State__) */
