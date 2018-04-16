#include <iostream>
#ifndef LISTAPRACOWNIKOW_H
#define LISTAPRACOWNIKOW_H
#include "pracownik.h"

using namespace std;

class ListaPracownikow{
private:
    Pracownik *wszyscyPracownicy;
    int iluPracownikow;
    static const int MAX_PRACOWNIKOW = 300;
public:
    ListaPracownikow();
    ListaPracownikow(ListaPracownikow& l);
    void wypisz_pracownikow();
    void dodaj_pracownika(Pracownik &p);
    int zwroc_liczbe_pracownikow();
    void zapisz();
    void operator+(Pracownik& p);
    ~ListaPracownikow();
};




#endif // LISTAPRACOWNIKOW_H
