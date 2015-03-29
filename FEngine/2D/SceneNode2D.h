//
//  SceneNode2D.h
//  FEngine
//
//  Created by Fakhir Shaheen on 20/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once


#include <list>

#include "../PointerDefs.h"


namespace FEngine
{
    class SceneNode2D
    {
    public:
        SceneNode2D();
        virtual ~SceneNode2D();
        
        bool                AddChild        (SceneNode2DPtr child);
        bool                RemoveChild     (SceneNode2DPtr child);
        
        // Finds the node amongst children
        //SceneNode2DPtr      FindNode        (unsigned int nodeID);
        
        void                SetParent       (SceneNode2DPtr parent);
        SceneNode2DPtr      GetParent       ();
        
        //virtual void        Update          (float dt);
        
        virtual bool        PreRender       (float dt = 0.0f);
        virtual bool        Render          (float dt = 0.0f)   =   0;
        virtual bool        RenderChildren  (float dt = 0.0f);
        virtual bool        PostRender      (float dt = 0.0f);
        
        SceneNodeProperties2DPtr GetSceneNodeProperties ();
        void                SetSceneNodeProperties(SceneNodeProperties2DPtr snp);
        
        unsigned int GetID();
        void SetID(unsigned int nodeID);
        
        std::list<SceneNode2DPtr> GetChildrenList(){return _children;}
        
    protected:
        
        //SceneNode2DPtr FindChild(SceneNode2DPtr node, unsigned int nodeID);
        
        std::list<SceneNode2DPtr>           _children;
        
        SceneNode2DPtr                      _parent;
        
        SceneNodeProperties2DPtr            _sceneNodeProperties2D;

        unsigned int _nodeID;
        
    };
    
}