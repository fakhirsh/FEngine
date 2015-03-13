//
//  SmartPtr.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 14/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "SmartPtr.h"

#include <iostream>

namespace FEngine
{
    SmartPtr::SmartPtr()
    {
        
    }
    
    SmartPtr::~SmartPtr()
    {
        
    }
    
    void SmartPtr::Print()
    {
        std::cout << "SmartPtr says hello!!!" << std::endl;
    }
}

