#include <cmath>
#include "vector.h"

using namespace std;

double Vector::length()
{
    return sqrt(x * x + y * y);
}

void Vector::print()
{
    cout << "x: " << x << " y: " << y << endl;
}

ostream &operator<<(ostream &lhs, const Vector &rhs)
{
    cout << "x:" << rhs.x << " y:" << rhs.y << endl;
    return lhs;
}

Vector operator+(const Vector &lhs, const Vector &rhs)
{
    return Vector(lhs.x + rhs.x, lhs.y + rhs.y);
}

void operator+=(Vector &lhs, const Vector &rhs)
{
    lhs.x += rhs.x;
    lhs.y += rhs.y;
}

Vector operator-(const Vector &lhs, const Vector &rhs)
{
    return Vector(lhs.x - rhs.x, lhs.y - rhs.y);
}

Vector operator-(const Vector &rhs)
{
    return {-rhs.x, -rhs.y};
}

void operator-=(Vector &lhs, const Vector &rhs)
{
    lhs.x -= rhs.x;
    lhs.y -= rhs.y;
}

Vector operator*(const Vector &rhs, const double &lhs)
{
    return Vector(lhs * rhs.x, lhs * rhs.y);
}

Vector operator*(const double &lhs, const Vector &rhs)
{
    return Vector(lhs * rhs.x, lhs * rhs.y);
}

double operator*(const Vector &rhs, const Vector &lhs)
{
    return (lhs.y * rhs.x) + (lhs.x * rhs.y);
}

bool operator==(const Vector &lhs, const Vector &rhs)
{
    return (lhs.x == rhs.x && lhs.y == rhs.y);
}