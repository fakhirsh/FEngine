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

#include "../../2D/SceneNode2D.h"
#include "../../2D/SceneNodeProperties2D.h"

#include "../../PhysicsManager/PhysicsManager.h"
#include "../../ActorManager/Components/ViewComponent.h"

#include "../../StateManager/StateManager.h"

#include <iostream>


namespace FEngine
{
    
    PhysicsComponent::PhysicsComponent()
    {
        _bodyProperties = boost::make_shared<FEngine::BodyProperties>();
    }
    
    PhysicsComponent::~PhysicsComponent()
    {
        Destroy();
    }
    
    void PhysicsComponent::Destroy ()
    {
        if(!_bodyProperties->body) return;
        
        /*
        SceneNode2D * ptr = (SceneNode2D * )_bodyProperties.body->GetUserData();
        if(ptr)
        {
            SceneNode2DPtr sPtr;
            sPtr.reset(ptr);
            SceneNode2DPtr dRoot = StateManager::Get()->GetDebugNode2D();
            dRoot->RemoveChild(sPtr);
        }
        */
        
        StateManager::Get()->GetPhysicsManager()->GetWorld()->DestroyBody(_bodyProperties->body);
        _bodyProperties->body = NULL;
    }
        
    void PhysicsComponent::Update(float dt)
    {
        
        // Instead of followng, PLEASE use an Event such as : EventUpdateTransform(ActorID, x, y, angle)...
        
        TransformComponentPtr tcPtr = boost::static_pointer_cast<TransformComponent>(_owner->GetTransformComponent());
        
        tcPtr->x = _bodyProperties->body->GetPosition().x * PhysicsManager::PTM_RATIO;
        tcPtr->y = _bodyProperties->body->GetPosition().y * PhysicsManager::PTM_RATIO;
        tcPtr->angle = Math::RadToDeg(_bodyProperties->body->GetAngle());
        
    }
    
    b2Body * const PhysicsComponent::GetBody()
    {
        return _bodyProperties->body;
    }
    
    BodyPropertiesPtr PhysicsComponent::GetBodyProperties()
    {
        return _bodyProperties;
    }
    
    
}