//
//  SpriteNodeFactory.h
//  FEngine
//
//  Created by Fakhir Shaheen on 21/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//


#pragma once

#include "../../PointerDefs.h"

#include "../../../3rdParty/tinyxml2-master/tinyxml2.h"

namespace FEngine
{
    class SpriteNodeFactory
    {
    public:
        SpriteNodeFactory();
        ~SpriteNodeFactory();
        
        SpriteNodePtr CreateSpriteNode(const tinyxml2::XMLElement * sceneNodeElement);
        
    };
}