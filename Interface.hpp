#include <vector>

struct Canvas;
struct Shape;

class Interface{
    public:
        Interface();
        ~Interface();

        bool menu(std::vector<Canvas>&); //główne menu programu
        void showCanvasList(std::vector<Canvas>&); //wypisuje listę wszystkich tablic (miniaturki)
        void addCanvas(std::vector<Canvas>&); //dodaje nową, pustą tablicę
        void drawOneCanvas(std::vector<Canvas>&); //rysuje jedną tablicę
        void drawAllCanvases(std::vector<Canvas>&); //rysuje wszystkie tablice
        bool modifyCanvas(Canvas&); //przechodzi w tryb modyfikacji wybranej tablicy
        
        //funkcje wewnętrzne modifyCanvas
        void showCanvasShapes(Canvas&); //wypisuje listę wszystkich kształtów modyfikowanej tablicy
        void addShapeToCanvas(Canvas&); //dodaje kształt z pliku do modyfikowanej tablicy
        void modifyShape(Canvas&); //modyfikuje wybrany kształt modyfikowanej tablicy
        void removeShape(Canvas&); //usuwa wybrany kształt modyfikowanej tablicy
        void clearCanvas(Canvas&); //czyści modyfikowaną tablicę
        
        //funkcje pomocnicze
        int chooseCanvas(std::vector<Canvas>& allCanvases); //funkcja, która pobiera od użytkownika numer wybranej tablicy. Zwraca -1, jeśli użytkownik chce wyjść
        int chooseShape(Canvas&); //funkcja, która pobiera od użytkownika numer wybranego kształtu danej tablicy. Zwraca -1, jeśli użytkownik chce wyjść
        void drawShape(Shape&); // rysuje miniaturkę pojedynczego kształtu
};