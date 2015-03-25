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
    class   State;
    class   StateManager;
    class   Process;
    class   ProcessScheduler;
    class   Program;
    class   Texture;
    class   TextureAtlas;
    //class SpriteBatch;
    //class Sprite;
    class   Event;
    class   EventDispatcher;
    class   SceneNode;
    class   SceneNode2D;
    class   SpriteNode;
    class   RootSceneNode2D;
    class   SceneNodeProperties2D;
    //class FontAtlas;
};


typedef boost::shared_ptr   <FEngine::State>                    StatePtr;
typedef boost::shared_ptr   <FEngine::StateManager>             StateManagerPtr;

typedef boost::shared_ptr   <FEngine::SceneNode>                SceneNodePtr;
typedef boost::weak_ptr     <FEngine::SceneNode>                SceneNodeWeakPtr;

typedef boost::shared_ptr   <FEngine::SceneNode2D>              SceneNode2DPtr;
typedef boost::weak_ptr     <FEngine::SceneNode2D>              SceneNode2DWeakPtr;
typedef boost::shared_ptr   <FEngine::SpriteNode>               SpriteNodePtr;
typedef boost::weak_ptr     <FEngine::SpriteNode>               SpriteNodeWeakPtr;
typedef boost::shared_ptr   <FEngine::RootSceneNode2D>          RootSceneNode2DPtr;
typedef boost::weak_ptr     <FEngine::RootSceneNode2D>          RootSceneNode2DWeakPtr;
typedef boost::shared_ptr   <FEngine::SceneNodeProperties2D>    SceneNodeProperties2DPtr;

typedef boost::shared_ptr   <FEngine::Process>                  ProcessPtr;
typedef boost::weak_ptr     <FEngine::Process>                  ProcessWeakPtr;
typedef boost::shared_ptr   <FEngine::ProcessScheduler>         ProcessSchedulerPtr;

typedef boost::shared_ptr   <FEngine::Program>                  ProgramPtr;
typedef boost::weak_ptr     <FEngine::Program>                  ProgramWeakPtr;

typedef boost::shared_ptr   <FEngine::Texture>                  TexturePtr;
typedef boost::weak_ptr     <FEngine::Texture>                  TextureWeakPtr;
typedef boost::shared_ptr   <FEngine::TextureAtlas>             TextureAtlasPtr;
typedef boost::weak_ptr     <FEngine::TextureAtlas>             TextureAtlasWeakPtr;

//typedef boost::shared_ptr <FEngine::SpriteBatch>              SpriteBatchPtr;
//typedef boost::shared_ptr <FEngine::Sprite>                   SpritePtr;

typedef boost::shared_ptr   <FEngine::Event>                    EventPtr;
typedef boost::weak_ptr     <FEngine::Event>                    EventWeakPtr;
typedef boost::shared_ptr   <FEngine::EventDispatcher>          EventDispatcherPtr;

//typedef boost::shared_ptr <FEngine::FontAtlas>                FontAtlasPtr;

// Consider this as a "Function Pointer" for class member functions
typedef fastdelegate::FastDelegate1 <EventPtr>                  EventListenerDelegate;

///////////////////////////////////////////////////////////////////



