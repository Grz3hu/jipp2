#include "triangle.h"
#include <cmath>

using namespace std;

string Triangle::getNazwa() const
{
    return nazwa;
}

void Triangle::setNazwa(string nazwa)
{
    this->nazwa = nazwa;
}

void Triangle::display() const
{
    cout << nazwa << endl
         << a << b << c;
}

ostream &operator<<(ostream &lhs, const Triangle &rhs)
{
    rhs.display();
    return lhs;
}

double Triangle::distance(int firstPointIndex, int secondPointIndex) const
{
    Node tab[3] = {a, b, c};
    double xa, xb, ya, yb;
    xa = tab[firstPointIndex].getX();
    xb = tab[secondPointIndex].getX();
    ya = tab[firstPointIndex].getY();
    yb = tab[secondPointIndex].getY();

    return sqrt(pow(xb - xa, 2) + pow(yb - ya, 2));
};

void Triangle::showTriangleData(Triangle triangle){
    triangle.display();
};

void Triangle::showTriangleData(Triangle& triangle){
    triangle.display();
};

void Triangle::showTriangleData(Triangle* triangle){
    triangle->display();
};