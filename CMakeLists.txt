PROJECT(TESTING)
CMAKE_MINIMUM_REQUIRED(VERSION 3.6)
SET(CMAKE_CXX_STANDARD 11)

# Add Dependecy Library Directory

if(APPLE)
	set(DIR_GRAPHICS lib/graphics/macos)
elseif(WIN32)
	set(DIR_GRAPHICS lib/graphics/windows)
elseif(UNIX)
	set(DIR_GRAPHICS lib/graphics/linux)
else()
	MESSAGE(FATAL_ERROR "your system is not supported")
endif()
file(GLOB_RECURSE LIB_GRAPHICS ${DIR_GRAPHICS}/*.cpp)

ADD_LIBRARY(Graphics STATIC ${LIB_GRAPHICS})


ADD_EXECUTABLE( UNIT_TEST
	./UnitTest/main.cpp
	./UnitTest/FunctionTest.h
	./UnitTest/GraphicsTest.h
	./UnitTest/EventHandlerTest.h )

TARGET_LINK_LIBRARIES( UNIT_TEST PUBLIC Graphics )
