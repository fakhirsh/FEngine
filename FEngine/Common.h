//
//  Common.h
//  WordGame
//
//  Created by Fakhir Shaheen on 28/10/2014.
//  Copyright (c) 2014 Fakhir Shaheen. All rights reserved.
//

#pragma once

#define GLM_FORCE_RADIANS

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform2.hpp>

#include <tinyxml2.h>

#include <FastDelegate.h>
#include <boost/smart_ptr/shared_ptr.hpp>
#include <boost/smart_ptr/make_shared.hpp>
#include <boost/smart_ptr/weak_ptr.hpp>


#include <png.h>

#include <vector>
#include <string>
#include <map>
#include <list>
#include <iostream>
#include <fstream>
#include <sstream>


#ifdef __APPLE__
#include <OpenGLES/ES2/gl.h>
#include <OpenAL/al.h>
#include <OpenAL/alc.h>
#else
#include <GLES2/gl2.h>
#include <AL/al.h>
#include <AL/alc.h>
#endif


#define STRINGIFY(A) #A


