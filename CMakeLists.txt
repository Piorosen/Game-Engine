PROJECT(TESTING)
CMAKE_MINIMUM_REQUIRED(VERSION 3.6)
SET(CMAKE_CXX_STANDARD 11)

# Add Dependecy Library Directory

if(APPLE)
	MESSAGE(STATUS "OS : APPLE")
	set(DIR_GRAPHICS lib/Graphics/macos)	
elseif(WIN32)
	MESSAGE(STATUS "OS : WINDOWS")
	set(DIR_GRAPHICS lib/Graphics/windows)
elseif(UNIX)
	MESSAGE(STATUS "OS : LINUX")
	set(DIR_GRAPHICS lib/Graphics/linux)
else()
	MESSAGE(FATAL_ERROR "your system is not supported")
endif()
MESSAGE(STATUS "Graphics Path : " ${DIR_GRAPHICS})

include_directories(include/Graphics)

file(GLOB_RECURSE LIB_GRAPHICS ${DIR_GRAPHICS}/*.cpp )

ADD_LIBRARY(Graphics STATIC ${LIB_GRAPHICS} lib/Graphics/default)


ADD_EXECUTABLE( UNIT_TEST
	./UnitTest/main.cpp
	./UnitTest/FunctionTest.h
	./UnitTest/GraphicsTest.h
	./UnitTest/EventHandlerTest.h )

target_include_directories(UNIT_TEST PRIVATE .)

TARGET_LINK_LIBRARIES( UNIT_TEST PUBLIC Graphics )
