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
#include "../StateManager/StateManager.h"
#include "../Utility/Math.h"
#include "../System/App.h"


using namespace FEngine;
using namespace std;

extern FEngine::App * gApp;

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
 
    bool SceneNode2D::IsVisible ()
    {
        
        // Math::BBox bBox = GetBBox();
        
        /*
        struct RECT_LOCAL
        {
            float X1, Y1, X2, Y2;
        };
        
        RECT_LOCAL RectA, RectB, AABB;
        
        glm::mat4 mat = StateManager::Get()->PeekTransform2D();
        
        glm::vec4 p;
        float W = _sceneNodeProperties2D->width;
        float H = _sceneNodeProperties2D->height;
         
         //??????? What is going on ???
         
        p = mat * glm::vec4(-W / 2.0f, -H / 2.0f, 0.0f, 1.0f);
        RectA.X1 = p.x;
        RectA.Y1 = p.y;
        p = mat * glm::vec4(W / 2.0f, H / 2.0f, 0.0f, 1.0f);
        RectA.X2 = p.x;
        RectA.Y2 = p.y;
        
         //??????
         
        RectB.X1 = 0.0f;
        RectB.Y1 = 0.0f;
        RectB.X2 = gApp->GetFrameBufferWidth();
        RectB.Y2 = gApp->GetFrameBufferHeight();
        
        if (RectA.X1 < RectB.X2 && RectA.X2 > RectB.X1 &&
            RectA.Y1 < RectB.Y2 && RectA.Y2 > RectB.Y1)
        {
            return true;
        }
        */
        
        return true;
    }
    
    /*
    Math::BBox SceneNode2D::GetBBox ()
    {
        if (_children.size() > 0)
        {
            std::list<SceneNode2DPtr>::iterator it = _children.begin();

            Math::BBox bBox;
            
            while (it != _children.end())
            {
                Math::BBox childBBox = (*it)->GetBBox();
                
                bBox.l = bBox.r = childBBox.l;
                bBox.b = bBox.t = childBBox.r;
                
                bBox.l = Math::Min(bBox.l, childBBox.l);
                bBox.r = Math::Max(bBox.r, childBBox.r);
                bBox.b = Math::Min(bBox.b, childBBox.b);
                bBox.t = Math::Max(bBox.t, childBBox.t);
                
                it++;
            }
            
            return bBox;
        }
        else
        {
            glm::mat4 mat = StateManager::Get()->PeekTransform2D();
            Math::BBox bBox;
            glm::vec4 points[4];
            
            float W = _sceneNodeProperties2D->width;
            float H = _sceneNodeProperties2D->height;
            
            points[0] = mat * glm::vec4(-W / 2.0f, -H / 2.0f, 0.0f, 1.0f);  // Bottom left
            points[1] = mat * glm::vec4(W / 2.0f, -H / 2.0f, 0.0f, 1.0f);   // Bottom Right
            points[2] = mat * glm::vec4(W / 2.0f, H / 2.0f, 0.0f, 1.0f);    // Upper Right
            points[3] = mat * glm::vec4(-W / 2.0f, H / 2.0f, 0.0f, 1.0f);   // Upper Left
            
            bBox.l = bBox.r = points[0].x;
            bBox.b = bBox.t = points[0].y;
            
            bBox.l = Math::Min(bBox.l, points[0].x);  bBox.r = Math::Max(bBox.r, points[0].x);
            bBox.l = Math::Min(bBox.l, points[1].x);  bBox.r = Math::Max(bBox.r, points[1].x);
            bBox.l = Math::Min(bBox.l, points[2].x);  bBox.r = Math::Max(bBox.r, points[2].x);
            bBox.l = Math::Min(bBox.l, points[3].x);  bBox.r = Math::Max(bBox.r, points[3].x);
            
            bBox.b = Math::Min(bBox.b, points[0].y);  bBox.t = Math::Max(bBox.t, points[0].y);
            bBox.b = Math::Min(bBox.b, points[1].y);  bBox.t = Math::Max(bBox.t, points[1].y);
            bBox.b = Math::Min(bBox.b, points[2].y);  bBox.t = Math::Max(bBox.t, points[2].y);
            bBox.b = Math::Min(bBox.b, points[3].y);  bBox.t = Math::Max(bBox.t, points[3].y);

            return bBox;
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
                if(child->IsVisible())
                {
                    child->Render (dt);
                    child->RenderChildren (dt);
                }
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