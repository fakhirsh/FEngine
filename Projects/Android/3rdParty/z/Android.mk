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

LOCAL_MODULE    := libz

LOCAL_CFLAGS    := -Werror

LOCAL_C_INCLUDES :=	jni/../../../GameEngine/3rdParty/zlib-1.2.8

LOCAL_EXPORT_C_INCLUDES := jni/../../../GameEngine/3rdParty/zlib-1.2.8

LOCAL_SRC_FILES :=	../../../GameEngine/3rdParty/zlib-1.2.8/adler32.c	\
			../../../GameEngine/3rdParty/zlib-1.2.8/compress.c	\
			../../../GameEngine/3rdParty/zlib-1.2.8/crc32.c	\
			../../../GameEngine/3rdParty/zlib-1.2.8/deflate.c	\
			../../../GameEngine/3rdParty/zlib-1.2.8/gzclose.c	\
			../../../GameEngine/3rdParty/zlib-1.2.8/gzlib.c	\
			../../../GameEngine/3rdParty/zlib-1.2.8/gzread.c	\
			../../../GameEngine/3rdParty/zlib-1.2.8/gzwrite.c	\
			../../../GameEngine/3rdParty/zlib-1.2.8/infback.c	\
			../../../GameEngine/3rdParty/zlib-1.2.8/inffast.c	\
			../../../GameEngine/3rdParty/zlib-1.2.8/inflate.c	\
			../../../GameEngine/3rdParty/zlib-1.2.8/inftrees.c	\
			../../../GameEngine/3rdParty/zlib-1.2.8/trees.c	\
			../../../GameEngine/3rdParty/zlib-1.2.8/uncompr.c	\
			../../../GameEngine/3rdParty/zlib-1.2.8/zutil.c


include $(BUILD_STATIC_LIBRARY)
