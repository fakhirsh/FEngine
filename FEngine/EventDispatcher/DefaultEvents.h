//
//  DefaultEvents.h
//  FEngine
//
//  Created by Fakhir Shaheen on 17/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "Event.h"

namespace FEngine
{
    class EventTest1 : public Event
    {
    public:
        EventTest1(){
            _name = "EventTest1";
        }
        virtual ~EventTest1(){}
    
        virtual const unsigned int  GetID() { return eventID; };
        static const unsigned int   eventID;
        
        int someData;
        int someMoreData;
        
    private:
        
    };
}