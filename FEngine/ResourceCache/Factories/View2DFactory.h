//
//  View2DFactory.h
//  FEngine
//
//  Created by Fakhir Shaheen on 25/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "../../PointerDefs.h"

#include "../../../3rdParty/tinyxml2-master/tinyxml2.h"

namespace FEngine
{
    class View2DFactory
    {
    public:
        View2DFactory();
        ~View2DFactory();
        
        SceneNode2DPtr CreateView(const tinyxml2::XMLElement * sceneNodeElement);

    private:
        SceneNode2DPtr CreateViewNode(const tinyxml2::XMLElement * sceneNodeElement);
        
    };
}