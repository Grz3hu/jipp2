#include "chess.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string.h>

using namespace std;
/*
TODO:
TEMPLATE
POLYMORPHISM
*/

int main(int argc, char* argv[])
{
	Board gameboard = Board();
	Piece *tmp;
	int src_col, src_row;
	int dest_col, dest_row;
	bool playerColor = WHITE;
	vector<string> moves;
	bool saveData = true;
	
	if(argc>=2)
	{
		if(strcmp(argv[1],"-nosave")==0)
			saveData=false;
	}
	
	ofstream historyFile;
	if(saveData)
	{
		historyFile.open("moveHistory.txt");
    	if (!historyFile.is_open() )
        	exit(EXIT_FAILURE);
	}

	cout << "By zakonczyc podaj zrodlowa kolumne -1\n";
	sleep(3);

	//gameloop
	while (1)
	{
		system("clear");
		if (playerColor)
			cout << "Ruch czarnych" << endl
				 << endl;
		else
			cout << "Ruch bialych" << endl
				 << endl;

		gameboard.drawBoard();

		cout << "Podaj zrodlowa kolumne:\n";
		cin >> src_col;
		cin.clear();
		cin.ignore(10000, '\n');
		
		if(src_col==-1)
			break;

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

		tmp = gameboard.getPieceAt(src_col, src_row);
		if (tmp == nullptr)
		{
			system("clear");
			cerr << "blad: nie ma pionka w takim miejscu" << endl;
			sleep(2);
			continue;
		}
		if (tmp->getColor() != playerColor)
		{
			system("clear");
			cerr << "blad: to nie twoj pionek" << endl;
			sleep(2);
			continue;
		}

		if (gameboard.move(Point(src_col, src_row), Point(dest_col, dest_row)) == -1)
		{
			system("clear");
			cerr << "blad: nieprawidlowy ruch" << endl;
			sleep(2);
			continue;
		}

		moves.push_back(to_string(playerColor) + " " + to_string(src_col) + ":" + to_string(src_row) + " -> " + to_string(dest_col) + ":" + to_string(dest_row));
		playerColor = !playerColor;
	}

	if (saveData)
	{
		for (string move : moves)
			historyFile << move << endl;
		historyFile.close();
	}

	return 0;
}