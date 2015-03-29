//
//  SimpleVertex2D.h
//  FEngine
//
//  Created by Fakhir Shaheen on 28/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once


#include "Program.h"


namespace FEngine
{
    
    class SimpleVertex2DProgram : public Program
    {
    public:
        SimpleVertex2DProgram();
        ~SimpleVertex2DProgram();
        
        virtual bool    Init                        ();
        
        void            SetMatrix                   (float screenWidth, float screenHeight);
        void            SetColor                    (float r, float g, float b, float a);
        unsigned int    GetPositionAttribLocation   ();
        
    private:
        unsigned int    _positionAttrib;
        
        unsigned int    _PMVMatrixUniform;
        unsigned int    _colorUniform;
    };
    
};


