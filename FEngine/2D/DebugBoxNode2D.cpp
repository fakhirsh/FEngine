//
//  DebugBoxNode2D.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 28/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "DebugBoxNode2D.h"


#include "Common.h"

#include "SceneNodeProperties2D.h"
#include "RootSceneNode2D.h"
#include "TextureAtlas.h"
#include "../Renderer/GLES20/Program.h"
#include "../Renderer/GLES20/SimpleVertex2DProgram.h"

#include "../PointerDefs.h"
#include "../System/App.h"
#include "../StateManager/StateManager.h"

#include "../Utility/Math.h"

#include <iostream>


extern FEngine::App * gApp;


namespace FEngine
{
    
    DebugBoxNode2D::DebugBoxNode2D()
    {
        _sceneNodeProperties2D = boost::make_shared<FEngine::SceneNodeProperties2D>();
        
        // 6 vertices per Sprite
        for(int i = 0; i < 6; i++)
        {
            Vertex2PF v;
            _renderBatch.push_back(v);
        }
        
    }
    
    DebugBoxNode2D::~DebugBoxNode2D()
    {
        
    }
    
    bool DebugBoxNode2D::PreRender (float dt)
    {
        float CSF = gApp->GetContentScaleFactor();
        
        //RootSceneNode * root = (RootSceneNode *)StateManager::Get()->GetRootSceneNode();
        //SceneNodeProperties snpStack = root->snpStack.back();
        //glm::mat4 matStack = root->transformationStack.back();
        
        glm::mat4 mat = StateManager::Get()->PeekTransform2D();
        
        glm::vec2 oldP(_sceneNodeProperties2D->x, _sceneNodeProperties2D->y);
        glm::vec2 newP;
        Math::Point2D p;
        p.x     =   oldP.x;
        p.y     =   oldP.y;
        p       =   gApp->DesignSpaceToSafeZone(p);
        newP.x  =   p.x;
        newP.y  =   p.y;
        
        glm::mat4 translate = glm::translate<GLfloat>(glm::mat4(1.0f), glm::vec3(newP.x, newP.y, 0.0f));
        
        glm::mat4 rotate    = glm::rotate   <GLfloat>(glm::mat4(1.0f),
                                                      Math::DegToRad(_sceneNodeProperties2D->angle),
                                                      glm::vec3(0.0f, 0.0f, 1.0f));
        
        glm::mat4 scale     = glm::scale    <GLfloat>(glm::mat4(1.0f), glm::vec3(_sceneNodeProperties2D->scaleX * CSF,
                                                                                 _sceneNodeProperties2D->scaleY * CSF,
                                                                                 1.0f));
        
        glm::mat4 localMat = translate * rotate * scale;
        
        StateManager::Get()->PushTransform2D(mat * localMat);
        return true;
    }
    
    bool DebugBoxNode2D::Render (float dt)
    {
        _sceneNodeProperties2D->program->Bind();
        
        UpdateSpriteBatch();
        
        int m_ui32VertexStride = 0;
        
        // Maybe use template functions to make it a bit generic? Saw that trick on GCC page 166.
        // Or maybe read in Game Engine Architecture on how to make a generic Render interface and mateirals etc.
        boost::shared_ptr <FEngine::SimpleVertex2DProgram> program = boost::static_pointer_cast<FEngine::SimpleVertex2DProgram>(_sceneNodeProperties2D->program);
        
        int posLoc      =   program->GetPositionAttribLocation();
        
        // Set PVM mastrix:
        program->SetMatrix(gApp->GetViewportWidth(), gApp->GetViewportHeight());
        
        program->SetColor(0.0f, 1.0f, 0.0f, _sceneNodeProperties2D->alpha);
        
        // Enable the user-defined vertex array
        glEnableVertexAttribArray(posLoc);
        
        glVertexAttribPointer(posLoc, 2, GL_FLOAT, GL_FALSE, m_ui32VertexStride, (const GLvoid *)&_renderBatch[0].x);
        
        const int VERTS_PER_SPRITE = 6;
        glDrawArrays(GL_TRIANGLES, 0, 1 * VERTS_PER_SPRITE);
        
        glDisableVertexAttribArray(posLoc);
        
        
        return true;
    }
    
    
    
    bool DebugBoxNode2D::PostRender (float dt)
    {
        StateManager::Get()->PopTransform2D();
        return true;
    }
    
    
    void DebugBoxNode2D::UpdateSpriteBatch()
    {
        
        glm::mat4 mat = StateManager::Get()->PeekTransform2D();
        
        float W, H;
        W       = _sceneNodeProperties2D->width;
        H       = _sceneNodeProperties2D->height;
        
        int i = 0;
        const int VERTS_PER_SPRITE = 6;
        
        glm::vec4 vec = mat * glm::vec4(-W / 2.0f, -H / 2.0f, 0.0f, 1.0f);
        _renderBatch[i * VERTS_PER_SPRITE].x	=	vec.x;
        _renderBatch[i * VERTS_PER_SPRITE].y	=	vec.y;
        
        vec = mat * glm::vec4(W / 2.0f, -H / 2.0f, 0.0f, 1.0f);
        _renderBatch[i * VERTS_PER_SPRITE + 1].x	=	vec.x;
        _renderBatch[i * VERTS_PER_SPRITE + 1].y	=	vec.y;
        
        vec = mat * glm::vec4(W / 2.0f, H / 2.0f, 0.0f, 1.0f);
        _renderBatch[i * VERTS_PER_SPRITE + 2].x	=	vec.x;
        _renderBatch[i * VERTS_PER_SPRITE + 2].y	=	vec.y;
        
        vec = mat * glm::vec4(-W / 2.0f, -H / 2.0f, 0.0f, 1.0f);
        _renderBatch[i * VERTS_PER_SPRITE + 3].x	=	vec.x;
        _renderBatch[i * VERTS_PER_SPRITE + 3].y	=	vec.y;
        
        vec = mat * glm::vec4(W / 2.0f, H / 2.0f, 0.0f, 1.0f);
        _renderBatch[i * VERTS_PER_SPRITE + 4].x	=	vec.x;
        _renderBatch[i * VERTS_PER_SPRITE + 4].y	=	vec.y;
        
        vec = mat * glm::vec4(-W / 2.0f, H / 2.0f, 0.0f, 1.0f);
        _renderBatch[i * VERTS_PER_SPRITE + 5].x	=	vec.x;
        _renderBatch[i * VERTS_PER_SPRITE + 5].y	=	vec.y;
        
    }
    
    
}