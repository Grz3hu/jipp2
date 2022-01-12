#include "chess.h"

//Point definitions 
Point::Point(int Xcord, int Ycord) : Xcord(Xcord), Ycord(Ycord)
{
    this->Xcord = Xcord;
    this->Ycord = Ycord;
}

int Point::getXCord()
{
    return this->Xcord;
}

int Point::getYCord()
{
    return this->Ycord;
}

void Point::setXCord(int XCord)
{
    this->Xcord = Xcord;
}

void Point::setYCord(int YCord)
{
    this->Ycord = Ycord;
}

Point operator+(const Point &lhs, const Point &rhs)
{
    return Point(lhs.Xcord + rhs.Xcord, lhs.Ycord + rhs.Ycord);
}

Point operator-(const Point &lhs, const Point &rhs)
{
    return Point(lhs.Xcord - rhs.Xcord, lhs.Ycord - rhs.Ycord);
}

void operator+=(Point &lhs, const Point &rhs)
{
    lhs.Xcord += rhs.Xcord;
    lhs.Ycord += rhs.Ycord;
}