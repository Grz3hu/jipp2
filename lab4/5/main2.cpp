#include <iostream>
#include <math.h>

using namespace std;

class Punkt{
	public:
		int x;
		int y;
	
		Punkt(int x, int y);
		double distance(Punkt a);
};

Punkt::Punkt(int x,int y){
	this->x=x;
	this->y=y;
}

double Punkt::distance(Punkt a){
	return sqrt(pow(a.x-this->x,2)+pow(a.y-this->y,2));
}


class Figura{
	public:
		int w;
		Punkt* wierzcholki;
		Figura(int w, Punkt* wierzcholki);
};

Figura::Figura(int w, Punkt* wierzcholki){
	this->wierzcholki=wierzcholki;
	this->w=w;
}

int main()
{
	return 0;
}
