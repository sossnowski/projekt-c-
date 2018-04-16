#include <iostream>
#ifndef POLACZENIE_H
#define POLACZENIE_H

using namespace std;

class Polaczenie{
private:
    int nrPolaczenia;
    string relacja;
    int potrzebnychPracownikow;
public:
    Polaczenie();
    Polaczenie(int i);
    Polaczenie(int a, string b, int c);
    Polaczenie(Polaczenie& p);
    int zwroc_nrPolaczenia();
    void wypisz_polaczenie();
    void utworz_polaczenie();
    int zwroc_potrzebnych_pracownikow();
    string konwertuj_na_string();
    friend class Pracownik;
    friend class ListaPolaczen;
    friend ostream& operator<<(ostream& os, Polaczenie& p2);
    Polaczenie& operator=(Polaczenie& p);
    ~Polaczenie();
};

#endif // POLACZENIE_H

