cmake_minimum_required(VERSION 2.8)


set ( HDR

	)
	
set ( SRC
		tinyxml2.cpp
	)

ADD_LIBRARY(tinyxml2 STATIC
		${HDR}
		${SRC}
	)