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
        
        for(; i != _processList.end(); ){
            // Get current process in process list
            if(*i){

                ProcessPtr      p       =   *i;
                
                // Save the iterator and increment the old one in case if the process has to be removed.
                std::list<ProcessPtr>::iterator tempIt = i;
                ++i;
                
                if(p->GetState() == Process::State::CREATED)
                {
                    p->Resume();
                }
                
                if(p->GetState() == Process::State::RUNNING)
                {
                    p->Update(dt);
                }
                
                if(p->GetState() == Process::State::READY)
                {
                    p->Pause();
                }
                
                if(p->GetState() == Process::State::SUCCEEDED)
                {
                    ProcessPtr child = p->RemoveChild();
                    if(child)
                    {
                        _processList.push_back(child);
                    }
                    p->Terminate();
                }

                if(p->GetState() == Process::State::FAILED)
                {
                    p->Terminate();
                }
                            
                if(p->GetState() == Process::State::TERMINATED)
                {
                    _processList.erase(tempIt);
                }
            }
            
        }
        
    }
    
    void ProcessScheduler::RemoveAll()
    {
        _processList.clear();
    }
    
}