#include <iostream>
#include <sstream>
#include "pracownik.h"

using namespace std;
//#define DEBUG_

Pracownik::Pracownik(){
    #ifdef DEBUG_
    cout<<"wywolano konstruktor"<<endl;
    #endif // DEBUG_
}

Pracownik::Pracownik(int nrPol){
    #ifdef DEBUG_
    cout<<"wywolano konstruktor z parametrami"<<endl;
    #endif // DEBUG_
    this->dodaj_pracownika(nrPol);
}

Pracownik::Pracownik(string a, string b, string c, int d){
    #ifdef DEBUG_
    cout<<"wywolano konstruktor z parametrami"<<endl;
    #endif // DEBUG_
    imie = a;
    nazwisko = b;
    godzinyPracy = c;
    nrPolaczenia = d;
}

Pracownik::Pracownik(Pracownik& p){
    #ifdef DEBUG_
    cout<<"wywolano konstruktor kopiujacy"<<endl;
    #endif // DEBUG_
    imie=p.imie;
    nazwisko=p.nazwisko;
    godzinyPracy = p.godzinyPracy;
    nrPolaczenia = p.nrPolaczenia;
}

Pracownik::~Pracownik(){
    #ifdef DEBUG_
    cout<<"wywolano destruktor"<<endl;
    #endif // DEBUG_
};

void Pracownik::dodaj_pracownika(int nrPol){
    cout<<"Podaj imie pracownika"<<endl;
    cin>>imie;
    cout<<"Podaj nazwisko pracownika"<<endl;
    cin>>nazwisko;
    cout<<"podaj jego godziny pracy"<<endl;
    cin>>godzinyPracy;
    nrPolaczenia = nrPol;
}

void Pracownik::wypisz_pracownika(){
    cout<<imie<<" ";
    cout<<nazwisko<<endl;
    cout<<"godziny pracy: "<<godzinyPracy<<endl;
    cout<<"obsluguje polaczenie nr: "<<nrPolaczenia +1<<endl;
    cout<<"********"<<endl;
}

string Pracownik::konwertuj_na_string(){
    ostringstream ss;
    ss << nrPolaczenia;
    string str = ss.str();

    return(imie+" "+nazwisko+" "+godzinyPracy+" "+str+"\n");
}

bool operator==(Pracownik &p1, Pracownik &p2){
    return (p1.imie == p2.imie && p1.nazwisko == p2.nazwisko && p1.nrPolaczenia == p2.nrPolaczenia);
}
ostream& operator<<(ostream& os, Pracownik& p2){
    os<<p2.imie<<" "<<p2.nazwisko<<" "<<p2.godzinyPracy<<" "<<p2.nrPolaczenia<<endl;
    return os;
}
