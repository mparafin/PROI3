#include <iostream>
#include <vector>
#include <string>

#include "Shape.hpp"
#include "Canvas.hpp"
#include "Interface.hpp"

using namespace std;


Interface::Interface(){
    cout << "PROI3 - Prosty edytor graficzny\nAutor: Michał Parafiniuk, Copyright: Politechnika Warszawska\n" << endl;    
}

Interface::~Interface(){
    cout << "Dziękujemy za skorzystanie z programu, zapraszamy ponownie!" << endl;
}

int Interface::chooseCanvas(vector<Canvas>& allCanvases){ //funkcja, która pobiera od użytkownika numer wybranej tablicy
    string buffer;
    int input = 0;
    while(1){
        try{
            getline(cin, buffer);
            if(buffer.size() == 0) throw 0;
            size_t number_pos = buffer.find_first_of("1234567890");
            if(number_pos == string::npos) throw "Wybierz jedną z istniejących tablic: ";
            buffer = buffer.substr(number_pos);
            input = stoi(buffer);
            if(input < 0 || input > allCanvases.size()) throw "Wybierz jedną z dostępnych opcji!\n";
        }
        catch(char const* message){
            cout << message;
            continue;
        }
        catch(int){ return -1; }
        break;
    }
    return input - 1;
}

int Interface::chooseShape(Canvas& canvas){
    string buffer;
    int input = 0;
    vector<Shape>* allShapesPointer = canvas.getShapes();
    while(1){
        try{
            getline(cin, buffer);
            if(buffer.size() == 0) throw 0;
            size_t number_pos = buffer.find_first_of("1234567890");
            if(number_pos == string::npos) throw "Wybierz jeden z istniejących kształtów: ";
            buffer = buffer.substr(number_pos);
            input = stoi(buffer);
            if(input < 0 || input > allShapesPointer->size()) throw "Wybierz jedną z dostępnych opcji!\n";
        }
        catch(char const* message){
            cout << message;
            continue;
        }
        catch(int){ return -1; }
        break;
    }
    return input - 1;
}


bool Interface::menu(vector<Canvas>& allCanvases){
    cout << "[MENU GŁÓWNE] Wybierz jedną spośród poniższych opcji:\n1. Pokaż listę wszystkich tablic.\n2. Dodaj nową tablicę.\n3. Narysuj wszystkie tablice.\n4. Narysuj jedną tablicę.\n5. Edytuj jedną tablicę.\n6. Usuń jedną z tablic.\n0. Wyjdź z programu." << endl;
    int input = 0;
    while(1){
        try{
            string buffer;
            getline(cin, buffer);
            if(buffer.size() == 0) throw "Podaj numer od 0 do 6: ";
            size_t number_pos = buffer.find_first_of("1234567890");
            if(number_pos == string::npos) throw "Podaj numer od 0 do 6: ";
            buffer = buffer.substr(number_pos);
            input = stoi(buffer);
            if(input < 0 || input > 6) throw "Wybierz jedną z dostępnych opcji!\n";
        }
        catch(char const* message){
            cout << message;
            continue;
        }
        catch(...){
            cout << "Coś poszło nie tak, spróbuj jeszcze raz:" << endl;
            continue;
        }
        break;
    }
    
    string buffer;
    switch(input){
        case 1: //Pokaż listę wszystkich tablic
            showCanvasList(allCanvases);
            break;

        case 2: //Dodaj nową tablicę
            addCanvas(allCanvases);
            break;

        case 3: //Narysuj wszystkie tablice
            drawAllCanvases(allCanvases);
            break;

        case 4: //Narysuj jedną tablicę
            drawOneCanvas(allCanvases);
            break;

        case 5: //Przejdź do modyfikacji jednej z tablic
            showCanvasList(allCanvases);
            cout << "Którą tablicę chcesz modyfikować? (0 aby wyjść)" << endl;
            
            input = chooseCanvas(allCanvases);
            if(input != -1) {
                allCanvases[input].draw(50, 50, true);
                while( modifyCanvas(allCanvases[input]) );
            }
            break;


        case 6: //Usuń jedną z tablic
            cout << "Którą z tablic chcesz usunąć? (0 aby wyjść)" << endl;
            
            input = chooseCanvas(allCanvases);
            if(input != -1) allCanvases.erase(allCanvases.begin() + input);
            break;
            
        case 0:
            return false;
    }
}

