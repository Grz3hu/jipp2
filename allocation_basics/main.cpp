#include <iostream>
#include <string.h>

using namespace std;

int toint(char a)
{
	return a - '0';
}

int main(int argc, char* argv[])
{
	int *n = new int;
	int k;

	cout << n << endl;
	cout << *n << endl;
	cout << &n << endl;
	cout << &k << endl;

	delete n;

	int *tab = new int[5];
	delete[] tab;

	int **tab2 = new int*[5]; //tablica 5*5
	for(int i=0;i<5;++i) {
		tab2[i] = new int[5];
	}

	for(int i=0;i<5;++i) {
		delete tab2[i];
	}

	delete[] tab2;

	int tab3[3] = {3,2,1};

	for(int i=0;i<argc;++i) {
		cout << argv[i] << " ";
	}
	cout << endl;
	//Program

	if(argc < 2)
		return 0;

	if (strcmp(argv[1], "add") == 0)
	{
		int w=(int)argv[2] + (int)argv[3] - 96;
		cout << w << endl;
	}
	if (strcmp(argv[1], "subtract") == 0)
	{
		int w=(int)argv[2] - (int)argv[3] - 96;
		cout << w << endl;
	}
	if (strcmp(argv[1], "volume") == 0)
	{
		//2-a 3-b 4-h 5-H
		int w=((toint(argv[2]) + toint(argv[3]))*toint(argv[4])/2) * toint(argv[5]);
		cout << w << endl;
	}
	if (strcmp(argv[1], "help") == 0)
	{
		cout << "add - dodawanie dwóch liczb" << "\n";
		cout << "subtract - odejmowanie dwóch liczb" << "\n";
		cout << "volume - obliczanie objętości graniastosłupa prostego o podstawie trapezu" << "\n";
		cout << "help - wyświetlanie dokumentacji" << "\n";
	}

	return 0;
}
