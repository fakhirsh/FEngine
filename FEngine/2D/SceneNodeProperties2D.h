//
//  SceneNodeProperties.h
//  FEngine
//
//  Created by Fakhir Shaheen on 19/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once


#include <string>
#include "../../3rdParty/glm-0.9.6.3/glm/glm.hpp"

namespace FEngine
{
    class SceneNodeProperties2D
    {
    public:
        
        SceneNodeProperties2D();
        ~SceneNodeProperties2D();
        
        unsigned int    actorID;
        std::string     name;
        
        float           alpha;
        
        int             x;
        int             y;
        int             zOrder;
        
        float           angle;
        
        float           scaleX;
        float           scaleY;
        
        glm::vec3       tintColor;
        float           width;
        float           height;
        
        
        float           u, v, uW, vH;

    };
    
}

