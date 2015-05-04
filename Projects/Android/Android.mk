# Copyright (C) 2009 The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

################################################################

include jni/../../../GameEngine/Projects/Android/3rdParty/png/Android.mk
include jni/../../../GameEngine/Projects/Android/3rdParty/z/Android.mk
include jni/../../../GameEngine/Projects/Android/3rdParty/tinyxml2/Android.mk
include jni/../../../GameEngine/Projects/Android/3rdParty/PennerEasing/Android.mk
include jni/../../../GameEngine/Projects/Android/3rdParty/Box2D/Android.mk
include jni/../../../GameEngine/Projects/Android/3rdParty/OpenAL-soft/Android.mk
include jni/../../../GameEngine/Projects/Android/3rdParty/vorbis/Android.mk
include jni/../../../GameEngine/Projects/Android/3rdParty/ogg/Android.mk
include jni/../../../GameEngine/Projects/Android/3rdParty/RectangleBinPack/Android.mk

#include jni/../../../GameEngine/Projects/Android/3rdParty/freetype2/Android.mk

################################################################

include $(CLEAR_VARS)

LOCAL_MODULE    := libFEngine

LOCAL_CFLAGS    := -Werror
#LOCAL_LDLIBS	:= -llog -lGLESv2 -landroid

LOCAL_C_INCLUDES :=	jni/../../../GameEngine	\
			jni/../../../		\
			jni/../../../GameEngine/3rdParty/FastDelegate	\
			jni/../../../GameEngine/3rdParty/boost_1_56_0	\
			jni/../../../GameEngine/3rdParty/glm-0.9.6.3

LOCAL_EXPORT_C_INCLUDES := jni/../../../GameEngine

LOCAL_STATIC_LIBRARIES := 	libpng		\
				libtinyxml2	\
				libPennerEasing	\
				libBox2D	\
				openal		\
				libvorbis	\
				libRectangleBinPacking
			

LOCAL_SRC_FILES := 	../../../GameEngine/FEngine/System/App.cpp		\
			../../../GameEngine/FEngine/System/SystemConfig.cpp	\
			../../../GameEngine/FEngine/2D/DebugBoxNode2D.cpp	\
			../../../GameEngine/FEngine/2D/DebugCircleNode2D.cpp	\
			../../../GameEngine/FEngine/2D/RootSceneNode2D.cpp	\
			../../../GameEngine/FEngine/2D/SceneNode2D.cpp		\
			../../../GameEngine/FEngine/2D/SceneNodeProperties2D.cpp	\
			../../../GameEngine/FEngine/2D/SpriteNode.cpp		\
			../../../GameEngine/FEngine/2D/ViewNode.cpp		\
			../../../GameEngine/FEngine/2D/Texture.cpp		\
			../../../GameEngine/FEngine/2D/TextureAtlas.cpp		\
			../../../GameEngine/FEngine/ActorManager/Actor.cpp	\
			../../../GameEngine/FEngine/ActorManager/ActorComponent.cpp	\
			../../../GameEngine/FEngine/ActorManager/ActorManager.cpp	\
			../../../GameEngine/FEngine/ActorManager/Components/InputComponent.cpp		\
			../../../GameEngine/FEngine/ActorManager/Components/PhysicsComponent.cpp	\
			../../../GameEngine/FEngine/ActorManager/Components/TransformComponent.cpp	\
			../../../GameEngine/FEngine/ActorManager/Components/ViewComponent.cpp		\
			../../../GameEngine/FEngine/EventDispatcher/DefaultEvents.cpp		\
			../../../GameEngine/FEngine/EventDispatcher/Event.cpp			\
			../../../GameEngine/FEngine/EventDispatcher/EventDispatcher.cpp		\
			../../../GameEngine/FEngine/MemoryManager/ActorPool.cpp			\
			../../../GameEngine/FEngine/MemoryManager/MemoryManager.cpp		\
			../../../GameEngine/FEngine/Monetize/Ads/AdsStub.cpp			\
			../../../GameEngine/FEngine/Monetize/Ads/ChartBoostAdsAndroid.cpp	\
			../../../GameEngine/FEngine/PhysicsManager/PhysicsManager.cpp		\
			../../../GameEngine/FEngine/ProcessScheduler/DefaultProcesses.cpp	\
			../../../GameEngine/FEngine/ProcessScheduler/Process.cpp		\
			../../../GameEngine/FEngine/ProcessScheduler/ProcessScheduler.cpp	\
			../../../GameEngine/FEngine/Renderer/GLES20/Program.cpp			\
			../../../GameEngine/FEngine/Renderer/GLES20/SimpleVertex2DProgram.cpp	\
			../../../GameEngine/FEngine/Renderer/GLES20/TexturedVertexProgram.cpp	\
			../../../GameEngine/FEngine/ResourceCache/IOManagerAndroid.cpp		\
			../../../GameEngine/FEngine/ResourceCache/IOManagerDefault.cpp		\
			../../../GameEngine/FEngine/ResourceCache/ResourceCache.cpp		\
			../../../GameEngine/FEngine/ResourceCache/Factories/ActorFactory.cpp	\
			../../../GameEngine/FEngine/ResourceCache/Factories/PhysicsFactory.cpp	\
			../../../GameEngine/FEngine/ResourceCache/Factories/ProgramFactory.cpp	\
			../../../GameEngine/FEngine/ResourceCache/Factories/SpriteNodeFactory.cpp	\
			../../../GameEngine/FEngine/ResourceCache/Factories/TextureAtlasFactory.cpp	\
			../../../GameEngine/FEngine/ResourceCache/Factories/View2DFactory.cpp	\
			../../../GameEngine/FEngine/StateManager/State.cpp			\
			../../../GameEngine/FEngine/StateManager/StateManager.cpp		\
			../../../GameEngine/FEngine/SoundManager/SoundManager.cpp		\
			../../../GameEngine/FEngine/Utility/Math.cpp				\
			../../../GameEngine/FEngine/Utility/String.cpp				\
			../../../GameEngine/FEngine/Debugging/Log.cpp				\
			../../../GameEngine/FEngine/Debugging/LogDefault.cpp			\
			../../../GameEngine/FEngine/Debugging/LogAndroid.cpp			\
			../../../GameEngine/FEngine/Debugging/LogStub.cpp			\
			../../../GameEngine/FEngine/Social/Facebook.cpp				\
			../../../GameEngine/FEngine/Social/FacebookAndroid.cpp			\
			../../../GameEngine/FEngine/Social/FacebookStub.cpp			\
			../../../GameEngine/FEngine/Social/BasicShareAndroid.cpp		\
			../../../GameEngine/FEngine/Serialize/SerializeAndroid.cpp		\
			../../../GameEngine/FEngine/Serialize/SerializeStub.cpp

include $(BUILD_STATIC_LIBRARY)
