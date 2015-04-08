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
#include <string>
#include <list>

namespace FEngine
{
    
    class FixtureProperties
    {
    public:
        FixtureProperties(){fixture=NULL;}
        // The view accociated to this fixture {an arm, leg or head etc}
        // NOTE: This MUST be a part of some other View
        //       (atleast in the view XML file in case the view is not already initialized yet).
        std::string     viewName;
        
        b2Fixture *     fixture;
        SceneNode2DPtr  viewNode;
        SceneNode2DPtr  debugNode;
    };
    
    class BodyProperties
    {
    public:
        BodyProperties(){body=NULL;}
        std::string     name;
        b2Body *        body;
        std::list<FixturePropertiesPtr> fixtureList;
    };

    
    class PhysicsManager
    {
    public:
        static const float PTM_RATIO;
        
        PhysicsManager();
        ~PhysicsManager();
        
        bool                            Init();
        b2World * const                 GetWorld();
        
        void                            Update(float dt);
        
    private:

        b2World *                       _world;
    };
}