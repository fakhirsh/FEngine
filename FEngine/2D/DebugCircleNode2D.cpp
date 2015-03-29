//
//  DebugCircleNode2D.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 28/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "DebugCircleNode2D.h"


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
    const int TOTAL_TRIANGLES = 20;
    
    DebugCircleNode2D::DebugCircleNode2D()
    {
        _sceneNodeProperties2D = boost::make_shared<FEngine::SceneNodeProperties2D>();
        
        // 6 vertices per Sprite
        for(int i = 0; i < TOTAL_TRIANGLES * 3 ; i++)
        {
            Vertex2PF v;
            _renderBatch.push_back(v);
        }
        
    }
    
    DebugCircleNode2D::~DebugCircleNode2D()
    {
        
    }
    
    bool DebugCircleNode2D::PreRender (float dt)
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
    
    bool DebugCircleNode2D::Render (float dt)
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
        
        glDrawArrays(GL_TRIANGLES, 0, 3 * TOTAL_TRIANGLES);
        
        glDisableVertexAttribArray(posLoc);
        
        
        return true;
    }
    
    
    bool DebugCircleNode2D::PostRender (float dt)
    {
        StateManager::Get()->PopTransform2D();
        return true;
    }
    
    
    void DebugCircleNode2D::UpdateSpriteBatch()
    {
        
        glm::mat4 mat = StateManager::Get()->PeekTransform2D();
        
        float W, H;
        W       = _sceneNodeProperties2D->width;
        H       = _sceneNodeProperties2D->height;
        
        glm::vec4 vec = mat * glm::vec4(-W / 2.0f, -H / 2.0f, 0.0f, 1.0f);
        
        float theta = 0;
        float DELTA = Math::DegToRad(360.0) / TOTAL_TRIANGLES;
        for(int i = 0; i < TOTAL_TRIANGLES*3; i+=3)
        {
            
            glm::vec4 p = mat * glm::vec4(0.0f, 0.0f, 0.0f, 1.0f);
            _renderBatch[i + 0].x = p.x;
            _renderBatch[i + 0].y = p.y;
            
            p = mat * glm::vec4(W * cosf(theta), W * sinf(theta), 0.0f, 1.0f);
            _renderBatch[i + 1].x = p.x;
            _renderBatch[i + 1].y = p.y;
            
            p = mat * glm::vec4(W * cosf(theta + DELTA), W * sinf(theta + DELTA), 0.0f, 1.0f);
            _renderBatch[i + 2].x = p.x;
            _renderBatch[i + 2].y = p.y;

            theta += DELTA;
        }
        
    }
    
    
}

