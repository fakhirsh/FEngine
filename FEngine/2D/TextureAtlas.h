//
//  TextureAtlas.h
//  WordGame
//
//  Created by Fakhir Shaheen on 31/10/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#ifndef __WordGame__TextureAtlas__
#define __WordGame__TextureAtlas__


#include "../PointerDefs.h"

#include <map>
#include <string>

namespace FEngine
{
    
    struct SpriteMetaData
    {
        int x, y, width, height;
        float u, v, uW, vH;
        bool rotated;
    };

    // PLEASE ADD COMMENTS About how to use this class
    
    class TextureAtlas
    {
    public:
        TextureAtlas(void);
        ~TextureAtlas(void);
        
        /**
         * Directly reads data from memory streams
         */
        bool            Init            (std::string atlasName,
                                         std::istream & textureStream,
                                         const std::string & metaDataXMLStream);
        
        int             GetX            (std::string spriteName);
        int             GetY            (std::string spriteName);
        int             GetWidth        (std::string spriteName);
        int             GetHeight       (std::string spriteName);
        
        float           GetU            (std::string spriteName);
        float           GetV            (std::string spriteName);
        float           GetUWidth       (std::string spriteName);
        float           GetVHeight      (std::string spriteName);
        
        bool            IsRotated       (std::string spriteName);
        
        unsigned int    GetTextureID    ();
        
        void            Bind            ();
        void            UnBind          ();
        
        std::string     GetName         ();
        unsigned int    GetID           ();
        
        bool            IsSpriteValid   (std::string spriteName);
        
    private:
        
        unsigned int    _id;
        
        std::map<std::string, SpriteMetaData> _atlasData;
        TexturePtr      _texture;
        
        std::string     _textureAtlasName;
    };

};

#endif /* defined(__WordGame__TextureAtlas__) */
