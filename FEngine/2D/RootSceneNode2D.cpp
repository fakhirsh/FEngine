//
//  RootSceneNode2D.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 20/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "RootSceneNode2D.h"


namespace FEngine
{
    RootSceneNode2D::RootSceneNode2D ()
    {
        
    }
    
    RootSceneNode2D::~RootSceneNode2D ()
    {
        
    }
    
    void RootSceneNode2D::Update (float dt)
    {
        _rootSceneNode2D->Update(dt);
    }
    
    bool RootSceneNode2D::PreRender (float dt)
    {
        _rootSceneNode2D->PreRender(dt);
        return true;
    }
    
    bool RootSceneNode2D::Render (float dt)
    {
        _rootSceneNode2D->Render(dt);
        return true;
    }
    
    bool RootSceneNode2D::RenderChildren (float dt)
    {
        _rootSceneNode2D->RenderChildren(dt);
        return true;
    }
    
    bool RootSceneNode2D::PostRender (float dt)
    {
        _rootSceneNode2D->PostRender(dt);
        return true;
    }
    
    void RootSceneNode2D::PushTransform (glm::mat4  transformMatrix)
    {
        _matrixStack.push(transformMatrix);
    }
    
    glm::mat4 RootSceneNode2D::PeekTransform ()
    {
        return _matrixStack.top();
    }
    
    void RootSceneNode2D::PopTransform ()
    {
        _matrixStack.pop();
    }
    
}