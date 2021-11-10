#include <iostream>

using namespace std;

/**
 * Opis funkci
 * @param name opis parametru
 */
void print(string name, int wiek)
{
	cout << name << " " << endl;
	cout << wiek << " " << endl;
}

int main()
{
	string name;
	short wiek;
	cout << "Podaj imie: \n";
	cin >> name;
	cout << "Podaj wiek: \n";
	cin >> wiek;
	/* cout << name << " " << endl; */

	string name_of_this_sth;
	string nameOfThisSth;

	print(name,wiek);

	return 0;
}
