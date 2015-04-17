//
//  Facebook.h
//  FEngine
//
//  Created by Fakhir Shaheen on 17/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include <string>

namespace FEngine
{
    class Facebook
    {
    public:
        Facebook(){}
        virtual ~Facebook(){}
        
        virtual bool ShareURL(std::string contentURL, std::string imgURL, std::string title, std::string description) = 0;
        
    };
}