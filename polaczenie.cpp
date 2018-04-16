#include <iostream>
#include <string>
#include <sstream>
#include "polaczenie.h"
#include "pracownik.h"

using namespace std;
//#define DEBUG_

Polaczenie::Polaczenie(){
    #ifdef DEBUG_
    cout<<"wywolano konstruktor"<<endl;
    #endif // DEBUG_
}



Polaczenie::Polaczenie(int i){
    #ifdef DEBUG_
    cout<<"wywolano konstruktor z parametrami"<<endl;
    #endif // DEBUG_
    utworz_polaczenie();
}

Polaczenie::Polaczenie(int a, string b, int c){
    #ifdef DEBUG_
    cout<<"wywolano konstruktor z parametrami"<<endl;
    #endif // DEBUG_
    nrPolaczenia = a;
    relacja = b;
    potrzebnychPracownikow = c;
}

Polaczenie::Polaczenie(Polaczenie& p){
    #ifdef DEBUG_
    cout<<"wywolano konstruktor kopiujacy"<<endl;
    #endif // DEBUG_
    nrPolaczenia = p.nrPolaczenia;
    relacja = p.relacja;
    potrzebnychPracownikow= p.potrzebnychPracownikow;
}

Polaczenie::~Polaczenie(){
    #ifdef DEBUG_
    cout<<"wywolano destruktor"<<endl;
    #endif // DEBUG_
    };

int Polaczenie::zwroc_nrPolaczenia(){
    return nrPolaczenia;
}

int Polaczenie::zwroc_potrzebnych_pracownikow(){
    return potrzebnychPracownikow;
}

void Polaczenie::utworz_polaczenie(){
    int wybor=0;
    cout<<"Wybierz jakie polaczenie chcesz dodac? W nawiasie ilosc potrzebnych pracownikow aby obsluzyc dane polaczenie"<<endl;
    cout<<"1 WWA<->KRK(2) | 2 WWA<->POZ(3) | 3 WWA<->WRO(3) |4 WWA<->GD(2) |"<<endl;
    cin>>wybor;
    do{
        switch(wybor){
        case 1:
            this->potrzebnychPracownikow = 2;
            this->relacja = "WWA<->KRK";
            cout<<"Potrzebujesz "<<potrzebnychPracownikow<<" pracownikow do tego polaczenia, dodaj ich."<<endl;
            break;
        case 2:
            this->potrzebnychPracownikow = 3;
            this->relacja = "WWA<->POZ";
            break;
        case 3:
            this->potrzebnychPracownikow = 3;
            this->relacja = "WWA<->WRO";
            break;
        case 4:
            this->potrzebnychPracownikow = 2;
            this->relacja = "WWA<->GD";
            break;
        }
    break;

    }while(wybor != 0);
}

void Polaczenie::wypisz_polaczenie(){
    cout<<"Polaczenie nr: "<<nrPolaczenia+1<<endl;
    cout<<"relacja: "<<relacja<<endl;
    cout<<"ilosc pracownikow potrzebna do obsluzenia kursu: "<<potrzebnychPracownikow<<endl;
}

string Polaczenie::konwertuj_na_string(){
    ostringstream ss;
    ss << nrPolaczenia;
    string str = ss.str();

    ostringstream ss1;
    ss1 << potrzebnychPracownikow;
    string str1 = ss1.str();

    return (str+" "+relacja+" "+str1+"\n");
}

ostream& operator<<(ostream& os, Polaczenie& p2){
    os<<p2.nrPolaczenia<<" "<<p2.relacja<<" "<<p2.potrzebnychPracownikow<<endl;
    return os;
}

Polaczenie& Polaczenie::operator=(Polaczenie& p){
    nrPolaczenia = p.nrPolaczenia;
    relacja = p.relacja;
    potrzebnychPracownikow = p.potrzebnychPracownikow;
    return *this;
}
