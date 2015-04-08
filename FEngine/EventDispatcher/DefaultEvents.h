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
        static const unsigned int eventID;
        virtual const unsigned int GetID() const { return eventID; }
        
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
        static const unsigned int eventID;
        virtual const unsigned int GetID() const { return eventID; }
        
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
        static const unsigned int eventID;
        virtual const unsigned int GetID() const { return eventID; }
        
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
        static const unsigned int eventID;
        virtual const unsigned int GetID() const { return eventID; }
        
        EventSetDebugNode(){}
        ~EventSetDebugNode(){}
        
        std::string GetName()
        {
            return "SetDebugNode";
        }
        
        SceneNode2DPtr _debugNode;
    };

    //----------------------------------------------------------------------------------------------------
    // EventSetActorPosition - Sets up debug node while initializing the Physics component
    //----------------------------------------------------------------------------------------------------
    class EventSetActorPosition : public Event
    {
    public:
        static const unsigned int eventID;
        virtual const unsigned int GetID() const { return eventID; }
        
        EventSetActorPosition(){}
        ~EventSetActorPosition(){}
        
        std::string GetName()
        {
            return "Set Actor Position";
        }
        
        ActorPtr actor;
        
        float x, y;
    };

    
    
    /*----------------------------------------------------------------------------------------------------
     *----------------------------------------------------------------------------------------------------
     *----------------------------------------------------------------------------------------------------
     *             Gameplay Related events...
     *----------------------------------------------------------------------------------------------------
     *----------------------------------------------------------------------------------------------------
     *----------------------------------------------------------------------------------------------------*/
    
    //----------------------------------------------------------------------------------------------------
    // EventCandyConsumed - Fires whenever the player eats a candy
    //----------------------------------------------------------------------------------------------------
    class EventCandyConsumed : public Event
    {
    public:
        static const unsigned int eventID;
        virtual const unsigned int GetID() const { return eventID; }
        
        EventCandyConsumed(){}
        ~EventCandyConsumed(){}
        
        ActorPtr candyActor;
        
        std::string GetName()
        {
            return "Candy Consumed";
        }
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
    
        virtual const unsigned int GetID() const { return eventID; };
        static const unsigned int  eventID;
        
        int someData;
        int someMoreData;
        
    private:
        
    };
    
    
    
    
    
    
}