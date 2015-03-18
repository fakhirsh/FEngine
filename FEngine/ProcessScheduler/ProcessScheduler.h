//
//  ProcessScheduler.h
//  FEngine
//
//  Created by Fakhir Shaheen on 17/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include <list>

#include "../PointerDefs.h"

namespace FEngine
{
    /*!
     *      A very basic cooprative multitasking process schedular
     */
    class ProcessScheduler
    {
    public:
        ProcessScheduler();
        ~ProcessScheduler();
        
        bool AddChild(ProcessPtr process);
        bool RemoveChild(ProcessPtr process);

        void Update(float dt);
        
        void RemoveAll();
        
    private:
        
        std::list<ProcessPtr> _processList;
        
    };
}