//
//  TransformComponent.h
//  FEngine
//
//  Created by Fakhir Shaheen on 26/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "../ActorComponent.h"

namespace FEngine
{
    class TransformComponent : public ActorComponent
    {
    public:
        TransformComponent();
        virtual ~TransformComponent();
        
        virtual void Update(float dt);
        
        float x, y, angle;
        
    };
}