//
//  DefaultProcesses.h
//  FEngine
//
//  Created by Fakhir Shaheen on 17/03/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#pragma once

#include "Process.h"
#include "../Utility/Math.h"

namespace FEngine
{
    class ProcessDelay : public Process
    {
    public:
        ProcessDelay();
        virtual ~ProcessDelay();
        
        virtual void    Update  (float dt);
        
        float           DELAY;
        
    private:
        float           _elapsed;
    };
    
////////////////////////////////////////////////////////////////////////////////////////////////////////

    class ProcessRotate : public Process
    {
    public:
        ProcessRotate();
        ~ProcessRotate();
        
        virtual void    Update  (float dt);
        
        float           START;
        float           ROTATE_BY;
        float           DURATION;
        SceneNode2D *   node;
        
    private:
        float           _elapsed;
    };

////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    class ProcessTranslate : public Process
    {
    public:
        ProcessTranslate();
        ~ProcessTranslate();
        
        virtual void    Update  (float dt);
        
        Math::Point2D   START;
        Math::Point2D   TRANSLATE_BY;
        float           DURATION;
        SceneNode2D *   node;
        
    private:
        float           _elapsed;
    };

////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    class ProcessScale : public Process
    {
    public:
        ProcessScale();
        ~ProcessScale();
        
        virtual void    Update  (float dt);
        
        Math::Point2D   START;
        Math::Point2D   SCALE_BY;
        float           DURATION;
        SceneNode2D *   node;
        
    private:
        float           _elapsed;
    };

    
////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    class ProcessCallFn : public Process
    {
    public:
        ProcessCallFn();
        ~ProcessCallFn();
        
        virtual void    Update  (float dt);
        
        float           DELAY;
        
        ProcessCallFnDelegate pFn;
        
    private:
        float           _elapsed;
    };

    
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    /*----------------------------------------------------------------------------------------------------
     *----------------------------------------------------------------------------------------------------
     *----------------------------------------------------------------------------------------------------
     *             Gameplay Related Processes...
     *----------------------------------------------------------------------------------------------------
     *----------------------------------------------------------------------------------------------------
     *----------------------------------------------------------------------------------------------------*/

    
        
    
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    
    class ProcessPrint : public Process
    {
    public:
        ProcessPrint();
        virtual ~ProcessPrint();
        
        virtual void    Update  (float dt);
        
    };
    
    
    
}