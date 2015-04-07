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
#include "SceneNodeProperties2D.h"


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
        
        child->SetParent(this);
        
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
    
    bool SceneNode2D::DestroySelf ()
    {
        if(_children.size() > 0)
        {
            _children.clear();
        }

        _parent = NULL;
        _sceneNodeProperties2D = SceneNodeProperties2DPtr();
        
        return true;
    }
    
    bool SceneNode2D::TearDown()
    {
        if(_children.size() > 0)
        {
            std::list<SceneNode2DPtr>::iterator it = _children.begin();
        
            while (it != _children.end()) {
                (*it)->TearDown();
            }
        }
        
        DestroySelf();
        
        return true;
    }
    
    void SceneNode2D::SetParent (SceneNode2D * parent)
    {
        _parent     =   parent;
    }
    
    const SceneNode2D * SceneNode2D::GetParent ()
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
    
    struct SortAScending
    {
        bool operator()(const SceneNode2DPtr & c1, const SceneNode2DPtr & c2) const
        {
            return c1->GetSceneNodeProperties()->zOrder < c2->GetSceneNodeProperties()->zOrder;
        }
    };
    
    bool SceneNode2D::RenderChildren (float dt)
    {
        if(_children.size() <= 0) return false;
        
        _children.sort(SortAScending());
        
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
    
    SceneNode2D * const SceneNode2D::FindNode (std::string nodeName)
    {
        if(_sceneNodeProperties2D->name == nodeName)
        {
            return this;
        }
        
        std::list<SceneNode2DPtr>::iterator it = _children.begin();
        while (it != _children.end())
        {
            SceneNode2D * p = (*it)->FindNode(nodeName);
            if(p) return p;
            
            it++;
        }
        
        return NULL;
    }
    
}