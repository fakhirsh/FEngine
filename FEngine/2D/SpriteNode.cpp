//
//  SpriteNode.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 20/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "SpriteNode.h"
#include "SceneNodeProperties2D.h"
#include "../PointerDefs.h"

#include <iostream>

namespace FEngine
{
    
    SpriteNode::SpriteNode ()
    {
        _sceneNodeProperties2D = boost::make_shared<FEngine::SceneNodeProperties2D>();
    }
    
    SpriteNode::~SpriteNode ()
    {
        
    }
    
    bool SpriteNode::Render (float dt)
    {
        
        return true;
    }
    
    
}