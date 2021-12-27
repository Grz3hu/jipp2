#include "chess.h"

Pawn::Pawn(int XCord, int YCord, bool color) : Piece(XCord, YCord, color)
{
    this->symbol = this->color ? "♟︎" : "♙";
}

bool Pawn::isMoveValid(Board &gameboard, Point newPosVect)
{
    int newPosX = this->Xcord + newPosVect.getXCord();
    int newPosY = this->Ycord + newPosVect.getYCord();

    if (gameboard.isMoveVaild((Point)(*this) + newPosVect, this->color) == false)
        return false;
    
    if (newPosVect.getXCord() == 0 && newPosVect.getYCord() == 0)
        return false;

    if (this->color == WHITE)
    {
        if ((newPosVect.getXCord() == -1 || newPosVect.getXCord() == 1) && newPosVect.getYCord() == 1 && gameboard.chessboard[newPosY][newPosX]->getColor() == BLACK)
            return true;

        if (moves == 0 && newPosVect.getXCord() == 0 && newPosVect.getYCord() == 2)
            return true;

        if (newPosVect.getXCord() == 0 && newPosVect.getYCord() == 1)
            return true;
    }

    if (this->color == BLACK)
    {
        //taking the opponent
        if ((newPosVect.getXCord() == -1 || newPosVect.getXCord() == 1) && newPosVect.getYCord() == -1 && gameboard.chessboard[newPosY][newPosX]->getColor() == WHITE)
            return true;

        //first move
        if (moves == 0 && newPosVect.getXCord() == 0 && newPosVect.getYCord() == -2 && gameboard.chessboard[newPosY][newPosX] == nullptr)
            return true;

        //one step forward
        if (newPosVect.getXCord() == 0 && newPosVect.getYCord() == -1 && gameboard.chessboard[newPosY][newPosX] == nullptr)
            return true;
    }

    return false;
}