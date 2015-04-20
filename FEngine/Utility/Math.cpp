//
//  Math.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 21/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "Math.h"


namespace FEngine
{
    namespace Math
    {
        
        float DegToRad(float a)
        {
            return (a * PI / 180.0f);
        }
        
        float RadToDeg(float a)
        {
            return (a * 180.0f / PI);
        }
        
        float Min(float a, float b)
        {
            if(a < b) return a;
            else return b;
        }
        
        float Max(float a, float b)
        {
            if(a > b) return a;
            else return b;
        }
    }
}