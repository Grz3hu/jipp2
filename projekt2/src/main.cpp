#include "chess.h"
#include <iostream>
#include <unistd.h>
#include <stdlib.h>
#include <vector>
#include <fstream>
#include <string.h>

using namespace std;

template <typename T>
struct pairColRow
{
	T col;
	T row;
};

int main(int argc, char* argv[])
{
	Board gameboard = Board();
	Piece *tmp;
	pairColRow<int> src;
	pairColRow<int> dest;
	
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
		cin >> src.col;
		cin.clear();
		cin.ignore(10000, '\n');
		
		//end of the game
		if(src.col==-1)
			break;

		cout << "Podaj zrodlowy wiersz:\n";
		cin >> src.row;
		cin.clear();
		cin.ignore(10000, '\n');

		cout << "Podaj docelowa kolumne:\n";
		cin >> dest.col;
		cin.clear();
		cin.ignore(10000, '\n');

		cout << "Podaj docelowy wiersz:\n";
		cin >> dest.row;
		cin.clear();
		cin.ignore(10000, '\n');

		tmp = gameboard.getPieceAt(src.col, src.row);
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

		if (gameboard.move(Point(src.col, src.row), Point(dest.col, dest.row)) == -1)
		{
			system("clear");
			cerr << "blad: nieprawidlowy ruch" << endl;
			sleep(2);
			continue;
		}

		moves.push_back(to_string(playerColor) + " " + to_string(src.col) + ":" + to_string(src.row) + " -> " + to_string(dest.col) + ":" + to_string(dest.row));
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