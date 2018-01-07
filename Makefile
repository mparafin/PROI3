CC = g++

PROI3: main.o
	$(CC) main.o -o PROI3

main.o: main.cpp Shape.hpp
	$(CC) -c main.cpp
