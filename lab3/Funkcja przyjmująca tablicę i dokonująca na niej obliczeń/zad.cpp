#include <iostream>
#include <algorithm> //swap
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */

using namespace std;

//zad1
int losuj(int a, int b) //assert b>a 
{
	return a+rand()%(b+1-a); //<a,b>
}

int maxt(int t[], int s)
{
	int max=t[0];
	for(int i=1; i<s; i++)
	{
		if(t[i]>max)
			max=t[i];
	}
	return max;
}

void odwrt(int t[], int s)
{
	for(int i=0;i<s/2;i++)
		swap(t[i],t[s-1-i]);
}

int main()
{
	srand (time(NULL));
	
	int* t=new int[20];
	for(int i=0;i<20;i++)
	{
		t[i]=losuj(1,100);
		cout << t[i] << " ";
	}
	cout << endl << maxt(t,20) << endl << endl;

	odwrt(t,20);

	for(int i=0;i<20;i++)
		cout << t[i] << " ";

	cout << endl;

	return 0;
}
