//
//  Process.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 17/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "Process.h"

#include "../Common.h"

namespace FEngine
{
    Process::Process()
    {
        _pID = 0;
        _state = Process::CREATED;
    }
    
    Process::~Process()
    {
        
    }
    
    unsigned long Process::GetID()
    {
        return _pID;
    }
    
    void Process::SetID(unsigned long pPID)
    {
        _pID = pPID;
    }
    
    bool Process::IsFinished()
    {
        return (_state == Process::SUCCEEDED || _state == Process::FAILED);
    }
    
    void Process::Pause()
    {
        _state = Process::READY;
    }
    
    void Process::Resume()
    {
        _state = Process::RUNNING;
    }
    
    void Process::Succeed()
    {
        _state = Process::SUCCEEDED;
    }
    
    void Process::Fail()
    {
        _state = Process::FAILED;
    }
    
    void Process::Terminate()
    {
        _state = Process::TERMINATED;
    }
    
    bool Process::IsDead()
    {
        return (_state == Process::SUCCEEDED || _state == Process::FAILED || _state == Process::TERMINATED);
    }
    
    Process::State Process::GetState()
    {
        return _state;
    }
    
    void Process::AddChild(ProcessPtr pChild)
    {
        _child = pChild;
    }
    
    ProcessPtr Process::RemoveChild()
    {
        if(_child)
        {
            ProcessPtr childPtr = _child;
            _child.reset();
            return childPtr;
        }
        
        return ProcessPtr();
    }

}