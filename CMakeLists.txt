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
	file(GLOB HEADER_GRAPHICS include/Graphics/*.h include/Graphics/Shape/*.h)
	file(GLOB HEADER_EXAMPLE Example/UnitTest/*.h)
	
	#source_group("HeaderGraphics", FILES ${HEADER_GRAPHICS})
	#source_group("HeaderExample", FILES ${HEADER_EXAMPLE})
	MESSAGE(STATUS ${HEADER_GRAPHICS})

	set(OS windows)
elseif(UNIX)
	MESSAGE(STATUS "OS : LINUX")
	set(OS linux)
else()
	MESSAGE(FATAL_ERROR "your system is not supported")
endif()

set(DIR_GRAPHICS lib/${OS}/Graphics)

MESSAGE(STATUS "Graphics Path : " ${DIR_GRAPHICS})

include_directories(include/Graphics)
file(GLOB_RECURSE LIB_GRAPHICS ${DIR_GRAPHICS}/*.cpp)
ADD_LIBRARY(Graphics STATIC  ${LIB_GRAPHICS} ${HEADER_GRAPHICS})


ADD_EXECUTABLE(${PROGRAM_NAME}
	./Example/main.cpp
	${HEADER_EXAMPLE}
	)

TARGET_LINK_LIBRARIES(${PROGRAM_NAME} PUBLIC Graphics )
