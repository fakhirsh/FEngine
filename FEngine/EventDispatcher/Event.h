//
//  Event.h
//  FEngine
//
//  Created by Fakhir Shaheen on 17/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once


/**
 *  Idea inspired by Game Coding Complete 4.
 *	There are many sites that generate UUIDs. Following are to name a few:
 *	http://www.uuidgenerator.net/
 *	http://www.guidgenerator.com/online-guid-generator.aspx
 *	http://www.famkruithof.net/uuid/uuidgen
 */


#include <string>

namespace FEngine
{
    
    class Event
    {
    public:
        Event();
        virtual ~Event();
        
        std::string GetName();
        
        virtual const unsigned int GetID() = 0;
        
    protected:
        std::string _name;
    };
    
}