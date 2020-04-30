set(PROGRAM_NAME "UNIT_TEST")

PROJECT(${PROGRAM_NAME})
CMAKE_MINIMUM_REQUIRED(VERSION 3.6)
SET(CMAKE_CXX_STANDARD 11)

# Add Dependecy Library Directory

if(APPLE)
	MESSAGE(STATUS "OS : APPLE")
	set(OS macos)
elseif(WIN32)
	MESSAGE(STATUS "OS : WINDOWS")
	set(OS windows)
elseif(UNIX)
	MESSAGE(STATUS "OS : LINUX")
	set(OS linux)
else()
	MESSAGE(FATAL_ERROR "your system is not supported")
endif()
set(DIR_GRAPHICS lib/Graphics)

MESSAGE(STATUS "Graphics Path : " ${DIR_GRAPHICS}/${OS})

include_directories(include/Graphics)
file(GLOB_RECURSE LIB_GRAPHICS ${DIR_GRAPHICS}/${OS}/*.cpp ${DIR_GRAPHICS}/default/*.cpp)
ADD_LIBRARY(Graphics STATIC  ${LIB_GRAPHICS} )


ADD_EXECUTABLE(${PROGRAM_NAME}
	./UnitTest/main.cpp
	./UnitTest/FunctionTest.h
	./UnitTest/GraphicsTest.h
	./UnitTest/EventHandlerTest.h )

TARGET_LINK_LIBRARIES(${PROGRAM_NAME} PUBLIC Graphics )
