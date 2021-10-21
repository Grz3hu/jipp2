#include <iostream>

using namespace std;

int main()
{
	int a,b;
	cout << "Podaj dwie liczby naturalne:\n";
	cin >> a >> b;

	try 
	{      
		if(b==0)
		throw "Dzielenie przez 0";

		if(a%b!=0)
		throw "Wynik nie jest liczba naturalna"; 

		cout << a/b;
	}
	catch(const char* msg)
	{                        
		cout << msg << endl;
	}
	
	return 0;
}
