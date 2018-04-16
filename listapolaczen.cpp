#include <iostream>
#include <string>
#include "listapolaczen.h"
#include <fstream>

using namespace std;
//#define DEBUG_

ListaPolaczen::ListaPolaczen(){
    #ifdef DEBUG_
    cout<<"wywolano konstruktor"<<endl;
    #endif // DEBUG_
    wszystkiePolaczenia = new Polaczenie[MAX_POLACZEN];
    ilePolaczen = 0;
}

ListaPolaczen::ListaPolaczen(ListaPolaczen& l){
    #ifdef DEBUG_
    cout<<"wywolano konstruktor kopiujacy"<<endl;
    #endif // DEBUG_
    wszystkiePolaczenia = new Polaczenie[MAX_POLACZEN];
    ilePolaczen = l.ilePolaczen;
    for(int i = 0;i<l.ilePolaczen;i++){
        wszystkiePolaczenia[i] = l.wszystkiePolaczenia[i];
    }
}
ListaPolaczen::~ListaPolaczen(){
     #ifdef DEBUG_
    cout<<"wywolano destruktor"<<endl;
    #endif // DEBUG_
    delete [] wszystkiePolaczenia;
}

void ListaPolaczen::dodaj_polaczenie(Polaczenie& p){
    if(ilePolaczen==MAX_POLACZEN){
        cout<<"nie ma miejsca w tablicy"<<endl;
    }else{
        p.nrPolaczenia = ilePolaczen;
        wszystkiePolaczenia[ilePolaczen]= p;
        ilePolaczen++;
    }
}
int ListaPolaczen::zwroc_liczbe_polaczen(){
    return ilePolaczen;
}

void ListaPolaczen::wypisz_polaczenia(){
    for (int i =0;i<ilePolaczen;i++){
        wszystkiePolaczenia[i].wypisz_polaczenie();
    }

}

void ListaPolaczen::zapisz(){
    ofstream plik("polaczenia.txt");
    for (int i =0;i<ilePolaczen;i++){
        plik<<wszystkiePolaczenia[i].konwertuj_na_string();
    }
    plik.close();
}
void ListaPolaczen::operator+=(Polaczenie& p){
    p.nrPolaczenia--;
    wszystkiePolaczenia[ilePolaczen] = p;
    ilePolaczen++;
}

