#include "chess.h"

using namespace std;

//Piece definitions
bool Piece::getColor()
{
    return this->color;
}

bool Piece::getState()
{
    return this->state;
}

void Piece::setColor(bool color)
{
    this->color = color;
}

void Piece::setState(bool state)
{
    this->state = state;
}

string Piece::getSymbol()
{
    return this->symbol;
}