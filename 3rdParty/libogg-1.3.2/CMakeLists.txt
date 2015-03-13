cmake_minimum_required(VERSION 2.8)

include_directories(include)

set ( HDR

	)
	
set ( SRC
		src/bitwise.c
		src/framing.c
	)

ADD_LIBRARY(ogg STATIC
		${HDR}
		${SRC}
	)