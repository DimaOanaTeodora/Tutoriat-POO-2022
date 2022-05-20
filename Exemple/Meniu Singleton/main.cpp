#include <iostream>
#include <string>
#include "Malware.h"
#include "Calculator.h"
using namespace std;

class Menu {
private:
    static Menu *instance;
    Calculator** array;
    int n;

    Menu() {
        this -> array= new Calculator * [100];
    }

public:
    ~Menu(){
        cout<<"destructor";
        delete [] array;
    }
    static Menu *getInstance() {
        if (instance == NULL) {
            instance = new Menu;
        }
        return instance;
    }
    void showOptions(){
        cout<<"-------------------------------Meniu-------------------------------------------"<<endl;
        cout<<"0. citirea a n calculatoare si afisarea lor"<<endl;
        cout<<"1. afișarea informațiilor pentru fiecare calculator"<<endl;
        cout<<"2. afișarea informațiilor pentru fiecare calculator fiind ordonate după ratingul final"<<endl;
        cout<<"3. afișarea primelor k calculatoare ordonate după ratingul final"<<endl;
        cout<<"4. afișarea procentului de computere infectate din firmă"<<endl;
        cout<<"5. exit"<<endl;
        cout<<"----------------------------------------------------------------------------------"<<endl;
    }
    void cerinta0(){
        cout<<"TODO cerinta 0"<<endl;
    }
    void cerinta1(){
        cout<<"TODO cerinta 1"<<endl;
    }
    void cerinta2(){
        cout<<"TODO cerinta 2"<<endl;
    }
    void cerinta3(){
        cout<<"TODO cerinta 3"<<endl;
    }
    void cerinta4(){
        cout<<"TODO cerinta 4"<<endl;
    }
    // cerinta 5 => exit prin brak;
};

Menu *Menu::instance;
int main() {
    Menu *menu = Menu::getInstance();
    int nr_cerinta;

    while(true){
        menu -> showOptions();
        cout<<"Dati nr cerinta: ";
        cin>> nr_cerinta;
        if(nr_cerinta == 0){
            menu -> cerinta0();
        } else if(nr_cerinta == 1){
            menu -> cerinta1();
        } else if(nr_cerinta == 2){
            menu -> cerinta2();
        } else if(nr_cerinta == 3){
            menu -> cerinta3();
        } else if(nr_cerinta == 4){
            menu -> cerinta4();
        }
        else if(nr_cerinta == 5){
            break;
        }
    }
    delete menu;
    return 0;
}
