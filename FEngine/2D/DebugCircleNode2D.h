//
//  DebugCircleNode2D.h
//  FEngine
//
//  Created by Fakhir Shaheen on 28/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "SceneNode2D.h"
#include "../Renderer/VertexDefinitions.h"

#include <vector>
#include <string>

namespace FEngine
{
    class DebugCircleNode2D : public SceneNode2D
    {
    public:
        DebugCircleNode2D();
        ~DebugCircleNode2D();
        
        virtual bool        PreRender       (float dt = 0.0f);
        virtual bool        Render          (float dt = 0.0f);
        virtual bool        PostRender      (float dt = 0.0f);
        
        //float radius;
        
    private:
        void RenderCircle(float radius);
        void RenderBox(float x, float y, float width, float height);
        
        void                UpdateSpriteBatch();
        
        std::vector<Vertex2PF>	_renderBatch;
    };
}