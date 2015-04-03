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

LOCAL_MODULE    := libvorbis

LOCAL_CFLAGS    := -Werror

LOCAL_C_INCLUDES :=	jni/../../../GameEngine/3rdParty/libvorbis-1.3.4/include	\
			jni/../../../GameEngine/3rdParty/libvorbis-1.3.4/lib	\
			jni/../../../GameEngine/3rdParty/libogg-1.3.2/include

LOCAL_EXPORT_C_INCLUDES := jni/../../../GameEngine/3rdParty/libvorbis-1.3.4/include


LOCAL_STATIC_LIBRARIES := libogg



LOCAL_SRC_FILES := \
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/analysis.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/barkmel.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/bitrate.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/block.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/codebook.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/envelope.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/floor0.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/floor1.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/info.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/lookup.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/lpc.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/lsp.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/mapping0.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/mdct.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/psy.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/registry.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/res0.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/sharedbook.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/smallft.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/synthesis.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/tone.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/vorbisenc.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/vorbisfile.c		\
	../../../GameEngine/3rdParty/libvorbis-1.3.4/lib/window.c


include $(BUILD_STATIC_LIBRARY)
