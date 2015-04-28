//
//  SoundManager.h
//  WordGame
//
//  Created by Fakhir Shaheen on 06/11/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "../PointerDefs.h"

#include <string>
#include <vector>
#include <map>

#ifdef __APPLE__
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#else
#include <AL/al.h>
#include <AL/alc.h>
#endif


namespace FEngine
{

    class SoundManager
    {
    public:
        ~SoundManager();
        
        static SoundManager * Get();
        
        
    /////////////////////////////////////////////////////////////////////////////////////
        
        bool    LoadOGGFromFile (std::string fileName);
        
        bool    LoadOGGFromMem  (std::vector<char> & oggFileData, std::vector<char> & buffer);
        
        void    PlaySound       (std::string fileName);
        void    StopSound       (std::string fileName);
        
        void    SetVolume       (std::string fileName, float newVolume);
        void    SetPitch        (std::string fileName, float newPitch);
        
        void    GamePauseListener   (EventPtr e);
        void    GameResumeListener  (EventPtr e);
        
        void    PauseAllSounds  ();
        void    ResumeAllSounds ();
        
    private:
        
        SoundManager        ();
        bool    Init        ();
        
        static SoundManager *   _instance;
        
        ALCdevice *             _deviceAL;
        ALCcontext *            _contextAL;
        
        std::map<std::string, ALuint> _bufferMap;
        std::map<std::string, ALuint> _sourceMap;
        
        std::vector<ALuint>     _pausedSources;
        
/////////////////////////////////////////////////////////////////////////////////////////////
        
        ALenum _format;
        ALsizei _freq;
        
        ALint _state;                // The state of the sound source
        //ALuint _bufferID;            // The OpenAL sound buffer ID
        //ALuint _sourceID;            // The OpenAL sound source
        
    };

};


