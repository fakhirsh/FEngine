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
//#include "../SoundManager/SoundManager.h"
//#include "../EventManager/DefaultEvents.h"
//#include "../EventManager/EventManager.h"
//#include "../Renderer/IRenderer.h"




#include <GameLogic/Screens/Test/Test.h>


namespace FEngine
{
    
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
        
        _elapsed                    =   0.0f;
        _currentFPS                 =   0.0f;
        _maxFPS                     =   60.0f;
        _origin.x                   =   -1.0f;
        _origin.y                   =   -1.0f;
        _ioManager                  =   NULL;
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
        
        _frameBufferWidth   =   sysConfig->frameBufferWidth;
        _frameBufferHeight  =   sysConfig->frameBufferHeight;
        _logicalWidth       =   sysConfig->logicalWidth;
        _logicalHeight      =   sysConfig->logicalHeight;
        _designWidth        =   sysConfig->designWidth;
        _designHeight       =   sysConfig->designHeight;
        _assetDesignWidth   =   sysConfig->assetDesignWidth;
        _assetDesignHeight  =   sysConfig->assetDesignHeight;
        
        _deviceAspectRatio  = (float)_frameBufferWidth / (float)_frameBufferHeight;
        _deviceContentScaleFactor =   sysConfig->deviceContentScaleFactor;
        
        _maxFPS             =   sysConfig->maxFPS;
        _assetPath          =   sysConfig->assetPath;
        
        // Initialize random number generator
        srand((unsigned int)time(NULL));
        
        ComputeLetterBoxPolicy();
        
        glEnable    (GL_BLEND);
        glBlendFunc (GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        
        //_renderer->EnableBlend();
        
        //_renderer->ClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        
        // Initialize the singleton Game state manager class. Also change State.
        StatePtr statePtr = boost::make_shared<Test>();
        StateManager::Get()->ChangeState(statePtr);
        
        // Initialize the singleton Sound manager class.
        //SoundManager::Get();
        
        return true;
        
    }
    
