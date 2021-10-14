#include <iostream>

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

	return 0;
}
