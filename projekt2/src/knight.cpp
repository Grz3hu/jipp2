#include "chess.h"

Knight::Knight(int XCord, int YCord, bool color) : Piece(XCord, YCord, color)
{
    this->symbol = this->color ? "♞" : "♘";
}

bool Knight::isMoveValid(Board &gameboard, Point newPosVect)
{
    int newPosX = this->Xcord + newPosVect.getXCord();
    int newPosY = this->Ycord + newPosVect.getYCord();

    if (gameboard.isMoveVaild((Point)(*this) + newPosVect, this->color) == false)
        return false;
    
    if (newPosVect.getXCord() == 0 && newPosVect.getYCord() == 0)
        return false;
    
    if ((newPosVect.getXCord() == 1 || newPosVect.getXCord() == -1) && (newPosVect.getYCord() == 2 || newPosVect.getYCord() == -2))
        return true;

    if ((newPosVect.getYCord() == 1 || newPosVect.getYCord() == -1) && (newPosVect.getXCord() == 2 || newPosVect.getXCord() == -2))
        return true;
    
    return false;
}