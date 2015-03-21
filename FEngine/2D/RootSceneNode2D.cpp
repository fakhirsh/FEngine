//
//  RootSceneNode2D.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 20/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "RootSceneNode2D.h"

#include "../Common.h"
#include "../Utility/Math.h"
#include "../2D/SceneNodeProperties2D.h"
#include "../StateManager/StateManager.h"

namespace FEngine
{
    RootSceneNode2D::RootSceneNode2D ()
    {
        _sceneNodeProperties2D          =   boost::make_shared<SceneNodeProperties2D>();
        _sceneNodeProperties2D->x       =   300;
        _sceneNodeProperties2D->y       =   0;
        _sceneNodeProperties2D->alpha   =   1.0f;
        _sceneNodeProperties2D->scaleX  =   1.0f;
        _sceneNodeProperties2D->scaleY  =   1.0f;
        _sceneNodeProperties2D->angle   =   Math::DegToRad(45.0f);
        
        glm::mat4 translate = glm::translate<GLfloat>(glm::mat4(1.0f),
                                                      glm::vec3(_sceneNodeProperties2D->x, _sceneNodeProperties2D->y, 0.0f));
        
        glm::mat4 rotate    = glm::rotate<GLfloat>(glm::mat4(1.0f),
                                                   _sceneNodeProperties2D->angle,
                                                   glm::vec3(0.0f, 0.0f, 1.0f));
        
        glm::mat4 scale     = glm::scale<GLfloat>(glm::mat4(1.0f),
                                                  glm::vec3(_sceneNodeProperties2D->scaleX, _sceneNodeProperties2D->scaleY, 1.0f));
        
        glm::mat4 mat = translate * rotate * scale;
        
        StateManager::Get()->PushTransform2D(mat);
        
    }
    
    RootSceneNode2D::~RootSceneNode2D ()
    {
        StateManager::Get()->PopTransform2D();
    }
    
    bool RootSceneNode2D::Render (float dt)
    {
        
        this->RenderChildren(dt);
        
        return true;
    }
    
        
}