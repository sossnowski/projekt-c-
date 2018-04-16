/*Program umozliwia zarzadzanie godzinami pracownikow kolei,
po przez dodawanie nowych polaczen kolejowych i pzypisywanie do nich wymaganej ilosci pracownikow.
Istnieje mozliwosc zapisu zmian do pliku, a pozniej ponowne ich odtworzenie.
autor: Krzysztof Brzoska
 */

#include <iostream>
#include <sstream>
#include <fstream>
#include "polaczenie.h"
#include "pracownik.h"
#include "listapolaczen.h"
#include "listapracownikow.h"



using namespace std;
//#define PROBA_OPERATOROW_I_ROZNYCH_WYMAGANYCH_FUNKCJI_PROGRAMU

int main()
{
    //pierwsza czesc funkcji main pokazuje dzialanie przeladowanych operatorow i konstruktorow kopiujacych
    #ifdef PROBA_OPERATOROW_I_ROZNYCH_WYMAGANYCH_FUNKCJI_PROGRAMU


    ListaPolaczen listaProbna1;
    ListaPracownikow listaProbnaPracownikow1;
    Polaczenie p1(1,"WWA<->KRK",3);
    Polaczenie p2(5,"KRK<->POZ",9);
    Polaczenie p3(4,"KRK<->WRO",125);
    Pracownik h1("Jan","Kowalski","12-20",1);
    Pracownik h2("Piotr","Nowak","10-21",2);
    Pracownik h3(h1);
    Polaczenie p4(p1);
    p4=p2;
    cout<<p1;
    cout<<h1;
    cout<<p2;
    bool czyRowne = (h1==h2);
    cout<<czyRowne<<endl;
    listaProbna1 += p1;
    listaProbna1 += p2;
    listaProbna1.wypisz_polaczenia();
    listaProbnaPracownikow1 + h1;
    listaProbnaPracownikow1 + h2;
    listaProbnaPracownikow1.wypisz_pracownikow();
    ListaPolaczen listaProbna2(listaProbna1);
    ListaPracownikow listaProbnaPracownikow2(listaProbnaPracownikow1);
    listaProbna2 += p3;
    listaProbna2.wypisz_polaczenia();
    #endif // PROBA_OPERATOROW_I_ROZNYCH_WYMAGANYCH_FUNKCJI_PROGRAMU


//wlascia czesc programu
    ListaPolaczen l1;
    ListaPracownikow lprac1;
    int wczytaj;
    cout<<"1 wczytaj dane  |  2 nowa sesja"<<endl;
    cin>>wczytaj;
    if (wczytaj == 1){
        string a,b,c,d;
        int nrPol, potrzPrac;
        ifstream plik("polaczenia.txt");
        if(plik){
        while(plik>>a>>b>>c){
            istringstream iss(a);
            iss >> nrPol;
            istringstream iss1(c);
            iss1 >> potrzPrac;

            Polaczenie tmp(nrPol, b, potrzPrac);
            l1.dodaj_polaczenie(tmp);
        }
        ifstream plik1("pracownicy.txt");
        while(plik1>>a>>b>>c>>d){
            istringstream iss(d);
            iss >> nrPol;
            Pracownik tmp(a,b,c, nrPol);
            lprac1.dodaj_pracownika(tmp);

        }
        }else{
            cout<<"nie zapisales jeszcze zadnych danych"<<endl;
        }
    }
    int wybor_glowny;
    do{

        cout<< "1 dodaj polaczenie | 2 wypisz wszystkie polaczenia | 3 wyswietl wszystkich pracownikow |";
        cout<<" 4 zapisz zmiany | 0 zakoncz"<<endl;
        cin>>wybor_glowny;
        cin.sync();
        switch(wybor_glowny){
        case 1:
            {
                Polaczenie p1(1);
                l1.dodaj_polaczenie(p1);
                int potrzebnychPracownikow = p1.zwroc_potrzebnych_pracownikow();
                int nrPolaczenia = p1.zwroc_nrPolaczenia();
                for(int i=0; i<potrzebnychPracownikow;++i){

                    Pracownik prac1(nrPolaczenia);
                    lprac1.dodaj_pracownika(prac1);
                }
            }
            break;
        case 2:
            {
                int ile = l1.zwroc_liczbe_polaczen();
                if(ile==0){
                    cout<<"nie dodales jeszcze zadnych polaczen"<<endl;
                }else{
                    l1.wypisz_polaczenia();
                }
            }

            break;
        case 3:
            {
                int ile = lprac1.zwroc_liczbe_pracownikow();
                if (ile==0){
                    cout<<"nie dodales jeszcze zadnych pracownikow"<<endl;
                }else{
                    lprac1.wypisz_pracownikow();
                }
            }

            break;
        case 4:
            l1.zapisz();
            lprac1.zapisz();

        }
        //break;
    }while(wybor_glowny!=0);

    return 0;
}
