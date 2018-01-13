#include <iostream>
#include <fstream>
#include <vector>
#include "Shape.hpp"
#include "Canvas.hpp"
#include "Interface.hpp"

using namespace std;


int main(){
    //inicjalizacja programu
    Interface program; //inicjalizacja interfejsu
    vector<Canvas> allCanvases; //stworzenie wektora przechowującego wszystkie tablice
    Canvas defaultCanvas; //stworzenie domyślnej tablicy
    defaultCanvas.addShape("plik.txt");
    allCanvases.push_back(defaultCanvas); //dodanie jej do wektora

    //pętla programu
    while( program.menu(allCanvases) );

    //vector<Shape>* temp = defaultCanvas.getShapes();
    //(*temp)[0].scale(2);

    return 0;
}
