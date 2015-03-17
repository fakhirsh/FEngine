//
//  Process.h
//  FEngine
//
//  Created by Fakhir Shaheen on 17/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//


#pragma once

#include "../PointerDefs.h"

namespace FEngine
{

    /*!
     *      Process abstract class. Defines various process states;
     */
    class Process
    {
    public:
        Process();
        virtual ~Process();
        
        
        enum State{CREATED = 1, READY, RUNNING, WAITING, SUCCEEDED, FAILED, TERMINATED};
        
        unsigned long GetID();
        void SetID(unsigned long pPID);
        
        bool    IsFinished();
        
        void    Pause();
        void    Resume();
        void    Succeed();
        void    Fail();
        void    Terminate();
        
        State   GetState();
        
        virtual void Update(float dt) = 0;
        
        void        AddChild(ProcessPtr pChild);
        ProcessPtr  RemoveChild();
        
    protected:
        unsigned int    _pID;
        State           _state;

        ProcessPtr _child;
        
    };
    
};