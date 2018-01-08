CC = g++

PROI3: main.o Shape.o
	$(CC) main.o Shape.o -o PROI3

main.o: main.cpp Shape.hpp
	$(CC) -c main.cpp

Shape.o: Shape.hpp Shape.cpp
	$(CC) -c -std=c++11 Shape.cpp