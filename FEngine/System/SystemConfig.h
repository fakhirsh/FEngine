//
//  SystemConfig.h
//  Game
//
//  Created by Fakhir Shaheen on 17/02/2015.
//
//

#pragma once

#include <string>
#include <vector>

using namespace std;

/***********************************************************************
 * SystemConfig
 *    A data structure that nicely packs essential system configuration
 *    parameters in one place. Just pass this structure into the Engine
 *    instead of having million parameters in the "Init" function.
 ***********************************************************************/

namespace FEngine
{
    class IOManager;
    class IRenderer;
    class Ads;
    class Log;
    
    class SystemConfig
    {
    public:
        SystemConfig();
        
        /*
         *  LoadConfiguration
         *  @param  buffer    A memory buffer containing entire config XML file.
         */
        bool        LoadConfig      (vector<char> & buffer);
        
        string      className;
        string      windowTitle;
        
        int         frameBufferWidth;
        int         frameBufferHeight;
        int         logicalWidth;       // Primarily for iOS
        int         logicalHeight;
        int         designWidth;
        int         designHeight;
        int         assetDesignWidth;
        int         assetDesignHeight;
        
        float       deviceContentScaleFactor;
        
        bool        debugMode;
        
        bool        allowFullScreen;
        bool        runFullSpeed;
        int         maxFPS;
        
        float       sfxVolume;      // 0% to 100%
        float       musicVolume;    // 0% to 100%
        
        string      defaultLocalization;

        string      assetPath;
        
        IOManager * ioManager;
        IRenderer * renderer;
        Ads *       ads;
        Log *       log;
        //SoundManager * sndManager;
        //Other System specific Crap * allCrapHere...
    };

};