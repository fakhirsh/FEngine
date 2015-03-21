//
//  SpriteNode.h
//  FEngine
//
//  Created by Fakhir Shaheen on 20/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "SceneNode2D.h"
#include "../Renderer/VertexDefinitions.h"

#include <vector>

namespace FEngine
{
    class SpriteNode : public SceneNode2D
    {
    public:
        SpriteNode();
        ~SpriteNode();
        
        virtual bool        PreRender       (float dt = 0.0f);
        virtual bool        Render          (float dt = 0.0f);
        virtual bool        PostRender      (float dt = 0.0f);
        
    private:
        
        void                UpdateSpriteBatch();
        
        std::vector<Vertex2PF2UVF4CF>	_renderBatch;
    };
}