PROJECT(Graphics)
CMAKE_MINIMUM_REQUIRED(VERSION 3.6)
MESSAGE(${CMAKE_PROJECT_NAME})

SET( SRC_FILES Graphics.cpp Color.cpp Cursor.cpp Display.cpp Enviroment.h EventHandler.cpp Func.h IDevice.h Keyboard.h Mouse.h Pixel.cpp Point.cpp Terminal.cpp )

SET(CMAKE_CXX_STANDARD 11)

ADD_LIBRARY(Graphics STATIC ${SRC_FILES})

