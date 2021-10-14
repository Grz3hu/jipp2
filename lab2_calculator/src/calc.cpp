#include "calc.h"
#include <iostream>

using namespace std;

int add(int a, int b){
	return a+b;
}

int subtract(int a, int b)
{
	return a-b;
}

int volume(int a, int b, int h, int H)
{
	return (h*(a+b)/2)*H;
}

void print_help()
{
		cout << "Simple calculator\nsimpleCalc [nazwa działania]\n\nDziałania:\n";
		cout << "add [a] [b] - dodawanie dwóch liczb całkowitych" << "\n";
		cout << "subtract [a] [b] - odejmowanie dwóch liczb całkowitych" << "\n";
		cout << "volume [a] [b] [h] [H] - obliczanie objętości graniastosłupa prostego o podstawie trapezu" << "\n";
		cout << "help - wyświetlanie dokumentacji" << "\n";
}
