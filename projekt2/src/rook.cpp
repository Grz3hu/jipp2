#include "chess.h"

Rook::Rook(int XCord, int YCord, bool color) : Piece(XCord, YCord, color)
{
    this->symbol = this->color ? "♜" : "♖";
}

bool Rook::isMoveValid(Board &gameboard, Point newPosVect)
{
    int newPosX = this->Xcord + newPosVect.getXCord();
    int newPosY = this->Ycord + newPosVect.getYCord();

    if (gameboard.isMoveVaild((Point)(*this) + newPosVect, this->color) == false)
        return false;
    
    if(newPosVect.getXCord()!=0 && newPosVect.getYCord()!=0)
        return false;
    
    if (newPosVect.getXCord() == 0 && newPosVect.getYCord() == 0)
        return false;

    //moving vertically
    if (newPosVect.getXCord() == 0)
    {
        //up
        if (newPosY > this->getYCord())
            for (int y = this->getYCord() + 1; y < newPosY; y++)
            {
                if (gameboard.chessboard[y][newPosX] != nullptr)
                    return false;
            }

        //down
        if (newPosY < this->getYCord())
            for (int y = this->getYCord() - 1; y > newPosY; y--)
            {
                if (gameboard.chessboard[y][newPosX] != nullptr)
                    return false;
            }
    }

    //moving horizontally
    if (newPosVect.getYCord() == 0)
    {
        //right
        if (newPosX > this->getXCord())
            for (int x = this->getXCord() + 1; x < newPosX; x++)
            {
                if (gameboard.chessboard[newPosY][x] != nullptr)
                    return false;
            }

        //left
        if (newPosX < this->getYCord())
            for (int x = this->getYCord() - 1; x > newPosX; x--)
            {
                if (gameboard.chessboard[newPosY][x] != nullptr)
                    return false;
            }
    }
    
    return true;
}