#ifndef AUTO_H 
#define AUTO_H 

#include <iostream>

using namespace std;

class Auto{
private:
    string nrRej;
    string nazwa;
    int iloscMiejsc;
    string* tabImieNaz;
    string marka;
    string typ;
    static string najnowsza_wersja_oprogramowania;
    string zainstalowana_wersja_oprogramowania="v1.0";

public:
    Auto(string nrRej, string nazwa, int iloscMiejsc, string marka, string typ);
    Auto(Auto &a);
    void Print() const;
    void zmienPas(int nrMiejsca, string info);
    string getNazwa();
    string getNrRej();
    string getMarka();
    string getTyp();
    void setNazwa(string nazwa);
    void setNrRej(string nrRej);
    void printSoft();
    void updateSoft();
    static void opublikujNoweOprogramowanie(const string newSoft);
};

#endif