#include <iostream>
#include <fstream>
#include "Shape.hpp"
#include "Table.hpp"

using namespace std;


int main(){
    Table testTable;
    try{
        testTable.addShape("plik.txt");
    }
    catch(...){
        cout << "Shit!" << endl;
        return 1;
    }
    testTable.draw(100, 20);

    return 0;
}
