#include "chess.h"

Queen::Queen(int XCord, int YCord, bool color) : Piece(XCord, YCord, color)
{
    this->symbol = this->color ? "♕" : "♛";
}