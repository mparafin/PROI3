CC = g++

PROI3: main.o Shape.o Table.o
	$(CC) main.o Shape.o Table.o -o PROI3

main.o: main.cpp Shape.hpp Table.hpp
	$(CC) -c -std=c++11 main.cpp

Shape.o: Shape.hpp Shape.cpp
	$(CC) -c -std=c++11 Shape.cpp

Table.o: Table.hpp Table.cpp
	$(CC) -c -std=c++11 Table.cpp
clean:
	rm *.o