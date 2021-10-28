#include <iostream>

using namespace std;

struct samochod{
	string marka;
	string model;
	int rok_prod;
	string kolor;
	int predkosc_max;
};

int printSameProducent(samochod a[], int n)
{
	int licznik=1;
	for(int i=1;i<n;i++)
	{
		if(a[0].marka==a[i].marka)
			licznik++;
	}
	return licznik;
}

unsigned int minRokProd(samochod a[], int n)
{
	int min=a[0].rok_prod;
	int mini=0;
	for(int i=1;i<n;i++)
	{
		if(a[i].rok_prod<min)
		{
			min=a[i].rok_prod;
			mini=i;
		}
	}
	return mini;
}

void set_samochod(samochod& a, string marka, string model, int rok_prod, string kolor, int predkosc_max)
{
	a.marka=marka;
	a.model=model;
	a.rok_prod=rok_prod;
	a.kolor=kolor;
	a.predkosc_max=predkosc_max;
}

int main()
{
	samochod auto1;
	samochod auto2;
	samochod auto3;
	samochod auto4;

	set_samochod(auto1,"Ford","Escort",1999,"Niebieski",200);
	set_samochod(auto2,"Audi","TT",2000,"Niebieski",250);
	set_samochod(auto3,"Lamborghini","Gallardo",2004,"Czerwony",300);
	set_samochod(auto4,"Ford","Escort",1999,"Niebieski",200);

	samochod tab_aut[]={auto1,auto2,auto3,auto4};

	cout << printSameProducent(tab_aut, 4) << endl;
	cout << minRokProd(tab_aut, 4) << endl;

	return 0;
}
