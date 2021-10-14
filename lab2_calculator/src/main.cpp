#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "calc.h"

using namespace std;

int main(int argc, char* argv[])
{
	//Program
	//TODO toint na atoi
	//osobny folder na zadanko lab2

	if(argc < 2)
	{
		cerr << "Podano złą ilość argumentów\n\n";
		print_help();
		return 0;
	}

	if (strcmp(argv[1], "add") == 0)
	{
		if(argc != 4)
		{
			cerr << "Podano złą ilość argumentów\n\n";
			print_help();
			return 0;
		}

		int w=add(atoi(argv[2]),atoi(argv[3]));
		cout << w << endl;
	}
	if (strcmp(argv[1], "subtract") == 0)
	{
		if(argc != 4)
		{
			cerr << "Podano złą ilość argumentów\n\n";
			print_help();
			return 0;
		}

		int w=subtract(atoi(argv[2]),atoi(argv[3]));
		cout << w << endl;
	}
	if (strcmp(argv[1], "volume") == 0)
	{
		//2-a 3-b 4-h 5-H
		if(argc != 6)
		{
			cerr << "Podano złą ilość argumentów\n\n";
			print_help();
			return 0;
		}

		int w=volume(atoi(argv[2]),atoi(argv[3]),atoi(argv[4]),atoi(argv[5]));
		cout << w << endl;
	}
	else
	{
		print_help();
	}

	return 0;
}
