#include <iostream>
#include "PlikTekstowy.h"
#include <fstream>

using namespace std;

string PlikTekstowy::pobierzNazwePliku()
{
    return NAZWA_PLIKU;
}
bool PlikTekstowy::czyPlikJestPusty(fstream &plikTekstowy)
{
    plikTekstowy.seekg(0, ios::end);
    if (plikTekstowy.tellg() == 0)
        return true;
    else
        return false;
}


