//
//  SystemConfig.cpp
//  Game
//
//  Created by Fakhir Shaheen on 17/02/2015.
//
//

#include "SystemConfig.h"
#include <tinyxml2.h>

//#include "IOManager.h"

//using namespace tinyxml2;

namespace FEngine
{

    SystemConfig::SystemConfig()
    {
        frameBufferWidth    =   -1;
        frameBufferHeight   =   -1;
        logicalWidth        =   -1;
        logicalHeight       =   -1;
        designWidth         =   -1;
        designHeight        =   -1;
        assetDesignWidth    =   -1;
        assetDesignHeight   =   -1;
        
        debugMode           =   false;
        
        deviceContentScaleFactor  =   -1.0f;
        
        allowFullScreen     =   false;
        runFullSpeed        =   false;
        maxFPS              =   -1;
        
        sfxVolume           =   -1.0f;
        musicVolume         =   -1.0f;
        
        ioManager           =   NULL;
        renderer            =   NULL;
        ads                 =   NULL;
    }

    bool SystemConfig::LoadConfig(vector<char> & buffer)
    {
        tinyxml2::XMLDocument configXML;
        tinyxml2::XMLError xmlErr;
        
        xmlErr = configXML.Parse((const char*)&buffer[0], buffer.size());
        if(xmlErr != tinyxml2::XML_SUCCESS)
        {
            return false;
        }

        tinyxml2::XMLElement * root;
        tinyxml2::XMLElement * child;
        
        root = configXML.FirstChildElement( "SystemConfig" );
        
        child = root->FirstChildElement( "WindowSystem" );
        className= child->Attribute("className");
        windowTitle = child->Attribute("windowTitle");
        
        child = child->NextSiblingElement( "Graphics" );
        
        sscanf(child->Attribute("frameBufferWidth"), "%d", &frameBufferWidth);
        sscanf(child->Attribute("frameBufferHeight"), "%d", &frameBufferHeight);
        sscanf(child->Attribute("designWidth"), "%d", &designWidth);
        sscanf(child->Attribute("designHeight"), "%d", &designHeight);
        sscanf(child->Attribute("assetDesignWidth"), "%d", &assetDesignWidth);
        sscanf(child->Attribute("assetDesignHeight"), "%d", &assetDesignHeight);

        std::string fullScreen = child->Attribute("allowFullScreen");
        if(fullScreen == "false")
        {
            allowFullScreen = false;
        }
        else
        {
            allowFullScreen = true;
        }
        
        std::string fullSpeed = child->Attribute("runFullSpeed");
        if(fullSpeed == "false")
        {
            runFullSpeed = false;
        }
        else
        {
            runFullSpeed = true;
        }
        
        sscanf(child->Attribute("maxFPS"), "%d", &maxFPS);
        
        child = child->NextSiblingElement( "Sound" );
        sscanf(child->Attribute("sfxVolume"), "%f", &sfxVolume);
        sscanf(child->Attribute("musicVolume"), "%f", &musicVolume);
        
        
        child = child->NextSiblingElement( "Physics" );
        std::string debugModeStr = child->Attribute("debugMode");
        if(debugModeStr == "false")
        {
            debugMode = false;
        }
        else
        {
            debugMode = true;
        }

        
        return true;
    }

};