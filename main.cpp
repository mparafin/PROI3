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
    testTable.draw(20, 20, false);
    vector<Shape>* temp = testTable.getShapes();
    (*temp)[0].scale(2);
    testTable.draw(20, 20, false);

    return 0;
}
