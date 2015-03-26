//
//  ActorManager.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 26/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "ActorManager.h"

#include "Actor.h"

namespace FEngine
{
    
    ActorManager::ActorManager()
    {
    
    }
    
    ActorManager::~ActorManager()
    {
    
    }
        
    bool ActorManager::AddActor (ActorPtr actor)
    {
        if (_actorMap[actor->GetID()]) return false;
        
        _actorMap[actor->GetID()] = actor;
        
        return true;
    }
    
    bool ActorManager::RemoveActor (unsigned int actorID)
    {
        if (!_actorMap[actorID]) return false;
        
        _actorMap[actorID] = ActorPtr();
        
        return false;
    }
    
    ActorPtr ActorManager::GetActor (unsigned int actorID)
    {
        return _actorMap[actorID];
    }
        
    void ActorManager::Update (float dt)
    {
        std::map<unsigned int, ActorPtr>::iterator it = _actorMap.begin();
        
        while (it != _actorMap.end()) {
            
            (it->second)->Update(dt);
            
            it++;
        }
    }
        
}