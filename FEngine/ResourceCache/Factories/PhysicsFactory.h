//
//  PhysicsFactory.h
//  FEngine
//
//  Created by Fakhir Shaheen on 28/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "../../PointerDefs.h"

#include <Box2D/Box2D.h>
#include <string>

#include "../../../3rdParty/tinyxml2-master/tinyxml2.h"

namespace FEngine
{
    class PhysicsFactory
    {
    public:
        PhysicsFactory();
        ~PhysicsFactory();
        
        // Creates a complete body along with a fixture attached to it !!!
        PhysicsComponentPtr CreatePhysicsComponent(std::string xmlFilePath);
    
    private:
        // A struct to gather all data. This will be used to create the body in a single pass.
        struct PhysicsShape
        {
            PhysicsShape();
            ~PhysicsShape();
    
            boost::shared_ptr<b2Shape> fixtureShape;
            b2FixtureDef fixtureDef;
            std::string shapeType;
            
            SceneNode2DPtr debugNode;
        };

        PhysicsShape CreateShape(const tinyxml2::XMLElement * physicsElement);
        void CreateBox(const tinyxml2::XMLElement * physicsElement, PhysicsShape & fixture);
        void CreateCircle(const tinyxml2::XMLElement * physicsElement, PhysicsShape & fixture);
        
    };
}