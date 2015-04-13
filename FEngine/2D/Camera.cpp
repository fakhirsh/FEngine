//
//  Camera.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 13/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "Camera.h"

#include "../Common.h"

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
    
    Camera::Camera()
    {
        _sceneNodeProperties2D = boost::make_shared<FEngine::SceneNodeProperties2D>();
    }
    
    Camera::~Camera()
    {
        
    }
    
    bool Camera::PreRender (float dt)
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
    
    bool Camera::Render (float dt)
    {
        return true;
    }
    
    
    
    bool Camera::PostRender (float dt)
    {
        StateManager::Get()->PopTransform2D();
        return true;
    }
    
}