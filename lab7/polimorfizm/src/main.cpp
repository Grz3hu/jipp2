#include <iostream>
#include <cmath>

using namespace std;

class Figure
{
	protected:
		string name;
		string color;

	public:
		Figure(string name, string color) : name(name), color(color) {}
		virtual double getArea() = 0; //Przypisujemy 0, aby nie było ciała metody
};

class Rectangle : public Figure
{
	protected:
		unsigned int a;
		unsigned int b;

	public:
		Rectangle(string name, string color, unsigned int a, unsigned int b) : Figure(name,color), a(a), b(b) {}

		double getArea()
		{
			return a * b;
		}

		unsigned int circuit(){
			return a+b;
		}
};

class Circle : public Figure
{
	protected:
		unsigned int r;

	public:
		Circle(string name, string color, unsigned int r) : Figure(name,color), r(r) {}

		double getArea()
		{
			return M_PI*r*r;
		}
		unsigned int circuit(){
			return M_PI*r*2;
		}
};

int main()
{
	Figure *circle = new Circle("c1","green",5);
	Figure *rectangle = new Rectangle("c1","green",5,5);

	cout << "Circle area: " << circle->getArea() << endl;
	cout << "Rectangle area: " << rectangle->getArea() << endl;
	return 0;
}
