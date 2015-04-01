//
//  Actor.h
//  FEngine
//
//  Created by Fakhir Shaheen on 26/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "../PointerDefs.h"


namespace FEngine
{
    class Actor
    {
        friend class ActorFactory;
        
    public:
        Actor();
        ~Actor();
        
        unsigned long       GetID                       ();
        
        void                Update                      (float dt);
        
        ActorComponentPtr   GetViewComponent            ();
        ActorComponentPtr   GetPhysicsComponent         ();
        ActorComponentPtr   GetTransformComponent       ();
        ActorComponentPtr   GetInputComponent           ();
        ActorComponentPtr   GetAIComponent              ();
        ActorComponentPtr   GetAnimationComponent       ();
        
        SceneNode2DPtr      GetViewComponentSceneNode2D ();
        
        void                Destroy                     ();
        
    private:
        
        unsigned long       _actorID;
        
        ActorComponentPtr   _physicsComponent;
        ActorComponentPtr   _transformComponent;
        ActorComponentPtr   _viewComponent;
        ActorComponentPtr   _inputComponent;
        ActorComponentPtr   _aiComponent;
        ActorComponentPtr   _animationComponent;
    };
}