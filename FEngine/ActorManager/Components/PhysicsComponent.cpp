//
//  PhysicsComponent.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 26/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "PhysicsComponent.h"
#include "../../ActorManager/Actor.h"
#include "TransformComponent.h"
#include "../../Utility/Math.h"

#include <iostream>

namespace FEngine
{

    float VEL = 100.0f;
    
    PhysicsComponent::PhysicsComponent()
    {
    
    }
    
    PhysicsComponent::~PhysicsComponent()
    {
    
    }
        
    void PhysicsComponent::Update(float dt)
    {
        TransformComponentPtr tPtr = boost::static_pointer_cast<TransformComponent>(_owner->GetTransformComponent());
        
        tPtr->x += VEL*dt;
        tPtr->y += VEL*dt;
        //tPtr->angle = 60;
        
        ///std::cout << tPtr->x << "  " << tPtr->y << std::endl;
    }
    
}