//
//  ViewComponent.h
//  FEngine
//
//  Created by Fakhir Shaheen on 26/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "../ActorComponent.h"

namespace FEngine
{
    class ViewComponent : public ActorComponent
    {
        friend class ActorFactory;
        
    public:
        ViewComponent();
        ~ViewComponent();
        
        virtual void    Update(float dt);
        
        SceneNode2DPtr  GetSceneNode2D  ();
        
    private:
        
        SceneNode2DPtr  _sceneNode2D;
    };
}