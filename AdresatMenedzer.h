#include <iostream>
#include <vector>
#include <windows.h>
#include "Adresat.h"
#include "PlikZAdresatami.h"


using namespace std;

class AdresatMenadzer
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Adresat> adresaci;
    Adresat podajDaneNowegoAdresata();
    PlikZAdresatami plikZAdresatami;
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    void wyswietlDaneAdresata(Adresat adresat);
    void wyswietlIloscWyszukanychAdresatow(int iloscAdresatow);
    int podajIdWybranegoAdresata();
    char wybierzOpcjeZMenuEdycja();

public:
    AdresatMenadzer(string nazwaPlikuZAdresatami, string nazwaTymczasowegoPlikuZAdresatami, int idZalogowanegoUzytkownika)
    : plikZAdresatami(nazwaPlikuZAdresatami, nazwaTymczasowegoPlikuZAdresatami),ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci = plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void wyszukajAdresatowPoImieniu();
    void wyszukajAdresatowPoNazwisku();
    int usunAdresata();
    void edytujAdresata();

};