void Interface::showCanvasList(vector<Canvas>& allCanvases){
    cout << "\n\n\n";
    for(int i=0; i<allCanvases.size(); i++){ 
        cout << i+1 << "." << endl;
        allCanvases[i].draw(16, 16, 1);
        cout << endl;
    }
}

void Interface::addCanvas(vector<Canvas>& allCanvases){
    Canvas new_canvas;
    allCanvases.push_back(new_canvas);
    cout << "Dodano nową tablicę!\n" << endl;
    return;
}

void Interface::drawAllCanvases(vector<Canvas>& allCanvases){
    bool scaled = false;
    int size_x=0, size_y=0;

    string buffer;
    cout << "Podaj wymiary tablicy (dwie liczby naturalne):\n";

    while(1){ //przyjęcie od użytkownika wymiaru x
        try{
            getline(cin, buffer);
            if(buffer.size() == 0) throw 0;
            size_t number_pos = buffer.find_first_of("1234567890-");
            if(number_pos == string::npos) throw 0;
            buffer = buffer.substr(number_pos);
            size_x = stoi(buffer);
            if(size_x <= 0 ) throw "Wymiary muszą być dodatnie!\n";
        }
        catch(char const* message){
            cout << message;
            continue;
        }
        catch(int) {
            cout << "Przyjmuję domyślną wartość 0." << endl;
            size_x = 0;
        }
        break;
    }

    while(1){ //przyjęcie od użytkownika wymiaru y
        try{
            getline(cin, buffer);
            if(buffer.size() == 0) throw 0;
            size_t number_pos = buffer.find_first_of("1234567890-");
            if(number_pos == string::npos) throw 0;
            buffer = buffer.substr(number_pos);
            size_y = stoi(buffer);
            if(size_y <= 0 ) throw "Wymiary muszą być dodatnie!\n";
        }
        catch(char const* message){
            cout << message;
            continue;
        }
        catch(int) {
            cout << "Przyjmuję domyślną wartość 0." << endl;
            size_y = 0;
        }
        break;
    }

    cout << "Czy chcesz, żeby tablice skalowały się do podanych rozmiarów?: (y/N) ";
    getline(cin, buffer);

    if(buffer == "y" || buffer == "Y" || buffer == "yes" || buffer == "Yes") scaled = true;

    for(int i=0; i<allCanvases.size(); i++){
        allCanvases[i].draw(size_x, size_y, scaled);
    }
}

void Interface::drawOneCanvas(vector<Canvas>& allCanvases){
    
    cout << "Którą tablicę chcesz narysować? (0 żeby wyjść)" << endl;
    int input = chooseCanvas(allCanvases);
    if(input == -1) return; //wyjście, jeżeli użytkownik wybrał 0


    bool scaled = false;
    int size_x=0, size_y=0;

    string buffer;
    cout << "Podaj wymiary tablicy (dwie liczby naturalne):\n";

    while(1){ //przyjęcie od użytkownika wymiaru x
        try{
            getline(cin, buffer);
            if(buffer.size() == 0) throw 0;
            size_t number_pos = buffer.find_first_of("1234567890-");
            if(number_pos == string::npos) throw 0;
            buffer = buffer.substr(number_pos);
            size_x = stoi(buffer);
            if(size_x <= 0 ) throw "Wymiary muszą być dodatnie!\n";
        }
        catch(char const* message){
            cout << message;
            continue;
        }
        catch(int) {
            cout << "Przyjmuję domyślną wartość 0." << endl;
            size_x = 0;
        }
        break;
    }

    while(1){ //przyjęcie od użytkownika wymiaru y
        try{
            getline(cin, buffer);
            if(buffer.size() == 0) throw 0;
            size_t number_pos = buffer.find_first_of("1234567890-");
            if(number_pos == string::npos) throw 0;
            buffer = buffer.substr(number_pos);
            size_y = stoi(buffer);
            if(size_y <= 0 ) throw "Wymiary muszą być dodatnie!\n";
        }
        catch(char const* message){
            cout << message;
            continue;
        }
        catch(int) {
            cout << "Przyjmuję domyślną wartość 0." << endl;
            size_y = 0;
        }
        break;
    }

    cout << "Czy chcesz, żeby tablice skalowały się do podanych rozmiarów?: (y/N) ";
    getline(cin, buffer);

    if(buffer == "y" || buffer == "Y" || buffer == "yes" || buffer == "Yes") scaled = true;

    //kiedy przyjął już wszystkie parametry
    allCanvases[input].draw(size_x, size_y, scaled);
    return;
}

