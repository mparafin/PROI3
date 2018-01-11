#include <iostream>
#include <fstream>
#include "Shape.hpp"
#include "Table.hpp"

using namespace std;


int main(){
    Table testTable;
    try{
        testTable.addShape("plik.txt");
        testTable.addShape("ramka.txt");
    }
    catch(...){
        cout << "Shit!" << endl;
        return 1;
    }
    testTable.draw(20, 20);
    vector<Shape>* temp = testTable.getShapes();
    (*temp)[0].flipHorizontally();
    testTable.draw(20, 20);

    return 0;
}
