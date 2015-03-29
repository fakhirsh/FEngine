//
//  PhysicsFactory.h
//  FEngine
//
//  Created by Fakhir Shaheen on 28/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "../../PointerDefs.h"

//#include <Box2D/Box2D.h>
#include <string>

namespace FEngine
{
    class PhysicsFactory
    {
    public:
        PhysicsFactory();
        ~PhysicsFactory();
        
        // Creates a complete body along with a fixture attached to it !!!
        PhysicsComponentPtr CreatePhysicsComponent(std::string xmlFilePath);
        
    };
}