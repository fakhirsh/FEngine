cmake_minimum_required(VERSION 2.8)

# Set include directories
include_directories(../libogg-1.3.2/include)
include_directories(include)
include_directories(lib)

# Add library subdirectories
add_subdirectory(../libogg-1.3.2 ${CMAKE_BINARY_DIR}/libogg)


ADD_LIBRARY(vorbis STATIC
		lib/analysis.c
		lib/barkmel.c
		lib/block.c
		lib/bitrate.c
		lib/codebook.c
		lib/envelope.c
		lib/floor0.c
		lib/floor1.c
		lib/info.c
		lib/lookup.c
		lib/lpc.c
		lib/lsp.c
		lib/mapping0.c
		lib/mdct.c
		lib/psy.c
		lib/registry.c
		lib/res0.c
		lib/sharedbook.c
		lib/smallft.c
		lib/synthesis.c
		lib/tone.c
		lib/vorbisenc.c
		lib/vorbisfile.c
		lib/window.c
	)

target_link_libraries( vorbis 
			ogg
			  )