//
//  SceneNodeProperties.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 19/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "SceneNodeProperties2D.h"


namespace FEngine
{
    
    SceneNodeProperties2D::SceneNodeProperties2D()
    {
        actorID     =   0;
        
        alpha       =   0.0f;
        
        x           =   0.0f;
        y           =   0.0f;

        angle       =   0.0f;
        
        scaleX      =   1.0f;
        scaleY      =   1.0f;
        
        width       =   0.0f;
        height      =   0.0f;
        
        zOrder      =   -1;
        
        u           =   0.0f;
        v           =   0.0f;
        uW          =   0.0f;
        vH          =   0.0f;
        
        tintColor.r =   1.0f;
        tintColor.g =   1.0f;
        tintColor.b =   1.0f;

    }
    
    SceneNodeProperties2D::~SceneNodeProperties2D()
    {
    
    }
    
}