//
//  Event.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 17/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "Event.h"

namespace FEngine
{
    Event::Event()
    {
    
    }
    
    Event::~Event()
    {
    
    }

    std::string Event::GetName()
    {
        return _name;
    }
    
}