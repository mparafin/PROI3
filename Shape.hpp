#include <vector>
#include <iostream>

using namespace std;

template <typename T>
struct Point{
    T x, y;
};

template <typename T>
class Shape{
    private:
        vector<Point<T> > points;
    public:
        void draw(); //rysuje figurę

        void loadData(istream&);

        void scale(T); //skaluje figurę
        void move(T, T); //przesuwa figurę
        //void transform(<wektor1>, <wektor2>);
};

template<typename T>
void Shape<T>::draw(){
    cout << "draw()" << endl;
}

template<typename T>
void Shape<T>::loadData(istream& source){
    string buffer;
    source >> buffer;
    cout << buffer << endl;
}

template<typename T>
void Shape<T>::scale(T ratio){
    cout << "scale(" << ratio << ")" << endl;
}

template<typename T>
void Shape<T>::move(T x_offset, T y_offset){
    cout << "move(" << x_offset << ", " << y_offset << ")" << endl;
}