PROJECT(Graphics)
CMAKE_MINIMUM_REQUIRED(VERSION 3.6)
MESSAGE(${CMAKE_PROJECT_NAME})

SET( SRC_FILES
	Point.cpp
	Pixel.cpp
	Color.cpp
	Cursor.cpp
	EventHandler.cpp
	EnviromentDefine.h
	Enviroment.h
	Func.cpp
	Terminal.cpp
	Display.cpp
	IDevice.h
	keyboard.h
	Mouse.h
)

SET(CMAKE_CXX_STANDARD 11)

ADD_LIBRARY(Graphics STATIC ${SRC_FILES})


