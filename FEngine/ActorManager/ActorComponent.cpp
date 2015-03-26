//
//  ActorComponent.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 26/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "ActorComponent.h"


namespace FEngine
{

    ActorComponent::ActorComponent()
    {
        _componentID = 0;
    }
    
    ActorComponent::~ActorComponent()
    {
    
    }
        
    unsigned int ActorComponent::GetID()
    {
        return _componentID;
    }

    ActorPtr ActorComponent::GetOwner()
    {
        return _owner;
    }
    
    void ActorComponent::SetOwner(ActorPtr owner)
    {
        _owner = owner;
    }

}