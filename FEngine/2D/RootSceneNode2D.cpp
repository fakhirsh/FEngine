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
#include "../2D/SceneNode2D.h"
#include "../2D/RootSceneNode2D.h"
#include "../2D/SceneNodeProperties2D.h"
#include "../StateManager/StateManager.h"

#include "../System/App.h"

extern FEngine::App * gApp;

namespace FEngine
{
    RootSceneNode2D::RootSceneNode2D ()
    {
        std::cout << "RootSceneNode2D::RootSceneNode2D" << std::endl;
        
        _sceneNodeProperties2D          =   boost::make_shared<SceneNodeProperties2D>();
        _sceneNodeProperties2D->x       =   0.0f;
        _sceneNodeProperties2D->y       =   0.0f;
        _sceneNodeProperties2D->alpha   =   1.0f;
        _sceneNodeProperties2D->scaleX  =   1.0f;
        _sceneNodeProperties2D->scaleY  =   1.0f;
        
        _sceneNodeProperties2D->angle   =   Math::DegToRad(0.0f);
        
    }
    
    RootSceneNode2D::~RootSceneNode2D ()
    {
        std::cout << "RootSceneNode2D::~RootSceneNode2D" << std::endl;
        
        //TearDown();
        
    }
    
    bool RootSceneNode2D::PreRender(float dt)
    {
        glm::mat4 translate = glm::translate<GLfloat>(glm::mat4(1.0f),
                                                      glm::vec3(_sceneNodeProperties2D->x, _sceneNodeProperties2D->y, 0.0f));
        
        glm::mat4 rotate    = glm::rotate<GLfloat>(glm::mat4(1.0f),
                                                   _sceneNodeProperties2D->angle,
                                                   glm::vec3(0.0f, 0.0f, 1.0f));
        
        glm::mat4 scale     = glm::scale<GLfloat>(glm::mat4(1.0f),
                                                  glm::vec3(_sceneNodeProperties2D->scaleX, _sceneNodeProperties2D->scaleY, 1.0f));
        
        glm::mat4 mat = translate * rotate * scale;
        
        StateManager::Get()->PushTransform2D(mat);

        return true;
    }
    
    bool RootSceneNode2D::Render (float dt)
    {
        this->PreRender();
        this->RenderChildren(dt);
        this->PostRender();
        
        return true;
    }
    
    bool RootSceneNode2D::PostRender(float dt)
    {
        StateManager::Get()->PopTransform2D();
        
        return true;
    }
    
    SceneNode2DPtr FindNodeInScene (SceneNode2DPtr currentNode, unsigned int nodeID)
    {
        if(!currentNode)
        {
            return SceneNode2DPtr();
        }
        if (currentNode->GetID() == nodeID) {
            return currentNode;
        }
        
        std::list<SceneNode2DPtr>::iterator it = currentNode->GetChildrenList().begin();
        
        while (it != currentNode->GetChildrenList().end()) {
            
            SceneNode2DPtr p = FindNodeInScene((*it), nodeID);
            if(p) return p;
            
            it++;
        }
        
        return SceneNode2DPtr();
    }
    
    SceneNode2DPtr RootSceneNode2D::FindNode (unsigned int nodeID)
    {
        std::list<SceneNode2DPtr>::iterator it = _children.begin();
        
        while (it != _children.end()) {
            
            SceneNode2DPtr p = FindNodeInScene((*it), nodeID);
            if(p) return p;
            
            it++;
        }
        
        return SceneNode2DPtr();
    }
    

}