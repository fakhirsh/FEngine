//
//  DefaultProcesses.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 17/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "DefaultProcesses.h"

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
        
        if(_time >= 0.5)
        {
            std::cout << "Process Finished with ID: " << GetID() << std::endl;

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
    }
    
    
}