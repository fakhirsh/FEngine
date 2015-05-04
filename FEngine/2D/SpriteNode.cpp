//
//  SpriteNode.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 20/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "SpriteNode.h"

#include "../Common.h"

#include "../../3rdParty/glm-0.9.6.3/glm/gtx/transform2.hpp"

#include "SceneNodeProperties2D.h"
#include "RootSceneNode2D.h"
#include "TextureAtlas.h"
#include "../Renderer/GLES20/Program.h"
#include "../Renderer/GLES20/TexturedVertexProgram.h"

#include "../PointerDefs.h"
#include "../System/App.h"
#include "../StateManager/StateManager.h"

#include "../Utility/Math.h"

#include <iostream>


extern FEngine::App * gApp;


namespace FEngine
{
    
    SpriteNode::SpriteNode ()
    {
        _sceneNodeProperties2D = boost::make_shared<SceneNodeProperties2D>();
             
        // 6 vertices per Sprite
        for(int i = 0; i < 6; i++)
        {
            Vertex2PF2UVF4CF v;
            _renderBatch.push_back(v);
        }
    }
    
    SpriteNode::~SpriteNode ()
    {
        
    }
    
    bool SpriteNode::PreRender (float dt)
    {
        static float prevScaleX = 1.0f;
        static float prevScaleY = 1.0f;
        
        prevScaleX = _sceneNodeProperties2D->scaleX;
        prevScaleY = _sceneNodeProperties2D->scaleY;
        
        _sceneNodeProperties2D->scaleX = prevScaleX * gApp->GetContentScaleFactor();
        _sceneNodeProperties2D->scaleY = prevScaleY * gApp->GetContentScaleFactor();
        
        bool result = ViewNode::PreRender(dt);
        
        _sceneNodeProperties2D->scaleX = prevScaleX;
        _sceneNodeProperties2D->scaleY = prevScaleY;
        
        return result;
    }
    
    bool SpriteNode::Render (float dt)
    {
        _sceneNodeProperties2D->program->Bind();
        _sceneNodeProperties2D->textureAtlas->Bind();
        
        UpdateSpriteBatch();
        
        int m_ui32VertexStride = sizeof(Vertex2PF2UVF4CF);
        
        int textureID = _sceneNodeProperties2D->textureAtlas->GetTextureID();
        
        glBindTexture(GL_TEXTURE_2D, textureID);
        
        // Maybe use template functions to make it a bit generic? Saw that trick on GCC page 166.
        // Or maybe read in Game Engine Architecture on how to make a generic Render interface and mateirals etc.
        boost::shared_ptr <FEngine::TexturedVertexProgram> program = boost::static_pointer_cast<FEngine::TexturedVertexProgram>(_sceneNodeProperties2D->program);
        
        int posLoc      =   program->GetPositionAttribLocation();
        int uvLoc       =   program->GetUVAttribLocation();
        int colorLoc    =   program->GetColorAttribLocation();
        // Set PVM mastrix:
        program->SetMatrix(gApp->GetViewportWidth(), gApp->GetViewportHeight());
        
        // Enable the user-defined vertex array
        glEnableVertexAttribArray(posLoc);
        glEnableVertexAttribArray(uvLoc);
        glEnableVertexAttribArray(colorLoc);
        
        glVertexAttribPointer(posLoc, 2, GL_FLOAT, GL_FALSE, m_ui32VertexStride, (const GLvoid *)&_renderBatch[0].x);
        glVertexAttribPointer(uvLoc, 2, GL_FLOAT, GL_FALSE, m_ui32VertexStride,(const GLvoid *)&_renderBatch[0].u);
        glVertexAttribPointer(colorLoc, 4, GL_FLOAT, GL_FALSE, m_ui32VertexStride,(const GLvoid *)&_renderBatch[0].r);
        
        const int VERTS_PER_SPRITE = 6;
        glDrawArrays(GL_TRIANGLES, 0, 1 * VERTS_PER_SPRITE);
        
        glDisableVertexAttribArray(colorLoc);
        glDisableVertexAttribArray(uvLoc);
        glDisableVertexAttribArray(posLoc);

        return true;
    }
    
    bool SpriteNode::PostRender (float dt)
    {
        return ViewNode::PostRender(dt);
        
        return true;
    }
    
