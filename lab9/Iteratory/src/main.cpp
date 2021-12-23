#include "musicPlayer.h"
#include <list> 
#include <iostream>

using namespace std;


int main()
{
    list <char> li={'a','b','c','d','e','f'};
    for(char &i : li)
    {
        i=toupper(i);
        cout << i << " ";
    }

    return 0;
}