#include "chess.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>

using namespace std;
/*
TODO:
FIX BISHOP
ADD CHECKMATE
ADD SURRENDER
MOVE HISTORY
SAVING HISTORY TO FILE
NOSAVE PARAMETER
*/

int main()
{
	Board gameboard = Board();
	Piece* tmp;
	int src_col, src_row;
	int dest_col, dest_row;
	bool playerColor=WHITE;

	while(1)
	{
		system ("clear");
		if(playerColor)
			cout << "Ruch czarnych" << endl << endl;
		else
			cout << "Ruch bialych" << endl << endl;
				
		gameboard.drawBoard();

		cout << "Podaj zrodlowa kolumne:\n";
		cin >> src_col;
		cin.clear();
		cin.ignore(10000, '\n'); 

		cout << "Podaj zrodlowy wiersz:\n";
		cin >> src_row;
		cin.clear();
		cin.ignore(10000, '\n'); 

		cout << "Podaj docelowa kolumne:\n";
		cin >> dest_col;
		cin.clear();
		cin.ignore(10000, '\n'); 

		cout << "Podaj docelowy wiersz:\n";
		cin >> dest_row;
		cin.clear();
		cin.ignore(10000, '\n'); 

		tmp = gameboard.getPieceAt(src_col,src_row);
		if (tmp == nullptr)
		{
			system ("clear");
			cerr << "blad: nie ma pionka w takim miejscu" << endl;
			sleep(2);
			continue;
		}
		if(tmp->getColor()!=playerColor)
		{
			system ("clear");
			cerr << "blad: to nie twoj pionek" << endl;
			sleep(2);
			continue;
		}

		if(gameboard.move(Point(src_col, src_row), Point(dest_col, dest_row))==-1)
		{
			system ("clear");
			cerr << "blad: nieprawidlowy ruch" << endl;
			sleep(2);
			continue;
		}

		playerColor = !playerColor;
	}

	return 0;
}