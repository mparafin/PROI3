#include <iostream>
#include <fstream>
#include "Shape.hpp"

using namespace std;


int main(){
    Shape testShape;
    ifstream input("plik.txt");
    try{
        testShape.loadData(input);
    }
    catch(...){
        cout << "Shit!" << endl;
        return 1;
    }
    testShape.draw(100, 100);
    //getDouble(input);
    return 0;
}
