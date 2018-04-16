#include <iostream>
#ifndef LISTAPOLACZEN_H
#define LISTAPOLACZEN_H

#include "polaczenie.h"

using namespace std;

class ListaPolaczen{
private:
    Polaczenie* wszystkiePolaczenia;
    static const int MAX_POLACZEN = 100;
    int ilePolaczen;
public:
    ListaPolaczen();
    ListaPolaczen(ListaPolaczen& l);
    void dodaj_polaczenie(Polaczenie& p);
    void wypisz_polaczenia();
    int zwroc_liczbe_polaczen();
    void zapisz();
    void operator+=(Polaczenie& p);
    ~ListaPolaczen();
    };

    #endif // LISTAPOLACZEN_H
