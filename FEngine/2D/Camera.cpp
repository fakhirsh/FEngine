//
//  Camera.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 13/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "Camera.h"

#include "../Common.h"

#include "SceneNodeProperties2D.h"
#include "RootSceneNode2D.h"
#include "TextureAtlas.h"
#include "../Renderer/GLES20/Program.h"
#include "../Renderer/GLES20/SimpleVertex2DProgram.h"

#include "../PointerDefs.h"
#include "../System/App.h"
#include "../StateManager/StateManager.h"

#include "../Utility/Math.h"

#include <iostream>

extern FEngine::App * gApp;


namespace FEngine
{
    
    Camera::Camera()
    {
        _sceneNodeProperties2D = boost::make_shared<FEngine::SceneNodeProperties2D>();
    }
    
    Camera::~Camera()
    {
        
    }
    
    bool Camera::PreRender (float dt)
    {
        return true;
    }
    
    bool Camera::Render (float dt)
    {
        return true;
    }
    
    
    
    bool Camera::PostRender (float dt)
    {
        StateManager::Get()->PopTransform2D();
        return true;
    }
    
}