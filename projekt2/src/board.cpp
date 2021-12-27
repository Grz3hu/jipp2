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
        chessboard[1][i] = new Pawn(i, 1, WHITE);
        chessboard[6][i] = new Pawn(i, 6, BLACK);
    }

    //spawn rooks
    chessboard[7][a] = new Rook(a, 7, BLACK);
    chessboard[7][h] = new Rook(h, 7, BLACK);
    chessboard[0][a] = new Rook(a, 7, WHITE);
    chessboard[0][h] = new Rook(h, 7, WHITE);

    //spawn knights
    chessboard[7][b] = new Knight(b, 7, BLACK);
    chessboard[7][g] = new Knight(g, 7, BLACK);
    chessboard[0][b] = new Knight(b, 7, WHITE);
    chessboard[0][g] = new Knight(g, 7, WHITE);

    //spawn bishops
    chessboard[7][c] = new Bishop(c, 7, BLACK);
    chessboard[7][f] = new Bishop(f, 7, BLACK);
    chessboard[0][c] = new Bishop(c, 7, WHITE);
    chessboard[0][f] = new Bishop(f, 7, WHITE);

    //spawn queens
    chessboard[7][d] = new Queen(d, 7, BLACK);
    chessboard[0][d] = new Queen(d, 0, WHITE);

    //spawn kings
    chessboard[7][e] = new King(e, 7, BLACK);
    chessboard[0][e] = new King(e, 0, WHITE);
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
        cout << (char)('a' + i) << " ";
    }
    cout << endl
         << endl;

    for (int i = 0; i < 8; i++)
    {
        cout << 8 - i << "  ";
        for (int j = a; j <= h; j++)
            if (chessboard[i][j] != nullptr)
                cout << chessboard[i][j]->getSymbol() << " ";
            else
                cout << "  ";
        cout << endl;
    }
}

bool Board::isMoveVaild(Point pos, bool color)
{
    int newPosX = pos.getXCord();
    int newPosY = pos.getYCord();
    //point not on the board
    if (!(newPosX >= 0 && newPosX <= 7 && newPosY >= 0 && newPosY <= 7))
        return 0;

    //allay on the new point
    if (chessboard[newPosY][newPosX]->getColor() == color)
        return 0;
        
    return 1;
}

void Board::move(Point src, Point dest)
{
    if (chessboard[dest.getYCord()][dest.getXCord()] != nullptr)
    {
        chessboard[dest.getYCord()][dest.getXCord()]->setState(DEAD);
        delete chessboard[dest.getYCord()][dest.getXCord()];
        chessboard[dest.getYCord()][dest.getXCord()] = nullptr;
    }

    chessboard[dest.getYCord()][dest.getXCord()] = chessboard[src.getYCord()][src.getXCord()];
    chessboard[src.getYCord()][src.getXCord()]->setXCord(dest.getXCord());
    chessboard[src.getYCord()][src.getXCord()]->setYCord(dest.getYCord());
    chessboard[src.getYCord()][src.getXCord()] = nullptr;
}