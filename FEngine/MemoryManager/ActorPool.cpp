//
//  ActorPool.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 31/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "ActorPool.h"

#include "../EventDispatcher/DefaultEvents.h"
#include "../EventDispatcher/EventDispatcher.h"
#include "../StateManager/StateManager.h"

namespace FEngine
{
    
    ActorPool::ActorPool()
    {
        _currentlyUsedActors = 0;
    }
    
    ActorPool::~ActorPool()
    {
        Clear();
    }
        
    void ActorPool::AddToPool (ActorPtr actor)
    {
        ActorNode n;
        n.actor     =   actor;
        n.isFree    =   true;
        _actorPool.push_back(n);
        
        // Reposition Actor, waaayyyy out of the visible area....
        EventDispatcherPtr ed = StateManager::Get()->GetEventDispatcher();
        boost::shared_ptr<EventSetActorPosition> e2 = boost::make_shared<EventSetActorPosition>();
        e2->actor    =   n.actor;
        e2->x =   0 + rand() / float(RAND_MAX) * 100.0f;
        e2->y =   -1800 - rand() / float(RAND_MAX) * 100.0f ;
        ed->DispatchEvent(e2);
        
    }
    
    void ActorPool::RemoveFromPool (ActorPtr actor)
    {
        std::vector<ActorNode>::iterator it = _actorPool.begin();
        
        while(it != _actorPool.end())
        {
            if((*it).actor == actor)
            {
                _actorPool.erase(it);
                return;
            }
            
            it++;
        }
    }
    
    void ActorPool::Clear ()
    {
        _actorPool.clear();
    }
        
    ActorPtr ActorPool::NEW ()
    {
        std::vector<ActorNode>::iterator it = _actorPool.begin();
        
        while(it != _actorPool.end())
        {
            if((*it).isFree)
            {
                _currentlyUsedActors++;
                
                (*it).isFree = false;
                return (*it).actor;
            }
            
            it++;
        }
        
        return ActorPtr();
    }
    
    void ActorPool::DELETE (ActorPtr actor)
    {
        std::vector<ActorNode>::iterator it = _actorPool.begin();
        
        while(it != _actorPool.end())
        {
            if((*it).actor == actor)
            {
                _currentlyUsedActors--;
                
                (*it).isFree = true;
                
                // Reposition Actor, waaayyyy out of the visible area....
                EventDispatcherPtr ed = StateManager::Get()->GetEventDispatcher();
                boost::shared_ptr<EventSetActorPosition> e2 = boost::make_shared<EventSetActorPosition>();
                e2->actor    =   (*it).actor;
                e2->x =   0 + rand() / float(RAND_MAX) * 100.0f;
                e2->y =   -1800 - rand() / float(RAND_MAX) * 100.0f ;
                ed->DispatchEvent(e2);
                
                return;
            }
            
            it++;
        }
    }
        
    int ActorPool::GetPoolSize ()
    {
        return _actorPool.size();
    }
    
    int ActorPool::GetFreeCount ()
    {
        return GetPoolSize() - GetUsedCount();
    }
    
    int ActorPool::GetUsedCount ()
    {
        return _currentlyUsedActors;
    }
        
}
