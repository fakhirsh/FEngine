//
//  Texture.h
//  WordGame
//
//  Created by Fakhir Shaheen on 31/10/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include <string>


namespace FEngine
{
    // PLEASE ADD COMMENTS About how to use this class
    
    class Texture
    {
    public:
        Texture();
        ~Texture();
        
        /**
         * Utility functions made static for global access.
         */
        //static bool LoadPngImage(const char * fileName, int &outWidth, int &outHeight, bool &outHasAlpha, unsigned char **outData);
        static unsigned int LoadFromPixels32(unsigned int texWidth, unsigned int texHeight, bool hasAlpha, unsigned int * pixels );
        
        /**
         * @param	name		Unique string identifier used to get the texture from texture manager. eg: "Level1Atlas_1024" etc etc
         * @param	fileName	Name of the image file located on the disk.
         */
        bool        LoadFromFile        (std::string fileName);
        bool        LoadFromStream      (std::istream & pngDataStream);
        
        /**
         * Sets already loaded Gl texture (such as a font texture generated else where).
         * @param	textureID   GL id of an already loaded texture
         * @param	width       Width of the texture
         * @param	height      Height of the texture
         * @param	hasAlpla    Whether the texture has transparency in it. Default value is false.
         */
        bool        SetTexture          (unsigned int textureID, int width, int height, bool hasAlpla = true);
        
        void        Unload              ();
        
        bool        Init                ();
        
        void        Bind                ();
        void        UnBind              ();
        
        void        SetName             (std::string name);
        std::string GetName             ();
        
        unsigned int GetID              ();
        
        int         GetWidth            ();
        int         GetHeight           ();
        
    private:
        
        std::string	_name;
        
        unsigned int	_textureID;
        int         _width;
        int         _height;
        int         _depth;
        bool        _hasAlpha;
    };
        
};


