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
        
        SceneNode2DPtr CreateSpriteNode(const tinyxml2::XMLElement * sceneNodeElement);
        
    private:
        SceneNode2DPtr CreateView(const tinyxml2::XMLElement * viewElement);
        
    };
}