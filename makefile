cppfeeder: main.o structure.o
	c++ -Wextra -o cppfeeder main.o structure.o -lX11 -lGL -lpthread -lpng -lstdc++fs
	
structure.o: structure.h structure.cpp
	c++ -Wextra -c -o structure.o -std=c++17 structure.cpp
	
main.o: main.cpp structure.h
	c++ -Wextra -c -o main.o -std=c++17 main.cpp
	
	
