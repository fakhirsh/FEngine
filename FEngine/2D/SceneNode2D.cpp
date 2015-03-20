//
//  SceneNode2D.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 20/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "SceneNode2D.h"


namespace FEngine
{
    
    SceneNode2D::SceneNode2D ()
    {
        
    }
    
    SceneNode2D::~SceneNode2D ()
    {
        
    }
    
    bool SceneNode2D::AddChild (SceneNode2DPtr child)
    {
        _children.push_back(child);
        
        return true;
    }
    
    bool SceneNode2D::RemoveChild (SceneNode2DPtr child)
    {
        
        std::list<SceneNode2DPtr>::iterator it = _children.begin();
        
        while (it != _children.end())
        {
            if(child == *it)
            {
                _children.erase(it);
                return true;
            }
            
            it++;
        }
        
        return false;
    }
    
    void SceneNode2D::SetParent (SceneNode2DWeakPtr parent)
    {
        _parent     =   parent;
    }
    
    SceneNode2DWeakPtr SceneNode2D::GetParent ()
    {
        return _parent;
    }
    
    void SceneNode2D::Update (float dt)
    {
        std::list<SceneNode2DPtr>::iterator it = _children.begin();
        
        while (it != _children.end())
        {
            SceneNode2DPtr child  =   *it;
            
            child->Update           (dt);
            
            it++;
        }
    }
    
    bool SceneNode2D::PreRender (float dt)
    {
        return true;
    }
    
    bool SceneNode2D::RenderChildren (float dt)
    {
        if(_children.size() <= 0) return false;
        
        std::list<SceneNode2DPtr>::iterator it = _children.begin();
        
        while (it != _children.end())
        {
            SceneNode2DPtr child  =   *it;
            
            if(child->PreRender (dt))
            {
                child->Render           (dt);
                child->RenderChildren   (dt);
            }
            child->PostRender   (dt);
            
            it++;
        }
        
        return true;
    }
    
    bool SceneNode2D::PostRender (float dt)
    {
        return true;
    }
    
}