//
//  SceneNode2D.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 20/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "SceneNode2D.h"

#include "../Common.h"
#include "../PointerDefs.h"


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
        
        child->SetParent(boost::shared_ptr<SceneNode2D>(this));
        
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
    
    void SceneNode2D::SetParent (SceneNode2DPtr parent)
    {
        _parent     =   parent;
    }
    
    SceneNode2DPtr SceneNode2D::GetParent ()
    {
        return _parent;
    }
    
/*
    void SceneNode2D::Update (float dt)
    {
        std::list<SceneNode2DPtr>::iterator it = _children.begin();
        
        while (it != _children.end())
        {
            SceneNode2DPtr child  =   *it;
            
            child->Update (dt);
            
            it++;
        }
    }
 */   
 
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
                child->Render (dt);
                child->RenderChildren (dt);
            }
            child->PostRender (dt);
            
            it++;
        }
        
        return true;
    }
    
    bool SceneNode2D::PostRender (float dt)
    {
        return true;
    }
    
    SceneNodeProperties2DPtr SceneNode2D::GetSceneNodeProperties ()
    {
        return _sceneNodeProperties2D;
    }
    
    void SceneNode2D::SetSceneNodeProperties(SceneNodeProperties2DPtr snp)
    {
        _sceneNodeProperties2D = snp;
    }
    
    unsigned int SceneNode2D::GetID()
    {
        return _nodeID;
    }
    
    void SceneNode2D::SetID(unsigned int nodeID)
    {
        _nodeID = nodeID;
    }

    /*
    SceneNode2DPtr SceneNode2D::FindNode (unsigned int nodeID)
    {
        SceneNode2DPtr current = boost::shared_ptr<SceneNode2D>(this);
        
        return FindChild(current, nodeID);
    }
    
    SceneNode2DPtr SceneNode2D::FindChild(SceneNode2DPtr node, unsigned int nodeID)
    {
        // Current node found. Just cast it properly and return...
        if(nodeID == _nodeID) return node;
        if(!node) return SceneNode2DPtr();
        
        std::list<SceneNode2DPtr>::iterator it = _children.begin();
        
        SceneNode2DPtr ptr;
        
        while (it != _children.end()) {
            ptr = FindChild(*it, nodeID);
            if(ptr) return ptr;
        
            it++;
        }
        
        return SceneNode2DPtr();
    }
     */
    
}