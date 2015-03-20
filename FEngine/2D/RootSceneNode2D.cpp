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
    
    bool RootSceneNode2D::Render (float dt)
    {
        
        this->RenderChildren(dt);
        
        return true;
    }
    
        
}