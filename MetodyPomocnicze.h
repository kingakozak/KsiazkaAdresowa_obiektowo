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
    static string pobierzLiczbe(string tekst, int pozycjaZnaku);
    static char wczytajZnak();
    static string zamienPierwszaLitereNaDuzaAPozostaleNaMale(string tekst);
    static int wczytajLiczbeCalkowita();

};
#endif
/* met statyczne - nie bede musiala tworzyc obiektu tej klay, �eby j� wywo�a�
    zamiast tworzy� obiekt, wywo�ujemy metode na klasie, z kt�rej pochodzi*/
