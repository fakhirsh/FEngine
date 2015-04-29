//
//  Facebook.h
//  FEngine
//
//  Created by Fakhir Shaheen on 17/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

namespace FEngine
{
    class Serialize
    {
    public:
        Serialize(){}
        virtual ~Serialize(){}
        
        
        virtual void    SetHighScore    (int score) =   0;
        virtual int     GetHighScore    ()          =   0;
        
    };
}