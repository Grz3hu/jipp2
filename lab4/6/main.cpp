#include <iostream>
#include <math.h>
#include <cstdlib>

using namespace std;

class KlasaCL
{
public:
    KlasaCL();
    ~KlasaCL();
};

KlasaCL::KlasaCL()
{
    cout << "=> Konstruktor wywolany!" << endl;
}

KlasaCL::~KlasaCL()
{
    cout << "=> Destruktor wywolany!" << endl;
}

int main()
{
    KlasaCL * tKlasa;
	int tmp;
    cout << "Rezerwuje pamiec za pomoca new" << endl;
    tKlasa = new KlasaCL[1024];
    cout << "Wchodze do bloku {" << endl;
    {
        KlasaCL tKlasa;
    }
    cout << "Wyszedlem z bloku }" << endl;
    cout << "Zwalniam pamiec, ktora zostala zarezerwowana za pomoca new" << endl;
    delete tKlasa;
	cin >> tmp;
    return( 0 );
}
