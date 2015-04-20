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
        
        
        /**
         *   Usage example:
         *      std::string shareURL    =   "http://www.facebook.com/delagames";
         *      std::string imgURL      =   "http://fakhir.heliohost.org/images/logo_large.png";
         *      std::string title       =   "Check out Cool new Zombie game!";
         *      std::string description =   "OMG I just ate 32232 candies! Can you beat it?";
         *      ShareURL(shareURL, imgURL, title, description);
         */
        virtual bool ShareURL(std::string contentURL, std::string imgURL, std::string title, std::string description) = 0;
        
    };
}