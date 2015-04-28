//
//  App.cpp
//  WordGame
//
//  Created by Fakhir Shaheen on 24/10/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#include "../Common.h"

#include "App.h"
#include "SystemConfig.h"

#include "../StateManager/StateManager.h"
#include "../SoundManager/SoundManager.h"
#include "../EventDispatcher/DefaultEvents.h"
#include "../EventDispatcher/EventDispatcher.h"
#include "../PhysicsManager/PhysicsManager.h"
#include "../Monetize/Ads/AdsStub.h"
//#include "../Social/FacebookStub.h"

//#include "../Renderer/IRenderer.h"
#include "../Debugging/LogDefault.h"

#include "../Utility/String.h"

#include <GameLogic/Screens/Test/Test.h>
#include <GameLogic/Screens/Splash1.h>
#include <GameLogic/Screens/Gameplay.h>
#include <GameLogic/Screens/Loading.h>

namespace FEngine
{
    unsigned int App::_GUID = 0;
    
    App::App ()
    {
        _frameBufferWidth           =   -1.0f;
        _frameBufferHeight          =   -1.0f;
        _logicalWidth               =   -1.0f;
        _logicalHeight              =   -1.0f;
        _viewportWidth              =   -1.0f;
        _viewportHeight             =   -1.0f;
        _logicalWidth               =   -1.0f;
        _logicalHeight              =   -1.0f;
        _designWidth                =   -1.0f;
        _designHeight               =   -1.0f;
        
        _deviceContentScaleFactor   =   -1.0f;
        _contentScaleFactor         =   -1.0f;
        _deviceAspectRatio          =   -1.0f;
        
        _availableRAM               =   0.0f;
        _availableStorage           =   0.0f;
        _cpuSpeed                   =   0.0f;
        
        _debugMode                  =   false;
        
        _elapsed                    =   0.0f;
        _currentFPS                 =   0.0f;
        _maxFPS                     =   60.0f;
        _origin.x                   =   -1.0f;
        _origin.y                   =   -1.0f;
        _ioManager                  =   NULL;
        _basicShare                 =   NULL;
        
        _isGamePaused               =   false;
    }

    App::~App ()
    {
        
    }
    
