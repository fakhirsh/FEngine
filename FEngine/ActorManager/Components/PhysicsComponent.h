//
//  PhysicsComponent.h
//  FEngine
//
//  Created by Fakhir Shaheen on 26/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include <Box2D/Box2D.h>

#include "../ActorComponent.h"


namespace FEngine
{

    class PhysicsComponent : public ActorComponent
    {
        friend class PhysicsFactory;
        
    public:
        PhysicsComponent();
        ~PhysicsComponent();
        
        virtual void    Update          (float dt);
        
        b2Body * const GetBody();
        
    private:
        
        b2Body * _body;
    };
}