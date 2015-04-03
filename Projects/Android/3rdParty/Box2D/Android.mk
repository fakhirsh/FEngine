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

LOCAL_MODULE    := libBox2D

LOCAL_CFLAGS    := -Werror

LOCAL_C_INCLUDES :=	jni/../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D
			
LOCAL_EXPORT_C_INCLUDES := jni/../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D


LOCAL_SRC_FILES :=	../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Collision/b2BroadPhase.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Collision/b2CollideCircle.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Collision/b2CollideEdge.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Collision/b2CollidePolygon.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Collision/b2Collision.cpp		\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Collision/b2Distance.cpp		\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Collision/b2DynamicTree.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Collision/b2TimeOfImpact.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Collision/Shapes/b2ChainShape.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Collision/Shapes/b2CircleShape.cpp \
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Collision/Shapes/b2EdgeShape.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Collision/Shapes/b2PolygonShape.cpp \
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Common/b2BlockAllocator.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Common/b2Draw.cpp			\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Common/b2Math.cpp			\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Common/b2Settings.cpp		\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Common/b2StackAllocator.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Common/b2Timer.cpp		\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/b2Body.cpp		\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/b2ContactManager.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/b2Fixture.cpp		\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/b2Island.cpp		\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/b2World.cpp		\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/b2WorldCallbacks.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Contacts/b2ChainAndCircleContact.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Contacts/b2ChainAndPolygonContact.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Contacts/b2CircleContact.cpp		\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Contacts/b2Contact.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Contacts/b2ContactSolver.cpp		\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Contacts/b2EdgeAndCircleContact.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Contacts/b2EdgeAndPolygonContact.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Contacts/b2PolygonAndCircleContact.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Contacts/b2PolygonContact.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Joints/b2DistanceJoint.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Joints/b2FrictionJoint.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Joints/b2GearJoint.cpp		\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Joints/b2Joint.cpp		\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Joints/b2MotorJoint.cpp		\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Joints/b2MouseJoint.cpp		\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Joints/b2PrismaticJoint.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Joints/b2PulleyJoint.cpp		\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Joints/b2RevoluteJoint.cpp	\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Joints/b2RopeJoint.cpp		\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Joints/b2WeldJoint.cpp		\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Dynamics/Joints/b2WheelJoint.cpp		\
			../../../GameEngine/3rdParty/Box2D_v2.3.0/Box2D/Box2D/Rope/b2Rope.cpp


include $(BUILD_STATIC_LIBRARY)
