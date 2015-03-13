cmake_minimum_required(VERSION 2.8)

set ( HDR
		PennerEasing/Back.h
		PennerEasing/Bounce.h
		PennerEasing/Circ.h
		PennerEasing/Cubic.h
		PennerEasing/Elastic.h
		PennerEasing/Expo.h
		PennerEasing/Linear.h
		PennerEasing/Quad.h
		PennerEasing/Quart.h
		PennerEasing/Quint.h
		PennerEasing/Sine.h
	)
	
set ( SRC
		PennerEasing/Back.cpp
		PennerEasing/Bounce.cpp
		PennerEasing/Circ.cpp
		PennerEasing/Cubic.cpp
		PennerEasing/Elastic.cpp
		PennerEasing/Expo.cpp
		PennerEasing/Linear.cpp
		PennerEasing/Quad.cpp
		PennerEasing/Quart.cpp
		PennerEasing/Quint.cpp
		PennerEasing/Sine.cpp
	)

ADD_LIBRARY(PennerEasing STATIC
		${HDR}
		${SRC}
	)