    void App::Tick (float dt)
    {
        static float    basetime    =   0.0f;
        static int      frames      =   0;
        
        _elapsed += dt;
        
        if ((_elapsed - basetime) > 1.0)
        {
            _currentFPS =   frames*1.0/(_elapsed - basetime);
            //std::cout << "FPS: " << _currentFPS << std::endl;
            basetime    =   _elapsed;
            frames      =   0;
        }
        
        frames++;
        
        Update (dt);
        Render (dt);
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

    //////////////////////////////////////////////////////////////////
    //   Input handling

    void App::TouchDown (int x, int y)
    {
        /*
        boost::shared_ptr<Fakhir::EventTouchDown> touchDownEvent = boost::make_shared<Fakhir::EventTouchDown>();
        // Adjust coordinates according to new viewport origin
        glm::vec2 viewportSpace(x - _origin.x, y - _origin.y);
        glm::vec2 designSpace = ViewportSpaceToDesignSpace(viewportSpace);
        touchDownEvent->x = designSpace.x;
        touchDownEvent->y = designSpace.y;
        
        EventManagerPtr eventMgr = StateManager::Get()->GetEventManager();
        eventMgr->TriggetEvent(touchDownEvent);
        */
    }

    void App::TouchUp (int x, int y)
    {
        /*
        boost::shared_ptr<Fakhir::EventTouchUp> touchUpEvent = boost::make_shared<Fakhir::EventTouchUp>();
        // Adjust coordinates according to new viewport origin
        glm::vec2 viewportSpace(x - _origin.x, y - _origin.y);
        glm::vec2 designSpace = ViewportSpaceToDesignSpace(viewportSpace);
        touchUpEvent->x = designSpace.x;
        touchUpEvent->y = designSpace.y;
        
        EventManagerPtr eventMgr = StateManager::Get()->GetEventManager();
        eventMgr->TriggetEvent(touchUpEvent);
        */
    }

    void App::TouchMoved (int x, int y)
    {
        /*
        boost::shared_ptr<Fakhir::EventTouchMoved> touchMovedEvent = boost::make_shared<Fakhir::EventTouchMoved>();
        // Adjust coordinates according to new viewport origin
        glm::vec2 viewportSpace(x - _origin.x, y - _origin.y);
        glm::vec2 designSpace = ViewportSpaceToDesignSpace(viewportSpace);
        touchMovedEvent->x = designSpace.x;
        touchMovedEvent->y = designSpace.y;
        
        EventManagerPtr eventMgr = StateManager::Get()->GetEventManager();
        eventMgr->TriggetEvent(touchMovedEvent);
        */
    }

    void App::TouchCancelled (int x, int y)
    {
        //FStateManager::Get()->TouchCancelled(x, y);
    }

    //////////////////////////////////////////////////////////////////////////////////////


    void App::ComputeLetterBoxPolicy ()
    {
        
        // Asset aspect ratio
        float assetAspectRatio  =   float(_assetDesignWidth) / float(_assetDesignHeight);
        
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
        
        _contentScaleFactor = _viewportWidth / _assetDesignWidth;
        //_contentScaleFactor = 1.0f;
        
        // Output message ONLY for testing:
        std::cout   << "DEBUG ==> \nScreen Width: " << _frameBufferWidth
                    << "\nScreen Height: " << _frameBufferHeight
                    << "\nViewport Width: " << _viewportWidth
                    << "\nViewport Height: " << _viewportHeight
                    << "\nSafe Zone x: " << _safeZoneRect.x
                    << "\nSafe Zone y: " << _safeZoneRect.y
                    << "\nSafe Zone Width: " << _safeZoneRect.width
                    << "\nSafe Zone Height: " << _safeZoneRect.height
                    << "\nCSF: " << _contentScaleFactor << std::endl;
        
        
        if(_contentScaleFactor < 0)
        {
            int g = 0.0f;
        }

    }

    //////////////////////////////////////////////////////////////////////////////////////

    Point2D App::DesignSpaceToViewportSpace (const Point2D & designSpace)
    {
        struct BOX
        {
            float l,r,b,t;
        };
        
        Point2D vpSpace;
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

    Point2D App::ViewportSpaceToDesignSpace (const Point2D & vpSpace)
    {
        struct BOX
        {
            float l,r,b,t;
        };
        
        Point2D designSpace;
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
    
    
    /*
     
            THE FOLLOWING TWO FUNCTIONS APPEAR TO BE BUGGY.... PLEASE FIX THEM ASAP.
            They appear to break if device aspect ratio/resolution is NOT equal to design space.
     
     */
    
    Point2D App::DesignSpaceToSafeZone (const Point2D & designSpace)
    {
        struct BOX
        {
            float l,r,b,t;
        };
        
        Point2D safeZone;
        BOX V, D;
        
        V.l = _safeZoneRect.x;
        V.r = _safeZoneRect.width;
        V.b = _safeZoneRect.y;
        V.t = _safeZoneRect.height;
        
        D.l = 0.0f;
        D.r = _designWidth;
        D.b = 0.0f;
        D.t = _designHeight;
        
        safeZone.x = ((V.r - V.l)/(D.r - D.l))*(designSpace.x - D.l) + V.l;
        safeZone.y = ((V.t - V.b)/(D.t - D.b))*(designSpace.y - D.b) + V.b;
        
        return safeZone;

    }
    
    /// BUGGY... PLEASE FIX.....
    
    Point2D App::SafeZoneToDesignSpace (const Point2D & safeZone)
    {
        struct BOX
        {
            float l,r,b,t;
        };
        
        Point2D designSpace;
        BOX V, D;
        
        V.l = _safeZoneRect.x;
        V.r = _safeZoneRect.width;
        V.b = _safeZoneRect.y;
        V.t = _safeZoneRect.height;
        
        D.l = 0.0f;
        D.r = _designWidth;
        D.b = 0.0f;
        D.t = _designHeight;
        
        designSpace.x = ((D.r - D.l)/(V.r - V.l))*(safeZone.x - V.l) + D.l;
        designSpace.y = ((D.t - D.b)/(V.t - V.b))*(safeZone.y - V.b) + D.b;
        
        return designSpace;

    }

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
    
    IOManager * App::GetIOManager ()
    {
        return _ioManager;
    }
    
    IRenderer * App::GetRenderer ()
    {
        return _renderer;
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

    Point2D App::GetOrigin ()
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


};


