//
//  DefaultEvents.h
//  FEngine
//
//  Created by Fakhir Shaheen on 17/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "Event.h"
#include "../PointerDefs.h"

namespace FEngine
{
    
    //----------------------------------------------------------------------------------------------------
    // EventTouchDown - sent when the player first touches on the screen
    ///----------------------------------------------------------------------------------------------------
    class EventTouchDown : public Event
    {
    public:
        static const unsigned long eventID;
        virtual const unsigned long GetID() const { return eventID; }
        
        EventTouchDown(){}
        ~EventTouchDown(){}
        
        std::string GetName()
        {
            return "Touch Down";
        }
        
        //private:
        int x, y;
    };
    
    
    
    //----------------------------------------------------------------------------------------------------
    // EventTouchMoved - sent when the player drags his finger on the screen
    //----------------------------------------------------------------------------------------------------
    class EventTouchMoved : public Event
    {
    public:
        static const unsigned long eventID;
        virtual const unsigned long GetID() const { return eventID; }
        
        EventTouchMoved(){}
        ~EventTouchMoved(){}
        
        std::string GetName()
        {
            return "Touch Moved";
        }
        
        //private:
        int x, y;
    };
    
    //----------------------------------------------------------------------------------------------------
    // EventTouchUp - sent when the player lifts his finger from the screen
    //----------------------------------------------------------------------------------------------------
    class EventTouchUp : public Event
    {
    public:
        static const unsigned long eventID;
        virtual const unsigned long GetID() const { return eventID; }
        
        EventTouchUp(){}
        ~EventTouchUp(){}
        
        std::string GetName()
        {
            return "Touch Up";
        }
        
        //private:
        int x, y;
    };

    //----------------------------------------------------------------------------------------------------
    // EventSetDebugNode - Sets up debug node while initializing the Physics component
    //----------------------------------------------------------------------------------------------------
    class EventSetDebugNode : public Event
    {
    public:
        static const unsigned long eventID;
        virtual const unsigned long GetID() const { return eventID; }
        
        EventSetDebugNode(){}
        ~EventSetDebugNode(){}
        
        std::string GetName()
        {
            return "Touch Up";
        }
        
        SceneNode2DPtr _debugNode;
    };

    
    //----------------------------------------------------------------------------------------------------
    // 
    //----------------------------------------------------------------------------------------------------
    
    
    
    
    
    class EventTest1 : public Event
    {
    public:
        EventTest1(){
            _name = "EventTest1";
        }
        virtual ~EventTest1(){}
    
        virtual const unsigned long GetID() const { return eventID; };
        static const unsigned long  eventID;
        
        int someData;
        int someMoreData;
        
    private:
        
    };
    
    
    
    
    
    
}