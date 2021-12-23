#ifndef NOTES_H
#define NOTES_H

#include <iostream>
#include <string>

using namespace std;

template <typename T>
T maxT(T x, T y)
{
    return (x > y) ? x : y;
}

template <typename T>
T minT(T x, T y)
{
    return (x < y) ? x : y;
}

template <typename T, int il>
void printArray(T *a)
{
    for (int i = 0; i < il; i++)
        cout << " " << a[i];
    cout << endl;
}

template <typename T, int il>
void printMatrix(T **a)
{
    for (int i = 0; i < il; i++)
    {
        for (int j = 0; j < il; j++)
            cout << " " << a[i][j];
        cout << endl;
    }
}

template <typename T, int il>
class Array
{
private:
    int size;
    T arr[];

public:
    Array()
    {
        size = il;
    }

    T getArr()
    {
        return arr;
    }

    int getSize()
    {
        return size;
    }
};

#endif