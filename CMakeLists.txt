PROJECT(TESTING)
CMAKE_MINIMUM_REQUIRED(VERSION 3.6)

SET( GRAPHICS_FILES
        ./Graphics/Point.cpp
        ./Graphics/Pixel.cpp
        ./Graphics/Color.cpp
        ./Graphics/Cursor.cpp
        ./Graphics/EventHandler.h
        ./Graphics/EnviromentDefine.h
        ./Graphics/Enviroment.h
        ./Graphics/Func.h
        ./Graphics/Terminal.cpp
        ./Graphics/Display.cpp
        ./Graphics/IDevice.h
        ./Graphics/keyboard.h
        ./Graphics/Mouse.h
	
)

SET(CMAKE_CXX_STANDARD 11)

ADD_EXECUTABLE( UNIT_TEST
	./UnitTest/main.cpp
	./UnitTest/FunctionTest.h
	./UnitTest/GraphicsTest.h
	./UnitTest/EventHandlerTest.h )

ADD_LIBRARY( GRAPHICS STATIC ${GRAPHICS_FILES} )
TARGET_LINK_LIBRARIES( UNIT_TEST PUBLIC GRAPHICS )
