//
//  Physics.h
//  FEngine
//
//  Created by Fakhir Shaheen on 28/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include <Box2D/Box2D.h>

#include "../PointerDefs.h"

#include <map>

namespace FEngine
{
    class PhysicsManager
    {
    public:
        static const float PTM_RATIO;
        
        PhysicsManager();
        ~PhysicsManager();
        
        static PhysicsManager * const   Get();
        bool                            Init();
        b2World * const                 GetWorld();
        
        void                            Update(float dt);
        
    private:
        static PhysicsManager *         _instance;
        b2World *                       _world;
    };
}