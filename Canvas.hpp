#ifndef __CANVAS_HPP__
#define __CANVAS_HPP__

#include <vector>
#include "Shape.hpp"


class Canvas{
    private:
        std::vector<Shape> shapes;
    public:
        std::vector<Shape>* getShapes() { return &shapes; }
        void draw(int size_x, int size_y, bool scaled); //rysuje wszystkie figury na kartezjańskim układzie współrzędnych o rozmiarze sizexsize
        void addShape(const char* filename); // dodaje nowy kształt do tablicy, wczytując jego dane z pliku
        void clear() { shapes.clear(); } // czyści tablicę (usuwa wszystkie kształty)
};

#endif