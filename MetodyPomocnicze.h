#ifndef METODYPOMOCNICZE_H //dyrektywa, gdy dany plik zostanie kilka razy zainkludowny
#define METODYPOMOCNICZE_H

#include <iostream>

using namespace std;

class MetodyPomocnicze
{
public:
    static string konwerjsaIntNaString(int liczba);
    static int konwersjaStringNaInt(string liczba);
    static string wczytajLinie();
    static bool czyPlikJestPusty(fstream &plikTekstowy);
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static char wczytajZnak();

};
#endif
/* met statyczne - nie bede musiala tworzyc obiektu tej klay, ¿eby j¹ wywo³aæ
    zamiast tworzyæ obiekt, wywo³ujemy metode na klasie, z której pochodzi*/
