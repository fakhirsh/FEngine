//
//  EventDispatcher.h
//  FEngine
//
//  Created by Fakhir Shaheen on 17/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "../PointerDefs.h"


#include <map>
#include <list>

namespace FEngine
{

    class EventDispatcher
    {
    private:
        static const int MAX_QUEUES = 2;
        
    public:
        EventDispatcher();
        ~EventDispatcher();
        
        bool AddListener    (unsigned int eID, EventListenerDelegate lfn);
        bool RemoveListener (unsigned int eID, EventListenerDelegate lfn);
        
        /*
         *...... WARNING WARNING WARNING .......
         * 
         * Dispatching an Event is VERY SLOW as compared to Triggering an Event.
         * Please fing the bottleneck and optimize.
         *
         */
        bool DispatchEvent  (EventPtr e);
        bool TriggerEvent   (EventPtr e);
        
        void Update         (float dt);
        
    private:
       
        std::list<EventPtr> _queues[MAX_QUEUES];
        int                 _activeQueue;
        
        // Hash table --> associates a list of delegates for each unique event type.
        std::map<unsigned int, std::list<EventListenerDelegate> > _listenerMap;
    };
    
}