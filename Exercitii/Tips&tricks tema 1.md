# Exemplu de interpretare T1

### Clasa model
```C++
#include <iostream>
using namespace std;

class A{
    int x;

public:
    A(){}
    A(int x){
        this -> x = x;
    }
    A(const A & a){
        // CC
        this -> x = a.x;
    }

    ~A(){}

    int getX() const {
        return x;
    }

    void setX(int x) {
        A::x = x;
    }

    friend ostream& operator <<(ostream& os, A& ob);//pentru afisare
    friend istream& operator >> (istream& os, A& ob);//pentru citire

    A& operator = (const A& a){
        this -> x = a.x;
        return *this;
    }
};

istream& operator >> (istream& os, A& ob)
{
    //cout<<"Titlu obiect"<<endl;
    //getline(os,str); // citire stringuri
    cout << "x = ";
    os >> ob.x;
    os.get(); // dupa inturi
    return os;
}
ostream& operator <<(ostream& os, A& ob)
{
    //os<<"Titlu obiect:"<<endl;
    os<<"x = ";
    os<<ob. x;
    return os;
}

int main()
{
    A *arr = new A[5];

    cout<< "Fara operatori"<<endl;
    for(int i = 0; i< 5; i++){
        A *a = new A(i);
       arr[i] = *a;
    }

    for(int i = 0; i< 5; i++){
       cout<<arr[i].getX()<< endl;
    }

    cout<< "Cu operatori"<<endl;
    // citire si afisare folosind operatorii >> si <<

    cout<<"Input:"<<endl;
    for(int i = 0; i< 5; i++){
        cin>> arr[i];
    }

    cout<<"Output:"<<endl;
    for(int i = 0; i< 5; i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}
```

### Exemplu

Definiti clasa ```persoana``` avand:
- membri privati pentru nume (string), anul nasterii (intreg), sex (caracter); ``` => 3 date membre```
- sase metode publice pentru setarea/furnizarea informatiilor din cei trei membri privati. ``` getters & setters pentru fiecare 2*3 =6 ```
Definiti clasa ```baza_de_date``` avand:
- ca membri privati un vector la "persoana" declarat dinamic si un intreg reprezentand numarul persoanelor;
  ``` 
    2 date membre:
        int nr_persoane;
        persoana *arr = new persoana[nr_persoane]; // array alocat dinamic (folosim keywordul new)
        persoana arr[nr_persoane]; // array alocat static
  ```
- ca metode publice:
  -  un constructor care initializeaza vectorul cu NULL pe fiecare componenta, 
    ``` C++
    baza_de_date(int nr_persoane){
        this -> nr_persoane = nr_persoane;
        for(int i = 0; i< nr_persoane; i++){
            this -> arr[i] =  NULL; 
        }
    }
    ```
    Mai multe despre alocarea dinamica gasiti [aici](https://www.guru99.com/cpp-dynamic-array.html).

  -  un destructor care dezaloca toate "persoanele" pointate de componentele vectorului,
    ``` C++
    ~baza_de_date(){
        delete [] arr; //sterge fiecare element din arr
    }
    ```
  -   o metoda pentru adaugat o "persoana"
    ```C++
    arr[nr_persoane] = *new persoane(....);
    ```
  -   trei metode pentru eliminat persoanele avand un anumit  nume, respectiv an al nasterii, respectiv sex (cele trei metode vor  avea acelasi nume, prin supraincarcare), 
    ```C++
    class baza_de_date{
      ...
      public:
        void sterge(string nume){...}
        void sterge(int an){...}
        void sterge(char sex){...}
        ....
    }
    ```
  Mai multe despre supraincarcarea functiilor [aici](https://www.geeksforgeeks.org/function-overloading-c/).

  -   doua metode pentru afisat persoanele continute in baza de date in ordinea alfabetica a numelor, respectiv crescatoare a varstelor. ```=> sortare pe vectori```
  
Cele doua clase de mai sus pot avea si alti membri/metode, dar se va respecta principiul incapsularii datelor (orice setare/furnizare a  informatiilor continute in membrii privati se va face doar prin intermediul unor metode). ```=> folosim numai private pentru datele membre```

Scrieti un program care sa gestioneze o baza de date folosind clasele de  mai sus. El va afisa un meniu (in mod text), care va oferi functii de adaugat o persoana, eliminat persoanele dupa nume, varsta, sex, afisat persoanele in ordine alfabetica sau dupa varsta. 
```  
o functie (declarata in afara claselor) care afiseaza optiunile de ales numerotate
un input unde sa introduca de la tastatura numarul optiunii
in functien de numarul optiunii introdus cere anumite lucruri/afiseaza anumite lucruri 
! Nu uitati de citirea a n obiecte (vector cu obiecte stiu ca trebuie si salvate, eventual si afisate, nu doar citite).
```

