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
#include "SceneNodeProperties2D.h"

namespace FEngine
{
    class SceneNode2D
    {
    public:
        SceneNode2D();
        virtual ~SceneNode2D();
        
        bool                AddChild        (SceneNode2DPtr child);
        bool                RemoveChild     (SceneNode2DPtr child);
        
        void                SetParent       (SceneNode2DWeakPtr parent);
        SceneNode2DWeakPtr  GetParent       ();
        
        unsigned long       GetActorID      ();
        void                SetActorID      (unsigned int actorID);
        
        virtual void        Update          (float dt);
        
        virtual bool        PreRender       (float dt = 0.0f);
        virtual bool        Render          (float dt = 0.0f)   =   0;
        virtual bool        RenderChildren  (float dt = 0.0f);
        virtual bool        PostRender      (float dt = 0.0f);
        
        SceneNodeProperties2DPtr GetSceneNodeProperties ();
        void                SetSceneNodeProperties(SceneNodeProperties2DPtr snp);
        
        //virtual void        Destroy         ();
        
    protected:
        std::list<SceneNode2DPtr>           _children;
        
        SceneNode2DWeakPtr                  _parent;
        
        SceneNodeProperties2DPtr            _sceneNodeProperties2D;

        
    };
    
}