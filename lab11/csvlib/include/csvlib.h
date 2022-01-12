#ifndef CSVLIB_H
#define CSVLIB_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class csv_obj {
	private:
		ifstream file;
		string* table;
	public:
		csv_obj(string fileName);
		~csv_obj();
		string* get_row(int index);
};

#endif