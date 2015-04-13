//
//  EventDispatcher.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 17/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "EventDispatcher.h"
#include "Event.h"

#include "../System/App.h"
#include "../Debugging/Log.h"

using namespace FEngine;
extern App * gApp;

namespace FEngine
{
    EventDispatcher::EventDispatcher()
    {
        gApp->GetLog()->Print("EventDispatcher::EventDispatcher()");
        _activeQueue = 0;
    }
    
    EventDispatcher::~EventDispatcher()
    {
        gApp->GetLog()->Print("EventDispatcher::~EventDispatcher()");
        RemoveAllEvents();
        RemoveAllListeners();
    }
    
    bool EventDispatcher::AddListener(unsigned int eID, EventListenerDelegate lfn)
    {
        
        std::list<EventListenerDelegate>::iterator i = _listenerMap[eID].begin();
        
        while(i != _listenerMap[eID].end())
        {
            if(*i == lfn)
            {
                return false;
            }
            
            i++;
        }
        
        _listenerMap[eID].push_back(lfn);
        
        return true;
    }
    
    bool EventDispatcher::RemoveListener(unsigned int eID, EventListenerDelegate lfn)
    {
        
        std::list<EventListenerDelegate>::iterator i = _listenerMap[eID].begin();
        
        // Iterate through all of the list elements
        while(i != _listenerMap[eID].end())
        {
            // If listener function is found then delete it!
            if(*i == lfn)
            {
                _listenerMap[eID].erase(i);
                
                return true;
            }
            
            i++;
        }
        
        return false;

    }
    
    bool EventDispatcher::DispatchEvent(EventPtr e)
    {
        _queues[_activeQueue].push_back(e);
        
        return true;
    }
    
    bool EventDispatcher::TriggerEvent(EventPtr e)
    {
        unsigned int eID = e->GetID();
        
        std::list<EventListenerDelegate>::iterator it = _listenerMap[eID].begin();
        
        // Iterate through all of the list elements
        while(it != _listenerMap[eID].end())
        {
            (*it)(e);
            
            it++;
        }
        
        return true;

    }
    
    void EventDispatcher::Update(float dt)
    {
        
        int currentQueue    =   _activeQueue;
        _activeQueue        =   (_activeQueue + 1) % MAX_QUEUES;
        
        std::list<EventPtr>::iterator queueIT = _queues[currentQueue].begin();
        
        while(queueIT != _queues[currentQueue].end())
        {
            EventPtr e = *queueIT;
            
            std::list<EventListenerDelegate>::iterator listenerIT = _listenerMap[e->GetID()].begin();
            
            while (listenerIT != _listenerMap[e->GetID()].end()) {
                
                // For each event, execute its listener
                (*listenerIT)(e);
                
                listenerIT++;
            }
            
            queueIT++;
            
        }
        
        _queues[currentQueue].clear();
        
    }

    bool EventDispatcher::RemoveAllListeners()
    {
        _listenerMap.clear();
        
        return true;
    }
    
    bool EventDispatcher::RemoveAllEvents()
    {
        for(int i = 0; i < MAX_QUEUES; i++)
        {
            _queues[i].clear();
        }
        return true;
    }
    
}