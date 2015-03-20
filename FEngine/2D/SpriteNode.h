//
//  SpriteNode.h
//  FEngine
//
//  Created by Fakhir Shaheen on 20/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "SceneNode2D.h"

namespace FEngine
{
    class SpriteNode : public SceneNode2D
    {
    public:
        SpriteNode();
        ~SpriteNode();
        
        virtual bool        Render          (float dt = 0.0f);
        
    private:

    };
}