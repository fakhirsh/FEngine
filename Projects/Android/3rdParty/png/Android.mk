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


include $(CLEAR_VARS)

LOCAL_MODULE    := libpng

LOCAL_CFLAGS    := -Werror

LOCAL_C_INCLUDES :=		jni/../../../GameEngine/3rdParty/libpng-1.6.15		

LOCAL_EXPORT_C_INCLUDES := 	jni/../../../GameEngine/3rdParty/libpng-1.6.15

LOCAL_STATIC_LIBRARIES := libz


LOCAL_SRC_FILES :=	../../../GameEngine/3rdParty/libpng-1.6.15/png.c	\
			../../../GameEngine/3rdParty/libpng-1.6.15/pngerror.c	\
			../../../GameEngine/3rdParty/libpng-1.6.15/pngget.c	\
			../../../GameEngine/3rdParty/libpng-1.6.15/pngmem.c	\
			../../../GameEngine/3rdParty/libpng-1.6.15/pngpread.c	\
			../../../GameEngine/3rdParty/libpng-1.6.15/pngread.c	\
			../../../GameEngine/3rdParty/libpng-1.6.15/pngrio.c	\
			../../../GameEngine/3rdParty/libpng-1.6.15/pngrtran.c	\
			../../../GameEngine/3rdParty/libpng-1.6.15/pngrutil.c	\
			../../../GameEngine/3rdParty/libpng-1.6.15/pngset.c	\
			../../../GameEngine/3rdParty/libpng-1.6.15/pngtest.c	\
			../../../GameEngine/3rdParty/libpng-1.6.15/pngtrans.c	\
			../../../GameEngine/3rdParty/libpng-1.6.15/pngwio.c	\
			../../../GameEngine/3rdParty/libpng-1.6.15/pngwrite.c	\
			../../../GameEngine/3rdParty/libpng-1.6.15/pngwtran.c	\
			../../../GameEngine/3rdParty/libpng-1.6.15/pngwutil.c	


include $(BUILD_STATIC_LIBRARY)
