build:
	x86_64-w64-mingw32-g++ -o GeometryDash.exe src/game/main.cpp src/steam/main.cpp stub/steam/main.cpp 3rdparty/cocos/wrapper.cpp -Wall -I.