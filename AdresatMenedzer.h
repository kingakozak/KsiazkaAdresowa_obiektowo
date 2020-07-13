#include <iostream>
#include <vector>
#include <windows.h>
#include "Adresat.h"
#include "PlikZAdresatami.h"


using namespace std;

class AdresatMenadzer
{
    vector <Adresat> adresaci;
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika, int idOstatniegoAdresata);
    PlikZAdresatami plikZAdresatami;
    string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    void wyswietlDaneAdresata(Adresat adresat);


public:
    AdresatMenadzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami){};
    int dodajAdresata(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);


    //void wczytajAdresatowZalogowanegoUzytkownikaZPliku();

};