bool Interface::modifyCanvas(Canvas& canvas){ //modyfikacja wybranej tablicy
    cout << "[MENU MODYFIKACJI TABLICY] Wybierz jedną spośród poniższych opcji:\n1. Pokaż tablicę.\n2. Pokaż wszystkie kształty.\n3. Dodaj kształt z pliku.\n4. Modyfikuj kształt.\n5. Usuń kształt.\n6. Wyczyść tablicę.\n0. Wróć do menu." << endl;
    int input = 0;
    while(1){
        try{
            string buffer;
            getline(cin, buffer);
            if(buffer.size() == 0) throw "Podaj numer od 0 do 6: ";
            size_t number_pos = buffer.find_first_of("1234567890");
            if(number_pos == string::npos) throw "Podaj numer od 0 do 6: ";
            buffer = buffer.substr(number_pos);
            input = stoi(buffer);
            if(input < 0 || input > 6) throw "Wybierz jedną z dostępnych opcji!\n";
        }
        catch(char const* message){
            cout << message;
            continue;
        }
        catch(...){
            cout << "Coś poszło nie tak, spróbuj jeszcze raz:" << endl;
            continue;
        }
        break;
    }
    switch(input){
        case 1: //Pokaż tablicę
            canvas.draw(50, 50, true);
            break;

        case 2: //Pokaż wszystkie kształty
            showCanvasShapes(canvas);
            break;

        case 3: //Dodaj kształt z pliku
            addShapeToCanvas(canvas);
            break;

        case 4: //Modyfikuj kształt
            modifyShape(canvas);
            break;
        
        case 5: //Usuń kształt
            showCanvasShapes(canvas);
            removeShape(canvas);
            break;
        
        case 6: //Wyczyść tablicę
            clearCanvas(canvas);
            break;

        case 0:
            return false;
    }
    return true;
}

void Interface::drawShape(Shape& shape){
    Canvas temp;
    temp.addShape(shape);
    temp.draw(16, 16, true);
}

void Interface::showCanvasShapes(Canvas& canvas){
    vector<Shape> allShapes = *(canvas.getShapes());
    for(int i=0; i<allShapes.size(); i++ ){
        cout << i+1 << "." << endl;
        drawShape( allShapes[i] );
    }
}

void Interface::addShapeToCanvas(Canvas& canvas){
    string buffer;
    cout << "Podaj nazwę pliku, z którego chcesz wczytać kształt (pozostaw puste żeby wyjść): ";
    while(1){
        try{
            getline(cin, buffer);
            if(buffer.size() == 0) return;
            canvas.addShape( buffer.c_str() );
        }
        catch(...){
            cout << "Popraw plik lub podaj poprawną nazwę (pozostaw puste żeby wyjść): ";
            continue;
        }
        break;
    }
    cout << "Załadowano kształt!\n" << endl;
}

void Interface::removeShape(Canvas& canvas){
    vector<Shape>* allShapesPointer = canvas.getShapes();
    cout << "Który kształt chciałbyś usunąć? (0 żeby wyjść)" << endl;
    int input = chooseShape(canvas);
    if (input == -1) return;
    else allShapesPointer->erase(allShapesPointer->begin() + input);
    cout << "Kształt usunięty!" << endl;
    return;
}

