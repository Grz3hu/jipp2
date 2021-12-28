#include "chess.h"

using namespace std;

//Piece definitions
Piece::Piece(int XCord, int YCord, bool color, Figure figureType) : Point(XCord, YCord), color(color), figureType(figureType)
{
    switch (figureType)
    {
    case PAWN:
        this->symbol = this->color ? "♙" : "♟︎";
        break;

    case ROOK:
        this->symbol = this->color ? "♖" : "♜";
        break;

    case KNIGHT:
        this->symbol = this->color ? "♘" : "♞";
        break;

    case BISHOP:
        this->symbol = this->color ? "♗" : "♝";
        break;

    case KING:
        this->symbol = this->color ? "♔" : "♚";
        break;

    case QUEEN:
        this->symbol = this->color ? "♕" : "♛";
        break;
    }
}

bool Piece::getColor()
{
    return this->color;
}

string Piece::getSymbol()
{
    return this->symbol;
}

Figure Piece::getFigureType()
{
    return this->figureType;
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


bool Piece::isMoveValid(Board &gameboard, Point oldPos, Point newPosVect)
{
    /* int newPosX = this->Xcord + newPosVect.getXCord(); */
    /* int newPosY = this->Ycord + newPosVect.getYCord(); */
    int newPosX = oldPos.getXCord() + newPosVect.getXCord();
    int newPosY = oldPos.getYCord() + newPosVect.getYCord();

    if (gameboard.isMoveVaild(Point(newPosX,newPosY), this->color) == false)
        return false;

    //no movement
    if (newPosVect.getXCord() == 0 && newPosVect.getYCord() == 0)
        return false;

    if (this->figureType == PAWN)
    {
        if (this->color == WHITE)
        {
            if ((newPosVect.getXCord() == -1 || newPosVect.getXCord() == 1) && newPosVect.getYCord() == 1 && gameboard.chessboard[newPosY][newPosX]->getColor() == BLACK)
                return true;

            if (moves == 0 && newPosVect.getXCord() == 0 && newPosVect.getYCord() == 2 && gameboard.chessboard[newPosY][newPosX]==nullptr)
                return true;

            if (newPosVect.getXCord() == 0 && newPosVect.getYCord() == 1 && gameboard.chessboard[newPosY][newPosX]==nullptr)
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

    if (this->figureType == ROOK || this->figureType == QUEEN)
    {
        if (this->figureType == ROOK && newPosVect.getXCord() != 0 && newPosVect.getYCord() != 0)
            return false;

        //moving vertically
        if (newPosVect.getXCord() == 0)
        {
            //up
            if (newPosY > this->getYCord())
            {
                for (int y = this->getYCord() + 1; y < newPosY; y++)
                {
                    if (gameboard.chessboard[y][newPosX] != nullptr)
                        return false;
                }
                return true;
            }

            //down
            if (newPosY < this->getYCord())
            {
                for (int y = this->getYCord() - 1; y > newPosY; y--)
                {
                    if (gameboard.chessboard[y][newPosX] != nullptr)
                        return false;
                }
                return true;
            }
        }

        //moving horizontally
        if (newPosVect.getYCord() == 0)
        {
            //right
            if (newPosX > this->getXCord())
            {
                for (int x = this->getXCord() + 1; x < newPosX; x++)
                {
                    if (gameboard.chessboard[newPosY][x] != nullptr)
                        return false;
                }
                return true;
            }

            //left
            if (newPosX < this->getYCord())
            {
                for (int x = this->getYCord() - 1; x > newPosX; x--)
                {
                    if (gameboard.chessboard[newPosY][x] != nullptr)
                        return false;
                }
                return true;
            }
        }
    }

    if (this->figureType == KNIGHT)
    {
        if ((newPosVect.getXCord() == 1 || newPosVect.getXCord() == -1) && (newPosVect.getYCord() == 2 || newPosVect.getYCord() == -2))
            return true;

        if ((newPosVect.getYCord() == 1 || newPosVect.getYCord() == -1) && (newPosVect.getXCord() == 2 || newPosVect.getXCord() == -2))
            return true;

        return false;
    }

    if (this->figureType == BISHOP || this->figureType == QUEEN)
    {
        //   X
        //  X
        // X
        if (oldPos.getXCord() == newPosVect.getXCord())
        {
            //down
            if (newPosX < this->Xcord)
            {
                for (int x = this->Xcord; x > newPosX; x--)
                    if (gameboard.chessboard[this->Ycord - (this->Xcord - x)][x] != nullptr)
                        return false;
                return true;
            }

            //up
            if (newPosX > this->Xcord)
            {
                for (int x = this->Xcord; x < newPosX; x++)
                    if (gameboard.chessboard[this->Ycord + (this->Xcord - x)][x] != nullptr)
                        return false;
                return true;
            }
        }

        // X
        //  X
        //   X
        if (oldPos.getXCord() == -newPosVect.getXCord())
        {
            //down
            if (newPosX < this->Xcord)
            {
                for (int x = this->Xcord; x < newPosX; x++)
                    if (gameboard.chessboard[this->Ycord - (this->Xcord - x)][x] != nullptr)
                        return false;
                return true;
            }

            //up
            if (newPosX > this->Xcord)
            {
                for (int x = this->Xcord; x > newPosX; x--)
                    if (gameboard.chessboard[this->Ycord + (this->Xcord - x)][x] != nullptr)
                        return false;
                return true;
            }
        }

        return false;
    }

    if (this->figureType == KING)
    {
        if ( (newPosVect.getXCord() == 1 || newPosVect.getXCord() == -1) && (newPosVect.getYCord() == 1 || newPosVect.getYCord() == -1) )
            return true;
    }
    
    return false;
}