//
//  ProcessScheduler.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 17/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "ProcessScheduler.h"

#include "../Common.h"
#include "Process.h"


namespace FEngine
{
    ProcessScheduler::ProcessScheduler()
    {
    
    }
    
    ProcessScheduler::~ProcessScheduler()
    {
    
    }
    
    bool ProcessScheduler::AddChild(ProcessPtr process)
    {
        _processList.push_back(process);
        
        return true;
    }
    
    bool ProcessScheduler::RemoveChild(ProcessPtr process)
    {
        std::list<ProcessPtr>::iterator i = _processList.begin();
        while (i != _processList.end())
        {
            if(*i == process)
            {
                _processList.erase(i);
                return true;
            }
            i++;
        }
        
        return false;
    }
    
    void ProcessScheduler::Update(float dt)
    {
        std::list<ProcessPtr>::iterator i = _processList.begin();
        
        for(; i != _processList.end(); )
        {
            // Get current process in process list
            ProcessPtr p = *i;
            
            Process::State state = p->GetState();
            
            switch (state)
            {
                case Process::State::CREATED :
                {
                    p->Resume();
                }
                break;
                    
                case Process::State::RUNNING :
                {
                    p->Update(dt);
                }
                break;
                
                case Process::State::SUCCEEDED :
                {
                    ProcessPtr child = p->RemoveChild();
                    if(child)
                    {
                        _processList.push_back(child);
                    }
                    p->Terminate();
                }
                break;
                
                case Process::State::FAILED :
                {
                    p->Terminate();
                }
                break;
                    
                case Process::State::TERMINATED :
                {
                    _processList.erase(i);
                }
                break;
                    
                    
                default:
                    break;
            }
            
            // Incrementing the iterator outside for loop so that it
            //    properly updates BEFORE checking the terminating condition...
            i++;
            
        }
        
    }
    
    void ProcessScheduler::RemoveAll()
    {
        _processList.clear();
    }
    
}