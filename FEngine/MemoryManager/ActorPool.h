//
//  ActorPool.h
//  FEngine
//
//  Created by Fakhir Shaheen on 31/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "../PointerDefs.h"
#include <vector>

namespace FEngine
{
    class ActorPool
    {
    public:
        ActorPool();
        ~ActorPool();
        
        void        AddToPool       (ActorPtr actor);
        void        RemoveFromPool  (ActorPtr actor);
        
        ActorPtr    NEW             ();
        void        DELETE          (ActorPtr actor);
        
        int         GetPoolSize     ();
        int         GetFreeCount    ();
        int         GetUsedCount    ();
        
        void        Clear           ();
        
    private:
        
        struct ActorNode
        {
            ActorPtr    actor;
            bool        isFree;
        };
        
        std::vector<ActorNode>  _actorPool;
        
        int                     _currentlyUsedActors;
        
    };
}
