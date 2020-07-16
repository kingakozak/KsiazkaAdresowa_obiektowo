#ifndef PLIK_TEKSTOWY_H //dyrektywa, gdy dany plik zostanie kilka razy zainkludowny
#define PLIK_TEKSTOWY_H

#include <iostream>>

using namespace std;

class PlikTekstowy
{
    const string NAZWA_PLIKU;

public:
    string pobierzNazwePliku();
    PlikTekstowy (string nazwaPliku) : NAZWA_PLIKU (nazwaPliku) {};
    bool czyPlikJestPusty(fstream &plikTekstowy);
};

#endif
