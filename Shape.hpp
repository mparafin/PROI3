#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__


#include <vector>
#include <iostream>

using namespace std;

struct Point{
    double x, y;
};

class Shape{
    private:
        vector<Point> points;
    public:
        void draw(int size_x, int size_y); //rysuje figurę w kartezjańskim układzie współrzędnych o rozmiarze sizexsize

        void loadData(istream&); //pobiera dane ze strumienia wejściowego istream

        void scale(double ratio); //skaluje figurę o ratio
        void move(double x_offset, double y_offset); //przesuwa figurę o podane wartości na osiach Ox i Oy
        void odbij(); //odbicie lustrzane
};

#endif
