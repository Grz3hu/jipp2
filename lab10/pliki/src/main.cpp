#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    ifstream input("input.csv");
    ofstream outputTram("tram.txt");
    ofstream outputBus("bus.txt");

    if (! (input.is_open() && outputTram.is_open() && outputBus.is_open()) )
        exit(EXIT_FAILURE);

    string tmp,nr;
    while (!input.eof())
    {
        getline(input, tmp);
        int i=0;
        nr="";
        while (tmp[i] != ',')
        {
            nr+=tmp[i];
            i++;
        }
        cout << nr << endl;
        if(atoi(nr.c_str())<=99)
            outputTram << tmp << endl;
        else
            outputBus << tmp << endl;
    }

    input.close();
    outputTram.close();
    outputBus.close();

    return 0;
}