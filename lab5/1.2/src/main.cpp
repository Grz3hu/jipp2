#include <iostream>
#include "auto.h"

using namespace std;

int main() {
    Auto auto1("SC5512", "Fiesta", 5, "Ford", "Osobowe");
    auto1.zmienPas(1,"Kuba");
    auto1.Print();
    
    Auto auto1Copy=auto1;
    auto1Copy.SetNazwa("Mondeo");
    auto1Copy.SetNrRej("SC6123");
    auto1Copy.zmienPas(0,"kierowca");
    auto1.zmienPas(1,"Andrzej");
    auto1Copy.Print();

    return 0;
}