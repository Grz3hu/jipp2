#ifndef CHESS_H
#define CHESS_H

#include <iostream>
#include <string>

#define WHITE 0
#define BLACK 1

#define DEAD 0
#define ALIVE 1

#define a 0
#define b 1
#define c 2
#define d 3
#define e 4
#define f 5
#define g 6
#define h 7

class Board;
class Point;

enum Figure {
    PAWN,
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

class Point
{
    protected:
        int Xcord;
        int Ycord;

    public:
        Point() {};
        Point(int Xcord, int Ycord);
        int getXCord();
        int getYCord();
        void setXCord(int Xcord);
        void setYCord(int Ycord);
        friend Point operator+(const Point &lhs, const Point &rhs);
        friend Point operator-(const Point &lhs, const Point &rhs);
        friend void operator+=(Point &lhs, const Point &rhs);
};

class Piece : public Point
{
    protected:
        bool color;
        bool state=ALIVE;
        std::string symbol=" ";
        Figure figureType;
        unsigned long long int moves=0;
    public:
        Piece(int XCord, int YCord, bool color, Figure figureType);
        bool getColor();
        bool getState();
        Figure getFigureType();
        void setColor(bool color);
        void setState(bool state);
        std::string getSymbol(); 
        bool isMoveValid(Board &gameboard, Point oldPos, Point newPosVect);
};

class Board
{
    private:
        Piece*** chessboard;
        unsigned long long int moves=0;
    
    public:
        Board();
        ~Board();
        void drawBoard();
        bool isMoveVaild(Point pos,bool color);
        int move(Point src, Point dest);
        Piece* getPieceAt(int X, int Y);

    friend class Piece;
};

#endif