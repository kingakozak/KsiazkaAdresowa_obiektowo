#include <iostream>
#include "UzytkownikMenedzer.h"

using namespace std;

void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}
Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do
    {
        cout<< "Podaj login: ";
        cin>>login;
        uzytkownik.ustawLogin(login); // tu chcemy dostaæ sie do loginu - pobieramy z metody (cin) login i chemy zmienić jego wartość na nową w klasie setter
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);   //tu chcemy pobrac login z klasy i go tu zwrócić getter

    string haslo;
    cout << "Podaj haslo: ";
    cin>>haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}
int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}
bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    for(int i = 0; i <uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzLogin() ==login) //to do logowania zamiast itr
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
        return true;
        }
    }
    return false;
}
void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{
    for(int i = 0; i <uzytkownicy.size(); i++)
    {
        cout << uzytkownicy[i].pobierzId() <<endl;
        cout << uzytkownicy[i].pobierzLogin() <<endl;
        cout << uzytkownicy[i].pobierzHaslo() <<endl;
    }
}
int UzytkownikMenedzer::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";

    cout << endl << "Podaj login: ";
    cin.sync();
    login = MetodyPomocnicze::wczytajLinie();

    for(int i = 0; i <uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzLogin() ==login)
   /* vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); // zamiast itr for jak wyżej
    while (itr != uzytkownicy.end())
    {
        if (itr -> login == login)*/
        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--)
            {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocnicze::wczytajLinie();

if(uzytkownicy[i].pobierzHaslo() ==haslo)
             {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika = uzytkownicy[i].pobierzId();
                    return idZalogowanegoUzytkownika;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
            return 0;
        }
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return 0;
}

void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocnicze::wczytajLinie();

   /* for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++) // itr na for
    {
        if (itr -> id == idZalogowanegoUzytkownika)*/
    for(int i = 0; i <uzytkownicy.size(); i++)
    {
        if(uzytkownicy[i].pobierzId()==idZalogowanegoUzytkownika)
        {
            uzytkownicy[i].ustawHaslo(noweHaslo);
            //itr -> haslo = noweHaslo;
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

bool UzytkownikMenedzer::czyUzytkownikJestZalogowany()
{
    if(idZalogowanegoUzytkownika>0)
        return true;
    else
        return false;
}
 void UzytkownikMenedzer::wylogujUzytkownika()
 {
    idZalogowanegoUzytkownika = 0;
 }

 int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika()
 {
     return idZalogowanegoUzytkownika;
 }
