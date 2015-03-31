//
//  Actor.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 26/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "Actor.h"
#include "Components/PhysicsComponent.h"
#include "Components/TransformComponent.h"
#include "Components/ViewComponent.h"

namespace FEngine
{

    Actor::Actor()
    {
        _actorID = 0;
    }
    
    Actor::~Actor()
    {
        float g = 0;
    }
        
    unsigned long Actor::GetID()
    {
        return _actorID;
    }

    void Actor::Update(float dt)
    {
        if(_physicsComponent)   _physicsComponent->Update(dt);
        if(_viewComponent)      _viewComponent->Update(dt);
    }
 
    ActorComponentPtr Actor::GetViewComponent()
    {
        return _viewComponent;
    }
    
    ActorComponentPtr Actor::GetPhysicsComponent()
    {
        return _physicsComponent;
    }
    
    ActorComponentPtr Actor::GetTransformComponent()
    {
        return _transformComponent;
    }

    ActorComponentPtr Actor::GetInputComponent ()
    {
        return _inputComponent;
    }
    
    SceneNode2DPtr Actor::GetViewComponentSceneNode2D()
    {
        ViewComponentPtr vPtr = boost::static_pointer_cast<ViewComponent>(_viewComponent);
        
        return vPtr->GetSceneNode2D();
    }
    
    void Actor::Destroy()
    {
        if(_physicsComponent)
            _physicsComponent->Destroy();
        if(_viewComponent)
            _viewComponent->Destroy();
        
        _physicsComponent = ActorComponentPtr();
        _viewComponent = ActorComponentPtr();
    }
}