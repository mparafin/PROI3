CC = g++

PROI3: main.o Shape.o Canvas.o
	$(CC) main.o Shape.o Canvas.o -o PROI3

main.o: main.cpp Shape.hpp Canvas.hpp
	$(CC) -c -std=c++11 main.cpp

Shape.o: Shape.hpp Shape.cpp
	$(CC) -c -std=c++11 Shape.cpp

Canvas.o: Canvas.hpp Canvas.cpp
	$(CC) -c -std=c++11 Canvas.cpp
clean:
	rm *.o