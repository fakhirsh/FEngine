//
//  ActorManager.h
//  FEngine
//
//  Created by Fakhir Shaheen on 26/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include <map>

#include "../PointerDefs.h"

namespace FEngine
{
    class ActorManager
    {
    public:
        ActorManager();
        ~ActorManager();
        
        bool        AddActor    (ActorPtr actor);
        bool        RemoveActor (unsigned int actorID);
        ActorPtr    GetActor    (unsigned int actorID);
        
        void Update(float dt);
        
    private:
        
        std::map<unsigned int, ActorPtr> _actorMap;
        
    };
}