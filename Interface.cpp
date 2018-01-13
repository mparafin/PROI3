#include <iostream>
#include <vector>
#include <string>

#include "Canvas.hpp"
#include "Interface.hpp"

using namespace std;


Interface::Interface(){
    cout << "PROI3 - Prosty edytor graficzny\nAutor: Michał Parafiniuk, Copyright: Politechnika Warszawska\n" << endl;    
}

Interface::~Interface(){
    cout << "Dziękujemy za skorzystanie z programu, zapraszamy ponownie!" << endl;
}

bool Interface::menu(vector<Canvas>& allCanvases){
    cout << "Wybierz jedną spośród poniższych opcji:\n1. Pokaż listę wszystkich tablic\n2. Narysuj wszystkie tablice\n3. Narysuj jedną tablicę\n4. Edytuj jedną tablicę\n5. Usuń jedną z tablic\n6. Wyjdź z programu" << endl;
    int input = 0;
    while(1){
        try{
            string buffer;
            getline(cin, buffer);
            if(buffer.size() == 0) throw "Podaj numer od 1 do 6: ";
            size_t number_pos = buffer.find_first_of("1234567890");
            if(number_pos == string::npos) throw "Podaj numer od 1 do 6: ";
            buffer = buffer.substr(number_pos);
            input = stoi(buffer);
            if(input <= 0 || input > 6) throw "Wybierz jedną z dostępnych opcji!\n";
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
            //showCanvasList(allCanvases);
            cout << "showAllCanvases(allCanvases);" << endl;
            break;

        case 2: //Narysuj wszystkie tablice
            drawAllCanvases(allCanvases);
            break;

        case 3: //Narysuj jedną tablicę
            //drawOneCanvas(allCanvases);
            cout << "drawOneCanvas(allCanvases);" << endl;
            break;

        case 4: //Przejdź do modyfikacji jednej z tablic
            //showCanvasList(allCanvases);
            cout << "Którą tablicę chcesz modyfikować?" << endl;
            while(1){
                try{
                    getline(cin, buffer);
                    if(buffer.size() == 0) throw "Wybierz jedną z istniejących tablc: ";
                    size_t number_pos = buffer.find_first_of("1234567890");
                    if(number_pos == string::npos) throw "Wybierz jedną z istniejących tablic: ";
                    buffer = buffer.substr(number_pos);
                    input = stoi(buffer);
                    if(input <= 0 || input > allCanvases.size()) throw "Wybierz jedną z dostępnych opcji!\n";
                }
                catch(char const* message){
                    cout << message;
                    continue;
                }
                break;
            }
            //modifyCanvas(allCanvases[input-1]);
            cout << "modifyCanvas(allCanvases[input-1]);" << endl;
            break;


        case 5: //Usuń jedną z tablic
            cout << "Którą z tablic chcesz usunąć?" << endl;
            while(1){
                try{
                    getline(cin, buffer);
                    if(buffer.size() == 0) throw "Wybierz jedną z istniejących tablc: ";
                    size_t number_pos = buffer.find_first_of("1234567890");
                    if(number_pos == string::npos) throw "Wybierz jedną z istniejących tablic: ";
                    buffer = buffer.substr(number_pos);
                    input = stoi(buffer);
                    if(input <= 0 || input > allCanvases.size()) throw "Wybierz jedną z dostępnych opcji!\n";
                }
                catch(char const* message){
                    cout << message;
                    continue;
                }
                break;
            }
            //allCanvases.erase(allCanvases.begin()+input-1);
            break;
            
        case 6:
            return false;
    }
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

