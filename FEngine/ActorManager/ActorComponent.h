//
//  ActorComponent.h
//  FEngine
//
//  Created by Fakhir Shaheen on 26/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "../PointerDefs.h"

namespace FEngine
{
    class ActorComponent
    {
    public:
        ActorComponent();
        virtual ~ActorComponent();
        
        virtual void Update(float dt) = 0;
        
        unsigned int GetID();
        
        ActorPtr    GetOwner();
        void        SetOwner(ActorPtr owner);
        
    protected:
        unsigned int _componentID;
        
        ActorPtr    _owner;
    };
}