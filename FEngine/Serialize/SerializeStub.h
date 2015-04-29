//
//  Facebook.h
//  FEngine
//
//  Created by Fakhir Shaheen on 17/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "Serialize.h"

namespace FEngine
{
    class SerializeStub : public Serialize
    {
    public:
        SerializeStub(){}
        virtual ~SerializeStub(){}
        
        virtual void SetHighScore(int score);
        virtual int  GetHighScore();
        
    };
}