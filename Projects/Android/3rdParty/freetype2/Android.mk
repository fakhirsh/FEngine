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

##########################################

##########################################

include $(CLEAR_VARS)

#FREETYPE_SRC_PATH := ../../../3rdParty/freetype-2.5.4
FREETYPE_SRC_PATH := ../../../3rdParty/freetype2-android-master

LOCAL_MODULE    := freetype2


LOCAL_CFLAGS   := -Werror -DANDROID_NDK -DFT2_BUILD_LIBRARY=1


LOCAL_C_INCLUDES :=	jni/../../../3rdParty/freetype2-android-master/include	\
			jni/../../../3rdParty/freetype2-android-master/src

LOCAL_EXPORT_C_INCLUDES := jni/../../../3rdParty/freetype2-android-master/include

LOCAL_SRC_FILES :=	$(FREETYPE_SRC_PATH)/src/autofit/autofit.c \
			$(FREETYPE_SRC_PATH)/src/base/basepic.c \
			$(FREETYPE_SRC_PATH)/src/base/ftapi.c \
			$(FREETYPE_SRC_PATH)/src/base/ftbase.c \
			$(FREETYPE_SRC_PATH)/src/base/ftbbox.c \
			$(FREETYPE_SRC_PATH)/src/base/ftbitmap.c \
			$(FREETYPE_SRC_PATH)/src/base/ftdbgmem.c \
			$(FREETYPE_SRC_PATH)/src/base/ftdebug.c \
			$(FREETYPE_SRC_PATH)/src/base/ftglyph.c \
			$(FREETYPE_SRC_PATH)/src/base/ftinit.c \
			$(FREETYPE_SRC_PATH)/src/base/ftpic.c \
			$(FREETYPE_SRC_PATH)/src/base/ftstroke.c \
			$(FREETYPE_SRC_PATH)/src/base/ftsynth.c \
			$(FREETYPE_SRC_PATH)/src/base/ftsystem.c \
			$(FREETYPE_SRC_PATH)/src/cff/cff.c \
			$(FREETYPE_SRC_PATH)/src/pshinter/pshinter.c \
			$(FREETYPE_SRC_PATH)/src/psnames/psnames.c \
			$(FREETYPE_SRC_PATH)/src/raster/raster.c \
			$(FREETYPE_SRC_PATH)/src/sfnt/sfnt.c \
			$(FREETYPE_SRC_PATH)/src/smooth/smooth.c \
			$(FREETYPE_SRC_PATH)/src/truetype/truetype.c

#LOCAL_LDLIBS := -ldl -llog

include $(BUILD_STATIC_LIBRARY)
