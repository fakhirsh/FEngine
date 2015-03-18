//
//  PointerDefs.h
//  FEngine
//
//  Created by Fakhir Shaheen on 17/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include <FastDelegate.h>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared.hpp>
#include <boost/smart_ptr/weak_ptr.hpp>

///////////////////////////////////////////////////////////////////
// Common pointer typedefs

namespace FEngine
{
    class State;
    class Process;
    class ProcessScheduler;
    //    class Texture;
    //    class TextureAtlas;
    //    class SpriteBatch;
    //    class Sprite;
    class Event;
    class EventDispatcher;
    //    class FontAtlas;
};


typedef boost::shared_ptr<FEngine::State>             StatePtr;

typedef boost::shared_ptr<FEngine::Process>           ProcessPtr;
typedef boost::weak_ptr  <FEngine::Process>           ProcessWeakPtr;
typedef boost::shared_ptr<FEngine::ProcessScheduler>  ProcessSchedulerPtr;

//typedef boost::shared_ptr<FEngine::Texture>           TexturePtr;
//typedef boost::shared_ptr<FEngine::TextureAtlas>      TextureAtlasPtr;

//typedef boost::shared_ptr<FEngine::SpriteBatch>       SpriteBatchPtr;
//typedef boost::shared_ptr<FEngine::Sprite>            SpritePtr;

typedef boost::shared_ptr<FEngine::Event>             EventPtr;
typedef boost::weak_ptr  <FEngine::Event>             EventWeakPtr;
typedef boost::shared_ptr<FEngine::EventDispatcher>   EventDispatcherPtr;

//typedef boost::shared_ptr<FEngine::FontAtlas>         FontAtlasPtr;

// Consider this as a "Function Pointer" for class member functions
typedef fastdelegate::FastDelegate1<EventPtr>         EventListenerDelegate;

///////////////////////////////////////////////////////////////////



