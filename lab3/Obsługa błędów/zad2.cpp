#include <iostream>
#include <string>

using namespace std;

void konwersja()
{
	string tekst;
	getline(cin,tekst);
	try
	{
		int w=stoi(tekst);

		cout << stoi(tekst);
	}
	catch(invalid_argument)
	{
		cout << "Wprowadzony ciąg zawiera nieprawidłowe znaki\n";
	}
	catch(out_of_range)
	{
		cout << "Wprowadzona liczba jest za duża\n";
	}
}

int main()
{
	konwersja();

	return 0;
}
