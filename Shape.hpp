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
        char color;
    public:
        Shape() { this->color = '+'; }

        char getColor(){ return color; }
        vector<Point> getPoints(){ return points; }
        void addPoint(Point& new_point) { points.push_back(new_point); }

        void scale(double ratio); //skaluje figurę o ratio
        void move(double x_offset, double y_offset); //przesuwa figurę o podane wartości na osiach Ox i Oy
        void flipVertically(); //odbicie lustrzane w pionie względem osi poziomej przechodzącej przez środek figury
        void flipHorizontally(); //odbicie lustrzane w poziomie względem osi pionowej przechodzącej przez środek figury
        void colorChange(char new_color) { color = new_color; } //zmienia "kolor", czyli znak graficzny rysowanych punktów
};

#endif
