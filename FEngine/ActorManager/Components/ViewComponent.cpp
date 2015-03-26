//
//  ViewComponent.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 26/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "ViewComponent.h"
#include "TransformComponent.h"
#include "../../ActorManager/Actor.h"

#include "../../2D/SceneNode2D.h"
#include "../../2D/SceneNodeProperties2D.h"


namespace FEngine
{
    
    ViewComponent::ViewComponent ()
    {
    
    }
    
    ViewComponent::~ViewComponent ()
    {
    
    }
        
    void ViewComponent::Update (float dt)
    {
        TransformComponentPtr tPtr = boost::static_pointer_cast<TransformComponent>(_owner->GetTransformComponent());
        
        _sceneNode2D->GetSceneNodeProperties()->x = tPtr->x;
        _sceneNode2D->GetSceneNodeProperties()->y = tPtr->y;
        _sceneNode2D->GetSceneNodeProperties()->angle = tPtr->angle;
    }
        
    SceneNode2DPtr ViewComponent::GetSceneNode2D ()
    {
        return _sceneNode2D;
    }
    
    void ViewComponent::SetSceneNode2D (SceneNode2DPtr nodePtr)
    {
        _sceneNode2D = nodePtr;
    }

}