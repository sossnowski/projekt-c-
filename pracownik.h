#include <iostream>
#ifndef PRACOWNIK_H
#define PRACOWNIK_H


using namespace std;

class Pracownik{
private:
    string imie;
    string nazwisko;
    string godzinyPracy;
    int nrPolaczenia;
public:
    Pracownik();
    Pracownik(string a, string b, string c, int d);
    Pracownik(int nrPolaczenia);
    Pracownik(Pracownik& p);
    void wypisz_pracownika();
    void dodaj_pracownika(int nrPolaczenia);
    string konwertuj_na_string();
    friend bool operator==(Pracownik &p1, Pracownik &p2);
    friend ostream& operator<<(ostream& os, Pracownik& p2);
    ~Pracownik();
};

#endif // PRACOWNIK_H