    void SpriteNode::UpdateSpriteBatch()
    {
        
        glm::mat4 mat = StateManager::Get()->PeekTransform2D();
        
        float W, H, u, v, uW, vH, angle, scaleX, scaleY, alpha, shearX, shearY;
        W       = _sceneNodeProperties2D->width;
        H       = _sceneNodeProperties2D->height;
        u       = _sceneNodeProperties2D->u;
        v       = _sceneNodeProperties2D->v;
        uW      = _sceneNodeProperties2D->uW;
        vH      = _sceneNodeProperties2D->vH;
        //angle   = _sceneNodeProperties2D->angle;
        //scaleX  = _sceneNodeProperties2D->scaleX;
        //scaleY  = _sceneNodeProperties2D->scaleX;
        alpha   = _sceneNodeProperties2D->alpha;
        //shearX  = _sceneNodeProperties2D->shearX;
        //shearY  = _sceneNodeProperties2D->shearY;
        shearX  = 0.0f;
        shearY  = 0.0f;
        

        int i = 0;
        const int VERTS_PER_SPRITE = 6;
        //glm::vec4 vec = translate * rotate * scale * glm::vec4(-W / 2.0f, -H / 2.0f, 0.0f, 1.0f);
        glm::vec4 vec = mat * glm::vec4(-W / 2.0f, -H / 2.0f, 0.0f, 1.0f);
        _renderBatch[i * VERTS_PER_SPRITE].x	=	vec.x;
        _renderBatch[i * VERTS_PER_SPRITE].y	=	vec.y;
        _renderBatch[i * VERTS_PER_SPRITE].u	=	u;
        _renderBatch[i * VERTS_PER_SPRITE].v	=	vH;
        _renderBatch[i * VERTS_PER_SPRITE].r	=	_sceneNodeProperties2D->tintColor.r;
        _renderBatch[i * VERTS_PER_SPRITE].g	=	_sceneNodeProperties2D->tintColor.g;
        _renderBatch[i * VERTS_PER_SPRITE].b	=	_sceneNodeProperties2D->tintColor.b;
        _renderBatch[i * VERTS_PER_SPRITE].a	=	alpha;
        
        
        vec = mat * glm::vec4(W / 2.0f, -H / 2.0f, 0.0f, 1.0f);
        _renderBatch[i * VERTS_PER_SPRITE + 1].x	=	vec.x;
        _renderBatch[i * VERTS_PER_SPRITE + 1].y	=	vec.y;
        _renderBatch[i * VERTS_PER_SPRITE + 1].u	=	uW;
        _renderBatch[i * VERTS_PER_SPRITE + 1].v	=	vH;
        _renderBatch[i * VERTS_PER_SPRITE + 1].r	=	_sceneNodeProperties2D->tintColor.r;
        _renderBatch[i * VERTS_PER_SPRITE + 1].g	=	_sceneNodeProperties2D->tintColor.g;
        _renderBatch[i * VERTS_PER_SPRITE + 1].b	=	_sceneNodeProperties2D->tintColor.b;
        _renderBatch[i * VERTS_PER_SPRITE + 1].a	=	alpha;
        
        vec = mat * glm::vec4(W / 2.0f + shearX, H / 2.0f + shearY, 0.0f, 1.0f);
        _renderBatch[i * VERTS_PER_SPRITE + 2].x	=	vec.x;
        _renderBatch[i * VERTS_PER_SPRITE + 2].y	=	vec.y;
        _renderBatch[i * VERTS_PER_SPRITE + 2].u	=	uW;
        _renderBatch[i * VERTS_PER_SPRITE + 2].v	=	v;
        _renderBatch[i * VERTS_PER_SPRITE + 2].r	=	_sceneNodeProperties2D->tintColor.r;
        _renderBatch[i * VERTS_PER_SPRITE + 2].g	=	_sceneNodeProperties2D->tintColor.g;
        _renderBatch[i * VERTS_PER_SPRITE + 2].b	=	_sceneNodeProperties2D->tintColor.b;
        _renderBatch[i * VERTS_PER_SPRITE + 2].a	=	alpha;
        
        vec = mat * glm::vec4(-W / 2.0f, -H / 2.0f, 0.0f, 1.0f);
        _renderBatch[i * VERTS_PER_SPRITE + 3].x	=	vec.x;
        _renderBatch[i * VERTS_PER_SPRITE + 3].y	=	vec.y;
        _renderBatch[i * VERTS_PER_SPRITE + 3].u	=	u;
        _renderBatch[i * VERTS_PER_SPRITE + 3].v	=	vH;
        _renderBatch[i * VERTS_PER_SPRITE + 3].r	=	_sceneNodeProperties2D->tintColor.r;
        _renderBatch[i * VERTS_PER_SPRITE + 3].g	=	_sceneNodeProperties2D->tintColor.g;
        _renderBatch[i * VERTS_PER_SPRITE + 3].b	=	_sceneNodeProperties2D->tintColor.b;
        _renderBatch[i * VERTS_PER_SPRITE + 3].a	=	alpha;
        
        vec = mat * glm::vec4(W / 2.0f + shearX, H / 2.0f + shearY, 0.0f, 1.0f);
        _renderBatch[i * VERTS_PER_SPRITE + 4].x	=	vec.x;
        _renderBatch[i * VERTS_PER_SPRITE + 4].y	=	vec.y;
        _renderBatch[i * VERTS_PER_SPRITE + 4].u	=	uW;
        _renderBatch[i * VERTS_PER_SPRITE + 4].v	=	v;
        _renderBatch[i * VERTS_PER_SPRITE + 4].r	=	_sceneNodeProperties2D->tintColor.r;
        _renderBatch[i * VERTS_PER_SPRITE + 4].g	=	_sceneNodeProperties2D->tintColor.g;
        _renderBatch[i * VERTS_PER_SPRITE + 4].b	=	_sceneNodeProperties2D->tintColor.b;
        _renderBatch[i * VERTS_PER_SPRITE + 4].a	=	alpha;
        
        vec = mat * glm::vec4(-W / 2.0f + shearX, H / 2.0f + shearY, 0.0f, 1.0f);
        _renderBatch[i * VERTS_PER_SPRITE + 5].x	=	vec.x;
        _renderBatch[i * VERTS_PER_SPRITE + 5].y	=	vec.y;
        _renderBatch[i * VERTS_PER_SPRITE + 5].u	=	u;
        _renderBatch[i * VERTS_PER_SPRITE + 5].v	=	v;
        _renderBatch[i * VERTS_PER_SPRITE + 5].r	=	_sceneNodeProperties2D->tintColor.r;
        _renderBatch[i * VERTS_PER_SPRITE + 5].g	=	_sceneNodeProperties2D->tintColor.g;
        _renderBatch[i * VERTS_PER_SPRITE + 5].b	=	_sceneNodeProperties2D->tintColor.b;
        _renderBatch[i * VERTS_PER_SPRITE + 5].a	=	alpha;
        
    }

    
}

