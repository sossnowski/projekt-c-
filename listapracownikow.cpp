#include <iostream>
#include <string>
#include <fstream>
#include "listapracownikow.h"

using namespace std;
//#define DEBUG_

ListaPracownikow::ListaPracownikow(){
    #ifdef DEBUG_
    cout<<"wywolano konstruktor"<<endl;
    #endif // DEBUG_
    wszyscyPracownicy = new Pracownik[MAX_PRACOWNIKOW];
    iluPracownikow = 0;
}

ListaPracownikow::ListaPracownikow(ListaPracownikow& l){
    #ifdef DEBUG_
    cout<<"wywolano konstruktor kopiujacy"<<endl;
    #endif // DEBUG_
    wszyscyPracownicy = new Pracownik[MAX_PRACOWNIKOW];
    iluPracownikow = l.iluPracownikow;
    for(int i = 0;i<l.iluPracownikow;i++){
        wszyscyPracownicy[i] = l.wszyscyPracownicy[i];
    }
}
ListaPracownikow::~ListaPracownikow(){
    #ifdef DEBUG_
    cout<<"wywolano destruktor"<<endl;
    #endif // DEBUG_
    delete [] wszyscyPracownicy;
}

void ListaPracownikow::dodaj_pracownika(Pracownik &p){
    if (iluPracownikow == MAX_PRACOWNIKOW){
        cout<<"nie ma miejsca w tablicy"<<endl;
    }else{
        wszyscyPracownicy[iluPracownikow] = p;
        iluPracownikow++;
    }
}

void ListaPracownikow::wypisz_pracownikow(){
    for (int i = 0;i<iluPracownikow;i++){
        cout<<"pracownik nr: "<<i+1<<endl;
        wszyscyPracownicy[i].wypisz_pracownika();
    }

}

int ListaPracownikow::zwroc_liczbe_pracownikow(){
    return iluPracownikow;
}

void ListaPracownikow::zapisz(){
    ofstream plik("pracownicy.txt");
    for (int i =0;i<iluPracownikow;i++){
        plik<<wszyscyPracownicy[i].konwertuj_na_string();
    }
    plik.close();
}
void ListaPracownikow::operator+(Pracownik& p){
    wszyscyPracownicy[iluPracownikow] = p;
    iluPracownikow++;
}