void Interface::clearCanvas(Canvas& canvas){
    vector<Shape>* pointer = canvas.getShapes();
    pointer->clear();
    cout << "Tablica wyczyszczona!\n" << endl;
    return;
}

void Interface::modifyShape(Canvas& canvas){
    showCanvasShapes(canvas);
    vector<Shape>* allShapesPointer = canvas.getShapes();
    cout << "Wybierz jeden z kształtów (0 żeby wyjść): " << endl;
    int input = chooseShape(canvas);
    if (input == -1) return;

    Shape* opPointer = &(*allShapesPointer)[input];

    cout << "Wybierz operację:\n1. Przesuń.\n2. Przeskaluj.\n3. Odbij w pionie.\n4. Odbij w poziomie.\n5. Zmień kolor.\n0. Wróć do modyfikacji tablicy." << endl;
    
    while(1){
        try{
            string buffer;
            getline(cin, buffer);
            if(buffer.size() == 0) throw "Podaj numer od 0 do 5: ";
            size_t number_pos = buffer.find_first_of("1234567890");
            if(number_pos == string::npos) throw "Podaj numer od 0 do 5: ";
            buffer = buffer.substr(number_pos);
            input = stoi(buffer);
            if(input < 0 || input > 5) throw "Wybierz jedną z dostępnych opcji!\n";
        }
        catch(char const* message){
            cout << message;
            continue;
        }
        catch(...){
            cout << "Coś poszło nie tak, spróbuj jeszcze raz:" << endl;
            continue;
        }
        break;
    }
    double x_offset = 0, y_offset = 0, ratio = 1;
    char color;
    string buffer;
    switch(input){
        case 1:
            cout << "Podaj wartość przesunięcia na osi x: ";
            try{
                getline(cin, buffer);
                if(buffer.size() == 0) throw 0;
                size_t number_pos = buffer.find_first_of("1234567890-");
                if(number_pos == string::npos) throw 0;
                buffer = buffer.substr(number_pos);
                x_offset = stod(buffer);
            }
            catch(int){
                cout << "Przyjmuję domyślną wartość 0." << endl;
            }
            cout << "Podaj wartość przesunięcia na osi y: ";
            try{
                getline(cin, buffer);
                if(buffer.size() == 0) throw 0;
                size_t number_pos = buffer.find_first_of("1234567890-.");
                if(number_pos == string::npos) throw 0;
                buffer = buffer.substr(number_pos);
                y_offset = stod(buffer);
            }
            catch(int){
                cout << "Przyjmuję domyślną wartość 0." << endl;
            }

            opPointer->move(x_offset, y_offset);
            cout << "Kształt przesunięty o wektor (" << x_offset << ", " << y_offset << ").\n " << endl;
            break;
        
        case 2:
            cout << "Podaj skalę: ";
            try{
                getline(cin, buffer);
                if(buffer.size() == 0) throw 0;
                size_t number_pos = buffer.find_first_of("1234567890-");
                if(number_pos == string::npos) throw 0;
                buffer = buffer.substr(number_pos);
                ratio = stod(buffer);
            }
            catch(int){
                cout << "Przyjmuję domyślną wartość 1." << endl;
            }

            opPointer->scale(ratio);
            cout << "Przeskalowano przez " << ratio << ".\n" << endl;
            break;

        case 3:
            opPointer->flipVertically();
            cout << "Odbito w pionie.\n" << endl;
            break;

        case 4:
            opPointer->flipHorizontally();
            cout << "Odbito w poziomie.\n" << endl;
            break;

        case 5:
            cout << "Podaj znak, który będzie nowym kolorem tej figury (zostaw puste żeby wyjść): ";
            getline(cin, buffer);
            if(buffer.size() == 0) return;
            opPointer->colorChange(buffer[0]);
            cout << "Zmieniono kolor na \"" << opPointer->getColor() << "\".\n" << endl;
            break;

        case 0:
            return;
    }
    drawShape(*opPointer);

    return;
}