    bool App::Init (const SystemConfig * sysConfig)
    {
        
        // Renderer MUST be set BEFORE calling Init
        //_renderer = sysConfig->renderer;
        //if (_renderer == NULL) {
        //    return false;
        //}
        
        _ioManager = sysConfig->ioManager;
        
        // IO manager MUST be set BEFORE calling Init
        if(_ioManager == NULL)
        {
            return false;
        }
        
        _ads = sysConfig->ads;
        if(_ads == NULL)
        {
            _ads = new AdsStub();
        }
        
        _logger = sysConfig->log;
        if(_logger == NULL)
        {
            _logger = new LogDefault();
        }
        
        /*
        _facebook = sysConfig->facebook;
        if(_facebook == NULL)
        {
            _facebook = new FacebookStub();
        }
        */
        
        _basicShare = sysConfig->basicShare;
        if(_basicShare == NULL)
        {
            //_basicShare = new BasicShareStub();
        }
        
        _frameBufferWidth   =   sysConfig->frameBufferWidth;
        _frameBufferHeight  =   sysConfig->frameBufferHeight;
        _logicalWidth       =   sysConfig->logicalWidth;
        _logicalHeight      =   sysConfig->logicalHeight;
        _designWidth        =   sysConfig->designWidth;
        _designHeight       =   sysConfig->designHeight;
        _assetDesignWidth   =   sysConfig->assetDesignWidth;
        _assetDesignHeight  =   sysConfig->assetDesignHeight;
        
        _debugMode          =   sysConfig->debugMode;
    
        _deviceContentScaleFactor =   sysConfig->deviceContentScaleFactor;
        
        _maxFPS             =   sysConfig->maxFPS;
        _assetPath          =   sysConfig->assetPath;
        
        // Initialize random number generator
        srand((unsigned int)time(NULL));
        
        SurfaceChanged(_frameBufferWidth, _frameBufferHeight);
        
        glEnable    (GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear (GL_COLOR_BUFFER_BIT);
        
        //_renderer->EnableBlend();
        
        //_renderer->ClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        
        // Initialize the singleton Game state manager class. Also change State.
        //StatePtr statePtr = boost::make_shared<Test>();
        //StatePtr statePtr = boost::make_shared<Splash1>();
        //StatePtr statePtr = boost::make_shared<Gameplay>();
        StatePtr statePtr = boost::make_shared<Loading>();
        StateManager::Get()->ChangeState(statePtr);
        
        return true;
        
    }
    
    void App::Tick (float dt)
    {
        static float    prevFPSElapsed  =   0.0f;   // Used in FPS display code
        static int      frames          =   0;
    
        _elapsed += dt;
        
        // Update current FPS after every second
        if ((_elapsed - prevFPSElapsed) >= 1.0)
        {
            _currentFPS =   frames*1.0/(_elapsed - prevFPSElapsed);
            
            //std::string newMsg = string("FPS: ") + String::ToString(_currentFPS);
            //GetLog()->Print(newMsg);
            
            prevFPSElapsed =   _elapsed;
            frames      =   0;
        }

        frames++;
        
        Update (dt);
        Render (dt);
        
    }

    unsigned int App::GetNextGUID()
    {
        _GUID++;
        return _GUID;
    }
    
    void App::Update (float dt)
    {
        StateManager::Get()->Update(dt);
    }

    void App::Render (float dt)
    {
        glClear (GL_COLOR_BUFFER_BIT);
        //_renderer->Clear();

        StateManager::Get()->Render(dt);

    }

    void App::SurfaceChanged (int width, int height)
    {
        _frameBufferWidth   =   width;
        _frameBufferHeight  =   height;
        
        _deviceAspectRatio  = (float)_frameBufferWidth / (float)_frameBufferHeight;
        
        ComputeLetterBoxPolicy();

    }
    
    //////////////////////////////////////////////////////////////////
    //   Input handling

    void App::TouchDown (int x, int y)
    {
        //string newMsg = string("Raw x: ") + String::to_string(x) + string(" -- y: ") + String::to_string(y);
        //GetLog()->Print(newMsg);
        
        Math::Point2D sz = ScreenToSafeZone(Math::Point2D(x, y));
        Math::Point2D ds = SafeZoneToDesign(sz);
        
        boost::shared_ptr<FEngine::EventTouchDown> touchDownEvent = boost::make_shared<FEngine::EventTouchDown>();
        touchDownEvent->x = ds.x;
        touchDownEvent->y = ds.y;
        
        EventDispatcherPtr eventMgr = StateManager::Get()->GetEventDispatcher();
        eventMgr->TriggerEvent(touchDownEvent);

    }
    
    void App::TouchMoved (int x, int y)
    {
     
        //string newMsg = string("Raw x: ") + String::to_string(x) + string(" -- y: ") + String::to_string(y);
        //_logger->Print(newMsg);

        Math::Point2D sz = ScreenToSafeZone(Math::Point2D(x, y));
        Math::Point2D ds = SafeZoneToDesign(sz);

        boost::shared_ptr<FEngine::EventTouchMoved> touchMovedEvent = boost::make_shared<FEngine::EventTouchMoved>();
        touchMovedEvent->x = ds.x;
        touchMovedEvent->y = ds.y;
        
        EventDispatcherPtr eventMgr = StateManager::Get()->GetEventDispatcher();
        eventMgr->TriggerEvent(touchMovedEvent);

    }

    void App::TouchUp (int x, int y)
    {
        Math::Point2D sz = ScreenToSafeZone(Math::Point2D(x, y));
        Math::Point2D ds = SafeZoneToDesign(sz);
        
        boost::shared_ptr<FEngine::EventTouchUp> touchUpEvent = boost::make_shared<FEngine::EventTouchUp>();
        touchUpEvent->x = ds.x;
        touchUpEvent->y = ds.y;
        
        EventDispatcherPtr eventMgr = StateManager::Get()->GetEventDispatcher();
        eventMgr->TriggerEvent(touchUpEvent);
        
    }

    
    void App::TouchCancelled (int x, int y)
    {
        
    }

    //////////////////////////////////////////////////////////////////////////////////////


    void App::ComputeLetterBoxPolicy ()
    {
        
        // Asset aspect ratio
        //float assetAspectRatio  =   float(_assetDesignWidth) / float(_assetDesignHeight);
        
        // Design aspect ratio
        float designAspectRatio =   _designWidth / _designHeight;
        
        // Set SafeZone accordingly.
        // Case 1: The game is "thinner" than the screen
        if(designAspectRatio < _deviceAspectRatio)
        {
            _safeZoneRect.width  =   _frameBufferHeight * designAspectRatio;
            _safeZoneRect.height =   _frameBufferHeight;
            _origin.x = (_frameBufferWidth - _safeZoneRect.width) / 2.0f;
            _origin.y = 0.0f;
        }
        // Case 2: The game is "fatter" than the screen
        else if(designAspectRatio > _deviceAspectRatio)
        {
            _safeZoneRect.width  =   _frameBufferWidth;
            _safeZoneRect.height =   _frameBufferWidth / designAspectRatio;
            _origin.x = 0.0f;
            _origin.y = (_frameBufferHeight - _safeZoneRect.height) / 2.0f;
            
        }
        // Case 3: The game and the screen aspect ratios match exactly !!!
        else
        {
            _safeZoneRect.width  =   _frameBufferWidth;
            _safeZoneRect.height =   _frameBufferHeight;
            _origin.x = 0.0f;
            _origin.y = 0.0f;
        }

        _safeZoneRect.x = _origin.x;
        _safeZoneRect.y = _origin.y;
        
        _viewportWidth  =   _frameBufferWidth;
        _viewportHeight =   _frameBufferHeight;
        //_renderer->SetViewPort(0.0f, 0.0f, _viewportWidth, _viewportHeight);
        glViewport(0.0f, 0.0f, _viewportWidth, _viewportHeight);
        //glViewport(_safeZoneRect.x, _safeZoneRect.y, _safeZoneRect.width, _safeZoneRect.height);
        
        _contentScaleFactor = _safeZoneRect.width / _assetDesignWidth;
        //_contentScaleFactor = 1.0f;
        
        // Output message ONLY for testing:
        std::string newMsg =    std::string("DEBUG ==> \nScreen Width: ")   + String::ToString(int(_frameBufferWidth))
                                + std::string("\nScreen Height: ")          + String::ToString(int(_frameBufferHeight))
                                + std::string("\nViewport Width: ")         + String::ToString(int(_viewportWidth))
                                + std::string("\nViewport Height: ")        + String::ToString(int(_viewportHeight))
                                + std::string("\nSafe Zone x: ")            + String::ToString(int(_safeZoneRect.x))
                                + std::string("\nSafe Zone y: ")            + String::ToString(int(_safeZoneRect.y))
                                + std::string("\nSafe Zone Width: ")        + String::ToString(int(_safeZoneRect.width))
                                + std::string("\nSafe Zone Height: ")       + String::ToString(int(_safeZoneRect.height))
                                + std::string("\nCSF: ")                    + String::ToString(_contentScaleFactor);
        
        GetLog()->Print(newMsg);
        
    }

    
    Math::Point2D App::ScreenToSafeZone (const Math::Point2D & screenSpace)
    {
        Math::Point2D safeZone;
        
        safeZone.x = screenSpace.x - GetOrigin().x;
        safeZone.y = screenSpace.y - GetOrigin().y;
        
        return safeZone;
    }
    
    Math::Point2D App::SafeZoneToScreen (const Math::Point2D & safeZone)
    {
        Math::Point2D screen;
        
        screen.x = safeZone.x + GetOrigin().x;
        screen.y = safeZone.y + GetOrigin().y;
        
        return screen;
    }
    
    Math::Point2D App::SafeZoneToDesign (const Math::Point2D & safeZone)
    {
        Math::Point2D design;
        
        design.x = safeZone.x / GetContentScaleFactor();
        design.y = safeZone.y / GetContentScaleFactor();
        
        return design;
    }
    
    Math::Point2D App::DesignToSafeZone (const Math::Point2D & designSpace)
    {
        Math::Point2D safeZone;
        
        safeZone.x = designSpace.x * GetContentScaleFactor();
        safeZone.y = designSpace.y * GetContentScaleFactor();
        
        return safeZone;
    }
    
    /*
    Math::Point2D App::ScreenSpaceToDesignSpace  (const Math::Point2D & screenSpace)
    {
        Math::Point2D designSpace;
        
        // 1. Move screen space to the new origin:
        Math::Point2D newScreenSpace(screenSpace.x - _origin.x, screenSpace.y - _origin.y);
        
        
        return designSpace;
    }
    
    Math::Point2D App::DesignSpaceToScreenSpace  (const Math::Point2D & designSpace)
    {
        Math::Point2D screenSpace;
        
        
        
        return screenSpace;
    }
    */
     
//////////////////////////////////////////////////////////////////////////////////////

    // The following two functions appear to be buggy. Please fix:
    //
    // 1. DesignSpaceToViewportSpace()
    // 2. ViewportSpaceToDesignSpace()
    //
    
/*
    Math::Point2D App::DesignSpaceToViewportSpace (const Math::Point2D & designSpace)
    {
        struct BOX
        {
            float l,r,b,t;
        };
        
        Math::Point2D vpSpace;
        BOX V, D;
        
        V.l = 0.0f;
        V.r = _viewportWidth;
        V.b = 0.0f;
        V.t = _viewportHeight;
        
        D.l = 0.0f;
        D.r = _designWidth;
        D.b = 0.0f;
        D.t = _designHeight;
        
        vpSpace.x = ((V.r - V.l)/(D.r - D.l))*(designSpace.x - D.l) + V.l;
        vpSpace.y = ((V.t - V.b)/(D.t - D.b))*(designSpace.y - D.b) + V.b;
        
        return vpSpace;
    }
    
    Math::Point2D App::ViewportSpaceToDesignSpace (const Math::Point2D & vpSpace)
    {
        struct BOX
        {
            float l,r,b,t;
        };
        
        Math::Point2D designSpace;
        BOX V, D;
        
        V.l = 0.0f;
        V.r = _viewportWidth;
        V.b = 0.0f;
        V.t = _viewportHeight;
        
        D.l = 0.0f;
        D.r = _designWidth;
        D.b = 0.0f;
        D.t = _designHeight;
        
        designSpace.x = ((D.r - D.l)/(V.r - V.l))*(vpSpace.x - V.l) + D.l;
        designSpace.y = ((D.t - D.b)/(V.t - V.b))*(vpSpace.y - V.b) + D.b;
        
        return designSpace;
    }

/////////////////////////////////////////////////////////////////////////////////
    
    
    Math::Point2D App::DesignSpaceToSafeZone (const Math::Point2D & designSpace)
    {
        struct BOX
        {
            float l,r,b,t;
        };
        
        Math::Point2D safeZone;
        BOX V, D;
        
        V.l = _safeZoneRect.x;
        V.r = _safeZoneRect.width + V.l;
        V.b = _safeZoneRect.y;
        V.t = _safeZoneRect.height + V.b;
        
        D.l = 0.0f;
        D.r = _designWidth;
        D.b = 0.0f;
        D.t = _designHeight;
        
        safeZone.x = ((V.r - V.l)/(D.r - D.l))*(designSpace.x - D.l) + V.l;
        safeZone.y = ((V.t - V.b)/(D.t - D.b))*(designSpace.y - D.b) + V.b;
        
        return safeZone;

    }
    
    Math::Point2D App::SafeZoneToDesignSpace (const Math::Point2D & safeZone)
    {
        struct BOX
        {
            float l,r,b,t;
        };
        
        Math::Point2D designSpace;
        BOX V, D;
        
        V.l = _safeZoneRect.x;
        V.r = _safeZoneRect.width + V.l;
        V.b = _safeZoneRect.y;
        V.t = _safeZoneRect.height + V.b;
        
        D.l = 0.0f;
        D.r = _designWidth;
        D.b = 0.0f;
        D.t = _designHeight;
        
        designSpace.x = ((D.r - D.l)/(V.r - V.l))*(safeZone.x - V.l) + D.l;
        designSpace.y = ((D.t - D.b)/(V.t - V.b))*(safeZone.y - V.b) + D.b;
        
        return designSpace;

    }
*/
    //////////////////////////////////////////////////////////////////////////////////////


    void App::SetDeviceContentScaleFactor (float deviceContentScaleFactor)
    {
        _deviceContentScaleFactor = deviceContentScaleFactor;
    }

    float App::GetDeviceContentScaleFactor ()
    {
        return _deviceContentScaleFactor;
    }
    
    
    void App::SetIOManager (IOManager * fileManager)
    {
        _ioManager = fileManager;
    }
    
    IOManager * const App::GetIOManager ()
    {
        return _ioManager;
    }
    
    IRenderer * const App::GetRenderer ()
    {
        return _renderer;
    }

    Ads * const App::GetAds ()
    {
        return _ads;
    }
    
    Log * const App::GetLog()
    {
        return _logger;
    }
    
    /*
    Facebook * const App::GetFacebook ()
    {
        return _facebook;
    }
    */
    
    BasicShare * const  App::GetBasicShare()
    {
        return _basicShare;
    }
    
    void App::SetAssetPath (const char * path)
    {
        _assetPath = std::string(path);
    }

    std::string App::GetAssetPath ()
    {
        return _assetPath;
    }

    void App::SetFrameBufferWidth (float val)
    {
        _frameBufferWidth = val;
    }

    void App::SetFrameBufferHeight (float val)
    {
        _frameBufferHeight = val;
    }

    //void App::SetGameScreenWidth (float val)
    //{
    //    _screenWidth = val;
    //}

    //void App::SetGameScreenHeight (float val)
    //{
    //    _screenHeight = val;
    //}

    bool App::IsGamePaused ()
    {
        return _isGamePaused;
    }
    
    void App::PauseGame ()
    {
        GetLog()->Print(string("------------------- App::PauseGame  -------------------"));
        
        _isGamePaused = true;
        
        SoundManager::Get()->PauseAllSounds();
        
        /*
        boost::shared_ptr<FEngine::EventGamePaused> pauseEvent = boost::make_shared<FEngine::EventGamePaused>();
        EventDispatcherPtr eventMgr = StateManager::Get()->GetEventDispatcher();
        eventMgr->TriggerEvent(pauseEvent);
         */
    }
    
    void App::ResumeGame ()
    {
        if(GetLog()){
            GetLog()->Print(string("------------------- App::ResumeGame  -------------------"));
            SoundManager::Get()->ResumeAllSounds();
        }
        
        _isGamePaused = false;
        
        /*
        boost::shared_ptr<FEngine::EventGameResumed> resumeEvent = boost::make_shared<FEngine::EventGameResumed>();
        EventDispatcherPtr eventMgr = StateManager::Get()->GetEventDispatcher();
        eventMgr->TriggerEvent(resumeEvent);
         */
    }
    
    void App::SetLogicalWidth (float val)
    {
        _logicalWidth = val;
    }

    void App::SetLogicalHeight (float val)
    {
        _logicalHeight = val;
    }

    float App::GetFrameBufferWidth ()
    {
        return _frameBufferWidth;
    }

    float App::GetFrameBufferHeight ()
    {
        return _frameBufferHeight;
    }

    float App::GetViewportWidth ()
    {
        return _viewportWidth;
    }

    float App::GetViewportHeight ()
    {
        return _viewportHeight;
    }

    float App::GetLogicalWidth ()
    {
        return _logicalWidth;
    }

    float App::GetLogicalHeight ()
    {
        return _logicalHeight;
    }

    float App::GetDesignWidth ()
    {
        return _designWidth;
    }

    float App::GetDesignHeight ()
    {
        return _designHeight;
    }

    float App::GetContentScaleFactor ()
    {
        return _contentScaleFactor;
    }

    Math::Point2D App::GetOrigin ()
    {
        return _origin;
    }

    float App::GetSafeWidth ()
    {
        return _safeZoneRect.width;
    }
    
    float App::GetSafeHeight ()
    {
        return _safeZoneRect.height;
    }
    
    float App::GetFPS ()
    {
        return _currentFPS;
    }
    
    float App::GetMaxFPS ()
    {
        return _maxFPS;
    }

    bool App::IsDebugModeOn ()
    {
        return _debugMode;
    }
    
    float App::GetElapsedTime ()
    {
        return _elapsed;
    }
    
    
};


