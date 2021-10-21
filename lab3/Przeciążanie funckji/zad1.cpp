#include <iostream>

using namespace std;

int pole(int a) //pole kwadratu
{
	return a*a;
}

int pole(int a, int b) //pole prostokąta
{
	return a*b;
}

int main()
{
	cout << pole(1) << endl;
	cout << pole(1,2) << endl;

	return 0;
}
