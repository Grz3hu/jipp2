#include <iostream>

using namespace std;

/**
 * Opis funkcji
 * @param name opis parametru
 */
double fun2(double x, double y, double z)
{
	return (3*x+5*y*y)/((x*y)-z);
}

int main()
{
	double a,b,c;
	cout << "Podaj: a \n";
	cin >> a; 
	cout << "Podaj: b \n";
	cin >> b; 
	cout << "Podaj: c \n";
	cin >> c; 

	cout << fun2(a,b,c) << " " << endl;

	return 0;
}
