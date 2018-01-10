#include "Shape.hpp"
#include <cmath>
#include <string>

using namespace std;

void Shape::scale(double ratio){
    cout << "scale(" << ratio << ")" << endl;
}

void Shape::move(double x_offset, double y_offset){
    cout << "move(" << x_offset << ", " << y_offset << ")" << endl;
}

void Shape::flipVerticaly(){
    cout << "flipVertically()" << endl;
}

void Shape::flipHorizontally(){
    cout << "flipVertically()" << endl;
}