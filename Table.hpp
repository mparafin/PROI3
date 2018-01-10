#ifndef __TABLE_HPP__
#define __TABLE_HPP__

#include <vector>

struct Shape;

class Table{
    private:
        std::vector<Shape> shapes;
    public:
        void draw(int size_x, int size_y); //rysuje wszystkie figury na kartezjańskim układzie współrzędnych o rozmiarze sizexsize
        void addShape(const char* filename); // dodaje nowy kształt do tablicy, wczytując jego dane z pliku
        void clear(); // czyści tablicę (usuwa wszystkie kształty)
};

#endif