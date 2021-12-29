#include "chess.h"

using namespace std;

Board::Board()
{
    chessboard = new Piece **[8];
    for (int i = 0; i < 8; i++)
    {
        chessboard[i] = new Piece *[8];
    }

    //empty space (middlegrounds)
    for (int i = 2; i < 6; i++)
        for (int j = a; j <= h; j++)
            chessboard[i][j] = nullptr;

    //spawn pawns
    for (int i = a; i <= h; i++)
    {
        //polymorphism
        chessboard[6][i] = new Pawn(i, 6, BLACK);
        chessboard[1][i] = new Pawn(i, 1, WHITE);
    }

    //spawn rooks
    chessboard[7][a] = new Piece(a, 7, BLACK, ROOK);
    chessboard[7][h] = new Piece(h, 7, BLACK, ROOK);
    chessboard[0][a] = new Piece(a, 7, WHITE, ROOK);
    chessboard[0][h] = new Piece(h, 7, WHITE, ROOK);

    //spawn knights
    chessboard[7][b] = new Piece(b, 7, BLACK, KNIGHT);
    chessboard[7][g] = new Piece(g, 7, BLACK, KNIGHT);
    chessboard[0][b] = new Piece(b, 7, WHITE, KNIGHT);
    chessboard[0][g] = new Piece(g, 7, WHITE, KNIGHT);

    //spawn bishops
    chessboard[7][c] = new Piece(c, 7, BLACK, BISHOP);
    chessboard[7][f] = new Piece(f, 7, BLACK, BISHOP);
    chessboard[0][c] = new Piece(c, 0, WHITE, BISHOP);
    chessboard[0][f] = new Piece(f, 0, WHITE, BISHOP);

    //spawn queens
    chessboard[7][d] = new Piece(d, 7, BLACK, QUEEN);
    chessboard[0][d] = new Piece(d, 0, WHITE, QUEEN);

    //spawn kings
    chessboard[7][e] = new Piece(e, 7, BLACK, KING);
    chessboard[0][e] = new Piece(e, 0, WHITE, KING);
};

Board::~Board()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = a; j <= h; j++)
            delete chessboard[i][j];
        delete chessboard[i];
    }
    delete chessboard;
}

void Board::drawBoard()
{
    //a b c d e f g h
    cout << "   ";
    for (int i = 0; i < 8; i++)
    {
        cout << i << " ";
    }
    cout << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << i << "  ";
        for (int j = a; j <= h; j++)
            if (chessboard[i][j] != nullptr)
                cout << chessboard[i][j]->getSymbol() << " ";
            else
                cout << "  ";
        cout << " " << i ;
        cout << endl;
    }

    cout << "   ";
    for (int i = 0; i < 8; i++)
    {
        cout << i << " ";
    }
    cout << endl;
}

bool Board::isMoveVaild(Point pos, bool color)
{
    int newPosX = pos.getXCord();
    int newPosY = pos.getYCord();
    //point not on the board
    if (!(newPosX >= 0 && newPosX <= 7 && newPosY >= 0 && newPosY <= 7))
        return false;

    //allay on the new point
    if (chessboard[newPosY][newPosX]!=nullptr && chessboard[newPosY][newPosX]->getColor() == color)
        return false;
        
    return true;
}

int Board::move(Point src, Point dest)
{
    int srcX,srcY,destX,destY;
    srcY=src.getYCord();
    srcX=src.getXCord();
    destY=dest.getYCord();
    destX=dest.getXCord();

    if (chessboard[srcY][srcX]==nullptr)
        return -1;

    if (isMoveVaild(dest, chessboard[srcY][srcX]->getColor()) == false)
        return -1;
    
    Point vect=dest-src;
    if (chessboard[srcY][srcX]->isMoveValid(*this,src,vect)==0)
        return -1;

    if (chessboard[destY][destX] != nullptr)
    {
        chessboard[destY][destX]->setState(DEAD);
        delete chessboard[destY][destX];
        chessboard[destY][destX] = nullptr;
    }

    chessboard[destY][destX] = chessboard[srcY][srcX];
    chessboard[srcY][srcX] = nullptr;
    
    return 0;
}

Piece* Board::getPieceAt(int X, int Y)
{
    if (X > 7 || X < 0 || Y > 7 || Y < 0)
        return nullptr;
    return chessboard[Y][X];
}

Piece* Board::getPieceAt(Point pos)
{
    int X=pos.getXCord();
    int Y=pos.getYCord();
    if (X > 7 || X < 0 || Y > 7 || Y < 0)
        return nullptr;
    return chessboard[Y][X];
}