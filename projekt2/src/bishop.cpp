#include "chess.h"

Bishop::Bishop(int XCord, int YCord, bool color) : Piece(XCord, YCord, color)
{
    this->symbol = this->color ? "♗" : "♝";
}

bool Bishop::isMoveValid(Board &gameboard, Point newPosVect)
{
    int newPosX = this->Xcord + newPosVect.getXCord();
    int newPosY = this->Ycord + newPosVect.getYCord();

    if (gameboard.isMoveVaild((Point)(*this) + newPosVect, this->color) == false)
        return false;
    
    if (newPosVect.getXCord() == 0 && newPosVect.getYCord() == 0)
        return false;

    //   X
    //  X
    // X
    if (newPosVect.getXCord() == newPosVect.getXCord())
    {
        //down
        if(newPosX<this->Xcord)
            for(int x=this->Xcord; x>newPosX; x--)
                if(gameboard.chessboard[this->Ycord-(this->Xcord-x)][x]!=nullptr)
                    return false;

        //up
        if(newPosX>this->Xcord)
            for(int x=this->Xcord; x<newPosX; x++)
                if(gameboard.chessboard[this->Ycord+(this->Xcord-x)][x]!=nullptr)
                    return false;
    }

    // X
    //  X
    //   X
    if (newPosVect.getXCord() == -newPosVect.getXCord())
    {
        //down
        if(newPosX<this->Xcord)
            for(int x=this->Xcord; x<newPosX; x++)
                if(gameboard.chessboard[this->Ycord-(this->Xcord-x)][x]!=nullptr)
                    return false;

        //up
        if(newPosX>this->Xcord)
            for(int x=this->Xcord; x>newPosX; x--)
                if(gameboard.chessboard[this->Ycord+(this->Xcord-x)][x]!=nullptr)
                    return false;
    }

    return true;
}