//
//  ViewNode.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 07/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "ViewNode.h"

#include "../Common.h"
#include "../PointerDefs.h"
#include "../System/App.h"
#include "../StateManager/StateManager.h"
#include "SceneNodeProperties2D.h"
#include "RootSceneNode2D.h"

#include "../Utility/Math.h"

extern FEngine::App * gApp;


namespace FEngine
{
    
    ViewNode::ViewNode ()
    {
        _sceneNodeProperties2D = boost::make_shared<SceneNodeProperties2D>();
    }
    
    ViewNode::~ViewNode ()
    {
        
    }
    
    bool ViewNode::PreRender (float dt)
    {
        float CSF = gApp->GetContentScaleFactor();
        
        //RootSceneNode * root = (RootSceneNode *)StateManager::Get()->GetRootSceneNode();
        //SceneNodeProperties snpStack = root->snpStack.back();
        //glm::mat4 matStack = root->transformationStack.back();
        
        glm::mat4 mat = StateManager::Get()->PeekTransform2D();
        
        glm::vec2 oldP(_sceneNodeProperties2D->x, _sceneNodeProperties2D->y);
        Math::Point2D p        =   gApp->DesignToSafeZone(Math::Point2D(oldP.x, oldP.y));
        
        glm::mat4 translate = glm::translate<GLfloat>(glm::mat4(1.0f), glm::vec3(p.x, p.y, 0.0f));
        
        glm::mat4 rotate    = glm::rotate   <GLfloat>(glm::mat4(1.0f),
                                                      Math::DegToRad(_sceneNodeProperties2D->angle),
                                                      glm::vec3(0.0f, 0.0f, 1.0f));
        
        glm::mat4 scale     = glm::scale    <GLfloat>(glm::mat4(1.0f), glm::vec3(_sceneNodeProperties2D->scaleX,
                                                                                 _sceneNodeProperties2D->scaleY,
                                                                                 1.0f));
        
        glm::mat4 translateAnchor = glm::translate<GLfloat>(glm::mat4(1.0f), glm::vec3(_sceneNodeProperties2D->anchor.x,
                                                                                       _sceneNodeProperties2D->anchor.y,
                                                                                       0.0f));
        
        glm::mat4 shearX    = glm::mat4(1.0f);
        shearX[1][0] = _sceneNodeProperties2D->shearX;
        
        
        glm::mat4 localMat = translate * rotate * scale * shearX * translateAnchor;
        
        StateManager::Get()->PushTransform2D(mat * localMat);
        
        //root->transformationStack.push_back(matStack * localMat);
        
        /*
         SceneNodeProperties snp;
         snp.name = _sceneNodeProp.name;
         snp.x = _sceneNodeProp.x + snpStack.x;
         snp.y = _sceneNodeProp.y + snpStack.y;
         snp.alpha = _sceneNodeProp.alpha * snpStack.alpha;
         snp.angle = _sceneNodeProp.angle + snpStack.angle;
         snp.scaleX = _sceneNodeProp.scaleX;
         snp.scaleY = _sceneNodeProp.scaleY;
         
         root->snpStack.push_back(snp);
         */
        
        return true;
    }
    
    bool ViewNode::Render (float dt)
    {
        return true;
    }
    
    bool ViewNode::PostRender (float dt)
    {
        StateManager::Get()->PopTransform2D();
        
        return true;
    }
    
}