//
//  TexturedVertexProgram.h
//  WordGame
//
//  Created by Fakhir Shaheen on 31/10/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#pragma once


#include "Program.h"


namespace FEngine
{
    
    class TexturedVertexProgram : public Program
    {
    public:
        TexturedVertexProgram();
        ~TexturedVertexProgram();
        
        virtual bool    Init                        ();
        
        void            SetMatrix                   (float screenWidth, float screenHeight);
        
        unsigned int    GetPositionAttribLocation   ();
        unsigned int    GetUVAttribLocation         ();
        unsigned int    GetColorAttribLocation      ();
        
    private:
        unsigned int    _positionAttrib;
        unsigned int    _uvAttrib;
        unsigned int    _colorAttrib;
        
        unsigned int    _PMVMatrixUniform;
    };

};


