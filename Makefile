CC = g++

PROI3: main.o Shape.o Canvas.o Interface.o
	$(CC) main.o Shape.o Canvas.o Interface.o -o PROI3

main.o: main.cpp Shape.hpp Canvas.hpp Interface.hpp
	$(CC) -c -std=c++11 main.cpp

Shape.o: Shape.hpp Shape.cpp
	$(CC) -c -std=c++11 Shape.cpp

Canvas.o: Canvas.hpp Canvas.cpp
	$(CC) -c -std=c++11 Canvas.cpp

Interface.o: Interface.hpp Interface.cpp
	$(CC) -c -std=c++11 Interface.cpp

clean:
	rm *.o