//
//  SoundManager.cpp
//  WordGame
//
//  Created by Fakhir Shaheen on 06/11/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#include "SoundManager.h"
#include "../ResourceCache/IOManager.h"

#include "../System/App.h"

#include <vorbis/vorbisfile.h>

#include <iostream>

// Custom callbacks to read ogg from memory.
// Reference :
// http://stackoverflow.com/questions/13437422/libvorbis-audio-decode-from-memory-in-c


extern FEngine::App * gApp;


struct ogg_file
{
    char* curPtr;
    char* filePtr;
    size_t fileSize;
};

size_t AR_readOgg(void* dst, size_t size1, size_t size2, void* fh)
{
    ogg_file* of = reinterpret_cast<ogg_file*>(fh);
    size_t len = size1 * size2;
    if ( of->curPtr + len > of->filePtr + of->fileSize )
    {
        len = of->filePtr + of->fileSize - of->curPtr;
    }
    memcpy( dst, of->curPtr, len );
    of->curPtr += len;
    return len;
}

int AR_seekOgg( void *fh, ogg_int64_t to, int type ) {
    ogg_file* of = reinterpret_cast<ogg_file*>(fh);
    
    switch( type ) {
        case SEEK_CUR:
            of->curPtr += to;
            break;
        case SEEK_END:
            of->curPtr = of->filePtr + of->fileSize - to;
            break;
        case SEEK_SET:
            of->curPtr = of->filePtr + to;
            break;
        default:
            return -1;
    }
    if ( of->curPtr < of->filePtr ) {
        of->curPtr = of->filePtr;
        return -1;
    }
    if ( of->curPtr > of->filePtr + of->fileSize ) {
        of->curPtr = of->filePtr + of->fileSize;
        return -1;
    }
    return 0;
}

int AR_closeOgg(void* fh)
{
    return 0;
}

long AR_tellOgg( void *fh )
{
    ogg_file* of = reinterpret_cast<ogg_file*>(fh);
    return (of->curPtr - of->filePtr);
}



namespace FEngine
{

    SoundManager * SoundManager::_instance = NULL;

    #define BUFFER_SIZE   32768     // 32 KB buffers

    //ALint state;                // The state of the sound source
    //ALuint bufferID;            // The OpenAL sound buffer ID
    //ALuint sourceID;            // The OpenAL sound source
    //ALenum format;              // The sound data format
    //ALsizei freq;               // The frequency of the sound data


    SoundManager::SoundManager()
    {

    }

    SoundManager::~SoundManager()
    {

    }

    SoundManager * SoundManager::Get()
    {
        if(!_instance)
        {
            _instance = new SoundManager();
            _instance->Init();
        }
        
        return _instance;
    }

    bool SoundManager::Init()
    {
        
        //reset error stack
        alGetError();
        
        _deviceAL = alcOpenDevice(NULL);
        if (_deviceAL == NULL)
        {
            std::cout << "Failed to open OpenAL device..." << std::endl;
            return false;
        }
        
        _contextAL = alcCreateContext(_deviceAL, NULL);
        if (_contextAL == NULL)
        {
            std::cout << "Failed to create OpenAL context..." << std::endl;
            return false;
        }
        
        alcMakeContextCurrent(_contextAL);
        ALenum err = alGetError();
        if (err != AL_NO_ERROR)
        {
            std::cout << "Failed to make current context..." << std::endl;
            return false;
        }
/*
        // Create the buffers
        alGenBuffers(1, &_bufferID);
        ALenum error;
        if ((error = alGetError()) != AL_NO_ERROR)
        {
            std::cout << "Failed to generate buffer : " << error << std::endl;
            return false;
        }
        
        // Create the source
        alGenSources(1, &_sourceID);
        if ((error = alGetError()) != AL_NO_ERROR)
        {
            std::cout << "Failed to generate source : " << error << std::endl;
            return false;
        }
 */
        return true;
    }


    void SoundManager::PlaySound(std::string fileName)
    {
        //alGetSourcei(sourceID, AL_SOURCE_STATE, &state);
        //if(state != AL_PLAYING)
        //{
            ALuint sourceID = _sourceMap[fileName];
            alSourcePlay(sourceID);
        //}
    }
    
    void SoundManager::SetVolume(std::string fileName, float newVolume)
    {
        ALuint sourceID = _sourceMap[fileName];
        alSourcef(sourceID, AL_GAIN, newVolume);
    }
    
    bool SoundManager::LoadOGGFromFile(std::string fileName)
    {
        std::string fullSoundPath = gApp->GetAssetPath() + fileName;
        
        IOManager * ioMgr = gApp->GetIOManager();
        
        // Read raw byte stream from the source file
        std::vector<char> fileStream;
        // The sound buffer data from file
        std::vector<char> bufferData;
        
        ioMgr->GetAssetStream(fullSoundPath, fileStream);
        if(fileStream.size() <= 0)
        {
            std::cout << "SoundManager: Failed to load resource: " << fileName << std::endl;
            return false;
        }
        
        LoadOGGFromMem(fileStream, bufferData);
        
        // Create the buffers
        ALuint bufferID;
        alGenBuffers(1, &bufferID);
        ALenum error;
        if ((error = alGetError()) != AL_NO_ERROR)
        {
            std::cout << "Failed to generate buffer : " << error << std::endl;
            return false;
        }

        // Create the source
        ALuint sourceID;
        alGenSources(1, &sourceID);
        if ((error = alGetError()) != AL_NO_ERROR)
        {
            std::cout << "Failed to generate source : " << error << std::endl;
            return false;
        }
        
        alBufferData(bufferID, _format, &bufferData[0], static_cast<ALsizei>(bufferData.size()), _freq);
        _bufferMap[fileName] = bufferID;
        
        alSourcei(sourceID, AL_BUFFER, bufferID);
        _sourceMap[fileName] = sourceID;
        
        return true;
    }
    
    bool SoundManager::LoadOGGFromMem(std::vector<char> & oggFileData, std::vector<char> & buffer)
    {
        int endian = 0;             // 0 for Little-Endian, 1 for Big-Endian
        int bitStream;
        long bytes;
        char array[BUFFER_SIZE];    // Local fixed size array
        
        ov_callbacks callbacks;
        ogg_file of;
        
        of.curPtr = of.filePtr = &oggFileData[0];
        of.fileSize = oggFileData.size();
        
        OggVorbis_File oggFile;

        memset( &oggFile, 0, sizeof( OggVorbis_File ) );
        
        callbacks.read_func = AR_readOgg;
        callbacks.seek_func = AR_seekOgg;
        callbacks.close_func = AR_closeOgg;
        callbacks.tell_func = AR_tellOgg;
        
        int ret = ov_open_callbacks((void *)&of, &oggFile, NULL, -1, callbacks);
        
        vorbis_info* pInfo = ov_info(&oggFile, -1);
        
        // Check the number of channels... always use 16-bit samples
        if (pInfo->channels == 1)
            _format = AL_FORMAT_MONO16;
        else
            _format = AL_FORMAT_STEREO16;
        
        // The frequency of the sampling rate
        _freq = pInfo->rate;
        
        do {
            // Read up to a buffer's worth of decoded sound data
            bytes = ov_read(&oggFile, array, BUFFER_SIZE, endian, 2, 1, &bitStream);
            // Append to end of buffer
            buffer.insert(buffer.end(), array, array + bytes);
        } while (bytes > 0);
        
        ov_clear(&oggFile);
        
        return true;
    }
    
};

