//
//  LogAndroid.cpp
//  FEngine
//
//  Created by Fakhir Shaheen on 13/04/2015.
//  Copyright (c) 2015 Fakhir Shaheen. All rights reserved.
//

#include "LogAndroid.h"

#include <android/log.h>

#define  LOG_TAG    "JNIGlue"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO,LOG_TAG,__VA_ARGS__)

using namespace std;

namespace FEngine
{
    
    LogAndroid::LogAndroid ()
    {
        
    }
    
    LogAndroid::~LogAndroid ()
    {
        
    }
    
    void LogAndroid::PrintToConsole (std::string message)
    {
        LOGI(message.c_str());
    }
    
    void LogAndroid::PrintToNetwork  (std::string message)
    {
        // SendToNetwork(message);
    }
}