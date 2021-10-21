#include <iostream>

using namespace std;

void bubble(int t[], int s)
{
	for(int i=0;i<s;i++)
		for(int j=0;j<s-i-1;j++)
			if(t[j]>t[j+1])
				swap(t[j],t[j+1]);
}

void zad4(int w,int* a)
{
	*a=w;
}

int main()
{
	int* a = new int;
	int* b = new int;

	cin >> *a >> *b;
	cout << *a << " " << *b << "\nsrednia: " << (*a + *b)/2 << endl;

	int* t = new int[5];
	for(int i=0;i<5;i++)
	{
		cout << "Podaj " << i << " element: \n";
		cin >> t[i];
	}

	for(int i=0;i<5;i++)
		if(t[i]>0)
			cout << t[i] << " ";

	cout << endl;
	bubble(t,5);

	cout << endl;
	for(int i=0;i<5;i++)
		cout << t[i] << " ";

	int* w = new int;
	zad4(2,w);
	cout << endl << *w << endl;

	return 0;
}
