//
//  BasicShare.h
//  FEngine
//
//  Created by Fakhir Shaheen on 24/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include <string>

namespace FEngine
{
    class BasicShare
    {
    public:
        BasicShare(){}
        virtual ~BasicShare(){}
        
        virtual bool Share() = 0;
        
    };
}