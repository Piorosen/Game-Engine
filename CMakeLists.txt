PROJECT(UnitTest)
CMAKE_MINIMUM_REQUIRED(VERSION 3.6)

SET( GRAPHICS_FILES
	./Graphics/Graphics.cpp
	./Graphics/Color.cpp
	./Graphics/Cursor.cpp
	./Graphics/Display.cpp
	./Graphics/Enviroment.h
	./Graphics/EventHandler.cpp
	./Graphics/Func.h
	./Graphics/IDevice.h
	./Graphics/Keyboard.h
	./Graphics/Mouse.h
	./Graphics/Pixel.cpp
	./Graphics/Point.cpp
	./Graphics/Terminal.cpp )

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE( main 
	./UnitTest/main.cpp
	./UnitTest/FunctionTest.h
	./UnitTest/GraphicsTest.h
	./UnitTest/EventHandlerTest.h )

ADD_LIBRARY( graphics STATIC ${GRAPHICS_FILES} )
TARGET_LINK_LIBRARIES( main PUBLIC graphics )
