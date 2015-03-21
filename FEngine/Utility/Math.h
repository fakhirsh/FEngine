//
//  Math.h
//  FEngine
//
//  Created by Fakhir Shaheen on 14/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

namespace FEngine
{
    namespace Math
    {
        static const float PI = 3.14159265359f;
        
        float DegToRad(float a);        
        float RadToDeg(float a);

        class Point2D
        {
        public:
            Point2D(){x = y = 0.0f;}
            ~Point2D(){}
            
            float x, y;
        };
        
        class Point3D
        {
        public:
            Point3D(){x = y = z = 0.0f;}
            ~Point3D(){}
            
            float x, y, z;
        };
        
        class Rect
        {
        public:
            Rect(){x = y = width = height = 0.0f;}
            ~Rect(){}
            float x, y;
            float width, height;
        };
        
    }
}
