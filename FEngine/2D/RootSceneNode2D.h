//
//  RootSceneNode2D.h
//  FEngine
//
//  Created by Fakhir Shaheen on 20/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//


#pragma once

#include "../Common.h"
#include "../PointerDefs.h"

#include "SceneNode2D.h"
#include "SceneNodeProperties2D.h"


namespace FEngine
{
    class RootSceneNode2D : public SceneNode2D
    {
    public:
        RootSceneNode2D();
        virtual ~RootSceneNode2D();
        
        virtual void        Update          (float dt);
        
        virtual bool        PreRender       (float dt = 0.0f);
        virtual bool        Render          (float dt = 0.0f);
        virtual bool        RenderChildren  (float dt = 0.0f);
        virtual bool        PostRender      (float dt = 0.0f);
        
        void                PushTransform   (glm::mat4  transformMatrix);
        glm::mat4           PeekTransform   ();
        void                PopTransform    ();
        
    private:
        
        std::stack<glm::mat4>       _matrixStack;
        
        SceneNode2DPtr              _rootSceneNode2D;
        
        SceneNodeProperties2DPtr    _sceneNodeProperties2D;
        
    };
}