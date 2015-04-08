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

#include <string>
#include <list>

namespace FEngine
{

    class PhysicsComponent : public ActorComponent
    {
        friend class PhysicsFactory;
        
    public:
        
        PhysicsComponent();
        virtual ~PhysicsComponent();
        
        virtual void    Update          (float dt);
        virtual void    Destroy         ();
        
        b2Body * const GetBody();
        
        BodyPropertiesPtr GetBodyProperties();
        
    private:
        
        // TODO:
        // Store a list of bodies and list of joints
        // OR maybe each body acts a single actor , wheels, car body are all separate actors
        // Need to decide that, for now, let's just keep it a SINGLE body per Actor.
        
        BodyPropertiesPtr _bodyProperties;
        
    };
}

