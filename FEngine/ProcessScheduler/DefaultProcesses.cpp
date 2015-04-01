//
//  DefaultProcesses.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 17/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "DefaultProcesses.h"

#include "../EventDispatcher/DefaultEvents.h"
#include "../EventDispatcher/EventDispatcher.h"
#include "../StateManager/StateManager.h"

#include <iostream>

namespace FEngine
{
    ProcessDelay::ProcessDelay()
    {
        _pID = 1;
        _time = 0;
    }
    
    ProcessDelay::~ProcessDelay()
    {
    
    }
    
    void ProcessDelay::Update(float dt)
    {
        _time += dt;
        
        if(_time >= 6.0)
        {
            std::cout << "Process Finished with ID: " << GetID() << " after " << _time << " seconds..." << std::endl;
            
            EventDispatcherPtr ed = StateManager::Get()->GetEventDispatcher();
            boost::shared_ptr<EventTest1> e = boost::make_shared<EventTest1>();
            e->someData = GetID();
            e->someMoreData = _time;
            
            ed->DispatchEvent(e);
            
            Succeed();
        }
    }
    
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    ProcessPrint::ProcessPrint()
    {
        
    }
    
    ProcessPrint::~ProcessPrint()
    {
        
    }
    
    void ProcessPrint::Update(float dt)
    {
        std::cout << "Printing a message..." << std::endl;
        
        Succeed();
    }
    
    
}