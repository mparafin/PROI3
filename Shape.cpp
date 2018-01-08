#include "Shape.hpp"
#include <cmath>
#include <string>

using namespace std;

void Shape::draw(int size_x, int size_y){
    char** table = new char* [size_x+1];
    for(int i=0; i<size_x+1; i++) {
        table[i] = new char [size_y+1];
        for(int j=0; j<size_y+1; j++) table[i][j] = ' ';
    } //stworzenie tablicy buforowej, na której rysowany będzie układ i figura oraz wypełnienie tej tablicy spacjami


    //rysowanie układu współrzędnych
    table[size_x][size_y/2] = '>';
    for(int i=0; i<size_x; i++) table[i][size_y/2] = '-'; // pozioma oś układu
    table[size_x/2][size_y] = '^';
    for(int i=0; i<size_y; i++) table[size_x/2][i] = '|'; //pionowa oś układu

    //uzyskanie maksymalnych wartości x i y punktów danej figury
    double maxX=0, maxY=0;
    for(int i=0; i<points.size(); i++){
        if(abs(points[i].x) > maxX) maxX = abs(points[i].x);
        if(abs(points[i].y) > maxY) maxY = abs(points[i].y);
    }

    double x_scale = (size_x/2)/maxX;
    double y_scale = (size_y/2)/maxY;

    for(int i=0; i<points.size(); i++){
        int x = round( points[i].x * x_scale ) + size_x/2;
        int y = round( points[i].y * y_scale ) + size_y/2;
        table[x][y] = '+';
    }

    
    //wypisanie tablicy na główne wyjście
    for(int i=0; i<size_x/2; i++) cout << ' ';
    cout << maxY << endl;
    for(int j=size_y; j>=0; j--){
        for(int i=0; i<size_x+1; i++) cout << table[i][j];
        if(j == size_y/2) cout << " " << maxX;
        cout << "\n";
    }

}

double getDouble(istream& input){
    string buffer;
    input >> buffer;
    size_t number = buffer.find_first_of("1234567890.-");
    buffer = buffer.substr(number);
    return stod(buffer);
}


void Shape::loadData(istream& source){
    int number_of_points=-1;
    string buffer;   
    try{
        source >> buffer;
        size_t number = buffer.find_first_of("1234567890");
        if(number == string::npos) throw "Check input file validity! (no number of points found)";
        buffer = buffer.substr(number);
        number_of_points = stoi(buffer);
        if(number_of_points == 0) throw "Check input file validity! (number of points cannot equal 0)";
    }
    catch(char const* message){
        cout << message << endl;
        throw;
    }

    for(int i=0; i<number_of_points; i++){
        Point temp;
        try{
            temp.x = getDouble(source);
        }
        catch(...){
            cout << "Check input file validity! (Argument x of point" << i+1 << ")" << endl;
        }
        cout << "Point" << i << ": (" <<temp.x << ", ";
        try{
            temp.y = getDouble(source);
        }
        catch(...){
            cout << "Check input file validity! (Argument y of point" << i+1 << ")" << endl;
        }
        cout << temp.y << ")" <<endl;
        points.push_back(temp);
    }
}

void Shape::scale(double ratio){
    cout << "scale(" << ratio << ")" << endl;
}

void Shape::move(double x_offset, double y_offset){
    cout << "move(" << x_offset << ", " << y_offset << ")" << endl;
}