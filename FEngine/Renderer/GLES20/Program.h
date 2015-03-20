//
//  Program.h
//  WordGame
//
//  Created by Fakhir Shaheen on 30/10/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include <string>

namespace FEngine
{

    class Program
    {
    public:
        Program();
        virtual ~Program();
        
        virtual bool    Init            ()  =   0;

        unsigned int    GetProgramID    ();
        std::string     GetProgramName  ();
        
        void            Bind            ();
        void            UnBind          ();
        void            Unload          ();
        
    protected:
        
        //bool          Init            (std::string vertexShaderSource, std::string fragmentShaderSource);
        bool            LinkProgram     (std::string vertexShaderSource, std::string fragmentShaderSource);
        unsigned int    LoadShaderFromFile(std::string path, unsigned int shaderType);
        unsigned int    LoadShaderFromString(std::string shaderString, unsigned int shaderType);
        
        unsigned int    _fragmentShader;
        unsigned int    _vertexShader;
        unsigned int    _programID;
        
        std::string     _name;
        
    };

};


