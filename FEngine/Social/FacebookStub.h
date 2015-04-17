//
//  FacebookStub.h
//  FEngine
//
//  Created by Fakhir Shaheen on 17/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "Facebook.h"

#include <string>

namespace FEngine
{
    class FacebookStub : public Facebook
    {
    public:
        FacebookStub();
        virtual ~FacebookStub();
        
        virtual bool ShareURL(std::string contentURL, std::string imgURL, std::string title, std::string description);
        
    };
}