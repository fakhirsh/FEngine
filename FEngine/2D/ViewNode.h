//
//  ViewNode.h
//  FEngine
//
//  Created by Fakhir Shaheen on 07/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "SceneNode2D.h"


#include <vector>

namespace FEngine
{
    /**
     *   Acts as an empty container for view elements
     */
    class ViewNode : public SceneNode2D
    {
    public:
        ViewNode();
        ~ViewNode();
        
        virtual bool        PreRender       (float dt = 0.0f);
        virtual bool        Render          (float dt = 0.0f);
        virtual bool        PostRender      (float dt = 0.0f);
        
    private:

    };
}