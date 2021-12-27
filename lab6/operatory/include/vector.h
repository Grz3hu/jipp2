#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
using namespace std;

class Vector{
private:
    double x, y;
    
public:
    Vector(); 
    Vector(double x, double y) : x(x), y(y) {};
    double length();
    void print();
    friend ostream& operator<<(ostream& os, const Vector& rhs);
    friend Vector operator+(const Vector &lhs, const Vector &rhs);
    friend void operator+=(Vector &lhs, const Vector &rhs);
    friend Vector operator-(const Vector &lhs, const Vector &rhs);
    friend Vector operator-(const Vector &rhs);
    friend void operator-=(Vector &lhs, const Vector &rhs);
    friend Vector operator*(const Vector &rhs, const double &lhs);
    friend Vector operator*(const double &lhs, const Vector &rhs);
    friend double operator*(const Vector &lhs, const Vector &rhs);
    friend bool operator==(const Vector &lhs, const Vector &rhs);
};

#endif