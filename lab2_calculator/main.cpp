#include <iostream>

using namespace std;

int main(int argc, char* argv)
{
	//Program
	//TODO toint na atoi
	//osobny folder na zadanko lab2

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
		cout << "add [a] [b] - dodawanie dwóch liczb" << "\n";
		cout << "subtract [a] [b] - odejmowanie dwóch liczb" << "\n";
		cout << "volume [a] [b] [h] [H] - obliczanie objętości graniastosłupa prostego o podstawie trapezu" << "\n";
		cout << "help - wyświetlanie dokumentacji" << "\n";
	}

	return 0;
}
