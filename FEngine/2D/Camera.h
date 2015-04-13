//
//  Camera.h
//  FEngine
//
//  Created by Fakhir Shaheen on 13/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "SceneNode2D.h"


namespace FEngine
{
    class Camera : public SceneNode2D
    {
    public:
        Camera();
        ~Camera();
        
        virtual bool        PreRender       (float dt = 0.0f);
        virtual bool        Render          (float dt = 0.0f);
        virtual bool        PostRender      (float dt = 0.0f);
        
    };
}