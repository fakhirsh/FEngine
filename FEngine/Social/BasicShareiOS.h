//
//  BasicShareiOS.h
//  FEngine
//
//  Created by Fakhir Shaheen on 24/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "BasicShare.h"

#include <string>

namespace FEngine
{
    class BasicShareiOS : public BasicShare
    {
    public:
        BasicShareiOS(){}
        virtual ~BasicShareiOS(){}
        
        virtual bool Share();
        
    };
}