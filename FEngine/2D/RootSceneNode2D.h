//
//  RootSceneNode2D.h
//  FEngine
//
//  Created by Fakhir Shaheen on 20/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//


#pragma once

#include "SceneNode2D.h"

namespace FEngine
{
    class RootSceneNode2D : public SceneNode2D
    {
    public:
        RootSceneNode2D();
        ~RootSceneNode2D();
        
        virtual bool        PreRender       (float dt = 0.0f);
        virtual bool        Render          (float dt = 0.0f);
        virtual bool        PostRender      (float dt = 0.0f);
        
        SceneNode2DPtr      FindNode        (unsigned int nodeID);
        
    private:

    };
}