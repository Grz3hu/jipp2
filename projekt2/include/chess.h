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
class Piece;

//! An enum.
/*! Chess figures */
enum Figure {
    PAWN, //pawn is separate class 
    ROOK,
    KNIGHT,
    BISHOP,
    QUEEN,
    KING
};

//A class representing point
class Point
{
    protected:
        int Xcord;/**< variable holding X position coordinate */
        int Ycord;/**< variable holding Y position coordinate */ 
    public:
        /*
        * Default constructor
        */
        Point(){};

        /**
        * Constructor setting class member values
        *
        * @param Xcord new Xcord value
        * @param Ycord new Ycord value
        */
        Point(int Xcord, int Ycord);

        /**
        * Getter of the Xcord value
        *
        * @return Xcord value
        */
        int getXCord();

        /**
        * Getter of the Ycord value
        *
        * @return Ycord value
        */
        int getYCord();
        
        /**
        * Setter of the Xcord Value
        *
        * @param Xcord new Xcord value
        */
        void setXCord(int Xcord);

        /**
        * Setter of the Xcord Value
        *
        * @param Ycord new Ycord value
        */
        void setYCord(int Ycord);

        /**
        * Sum of two points
        * It sums one member form another 
        * a.x + b.x, a.y + b.y 
        *
        * @param lhs point on the left side
        * @param rhs point on the right side
        */
        friend Point operator+(const Point &lhs, const Point &rhs);

        /**
        * Subtration of two points
        * It subtracts one member form another
        * a.x - b.x, a.y - b.y 
        *
        * @param lhs point on the left side
        * @param rhs point on the right side
        */
        friend Point operator-(const Point &lhs, const Point &rhs);

        /**
        * Sum of two points
        * It adds one member to another
        * a.x += b.x,
        * a.y += b.y 
        *
        * @param lhs point on the left side
        * @param rhs point on the right side
        */
        friend void operator+=(Point &lhs, const Point &rhs);
};

//A class representing chess piece
class Piece : public Point
{
protected:
    bool color;/**< variable holding piece color */
    bool state = ALIVE;/**< variable holding piece state (DEAD or ALIVE) */
    std::string symbol = " ";/**< variable holding piece symbol (in unicode)*/
    Figure figureType;/**< variable holding piece type (check figure enum for possible types)*/

public:
    /**
    * Constructor setting class member values
    *
    * @param Xcord new Xcord value
    * @param Ycord new Ycord value
    * @param color new color value
    * @param figureType new figureType value
    */
    Piece(int XCord, int YCord, bool color, Figure figureType);

    /**
    * Getter of the color value
    *
    * @return color value
    */
    bool getColor();

    /**
    * Getter of the state value
    *
    * @return state value
    */
    bool getState();

    /**
    * Getter of the figureType value
    *
    * @return figureType value
    */
    Figure getFigureType();

    /**
    * Getter of the symbol value
    *
    * @return symbol value
    */
    std::string getSymbol();

    /**
    * Setter of the color member
    *
    * @param color new color value
    */
    void setColor(bool color);

    /**
    * Setter of the color member
    *
    * @param state new state value
    */
    void setState(bool state);

    /**
    * Setter of the color member
    *
    * @param gameboard new state value
    * @param oldPos where the piece is
    * @param newPosVect VECTOR that will be added to oldPos
    * @return true if move is valid, false if not
    */
    virtual bool isMoveValid(Board &gameboard, Point oldPos, Point newPosVect);
};

class Pawn : public Piece{
    private:
        unsigned long long int moves = 0;/**< variable holding number of piece moves */
    public:
        /**
        * Constructor setting class member values
        *
        * @param Xcord new Xcord value
        * @param Ycord new Ycord value
        * @param color new color value
        */
        Pawn(int XCord, int YCord, bool color);

        /**
        * Setter of the color member
        *
        * @param gameboard new state value
        * @param oldPos where the piece is
        * @param newPosVect VECTOR that will be added to oldPos
        * @return true if move is valid, false if not
        */
        bool isMoveValid(Board &gameboard, Point oldPos, Point newPosVect);
};

//A class representing chess board
class Board
{
private:
    Piece ***chessboard;/**< variable holding 2d array of pieces representing the board */

public:
    /**
    * Board Constructor 
    * it allocates space for chessboard member
    */
    Board();

    /**
    * Board Constructor 
    * it frees space taken by chessboard member
    */
    ~Board();

    /**
    * Draws board with pieces to stdout
    */
    void drawBoard();

    /**
    * Validates if the pos is within board scope and if the param color isnt the same as the one on pos
    * @param pos point representing position to check
    * @param color color of the piece we want to move
    * @return true if move is valid, false if not
    */
    bool isMoveVaild(Point pos, bool color);

    /**
    * Move piece from src to dest and check if its legal (doesnt check for checkmate)
    * @param src point representing source position
    * @param dest point representing destination position
    * @return -1 on failure, 0 on success
    */
    int move(Point src, Point dest);

    /**
    * Return piece at chessboard[Y][X]
    * @param X represents column
    * @param Y represents row
    * @return pointer to piece at chessboard[Y][X]
    */
    Piece *getPieceAt(int X, int Y);

    /**
    * Return piece at chessboard[pos.getYCord()][pos.getXCord()]
    * @param pos represents piece position
    * @return pointer to piece at pos
    */
    Piece *getPieceAt(Point pos);

    //allows piece to access chessboard
    friend class Piece;
    friend class Pawn;
};

#endif