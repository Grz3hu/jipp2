#include <iostream>

using namespace std;

class Figure
{
	protected:
		string name;
		string color;

	public:
		Figure(string name, string color) : name(name), color(color) {}
};

class Rectangle : public Figure
{
	protected:
		unsigned int a;
		unsigned int b;

	public:
		Rectangle(string name, string color, unsigned int a, unsigned int b) : Figure(name,color), a(a), b(b) {}

		double Area()
		{
			return a * b;
		}

		unsigned int circuit(){
			return a+b;
		}
};

class Triangle : public Figure
{
	protected:
		unsigned int a;
		unsigned int b;
		unsigned int c;
		unsigned int h;

	public:
		Triangle(string name, string color, unsigned int a, unsigned int b, unsigned int c, unsigned int h) : Figure(name,color), a(a), b(b), c(c), h(h) {}

		double Area()
		{
			return 0.5 * h * (double) (a + b);
		}
		unsigned int circuit(){
			return a+b+c;
		}
};

int main()
{
	Rectangle r1("a","green",2,2);
	Triangle t1("a","green",2,2,2,3);

	cout << r1.Area() << endl;
	cout << t1.Area() << endl;
	cout << r1.circuit() << endl;
	cout << t1.circuit() << endl;

	return 0;
}
