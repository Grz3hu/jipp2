#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "matrix.h"

using namespace std;

int main(int argc, char **argv)
{
	if(argc==1)
	{
		printHelp();
		return 1;
	}

	int option=atoi(argv[1]);
	if(!option || option>=11)
	{
		printHelp();
		return 1;
	}

	int w1,k1;
	getMatrixParams(w1,k1);
	double** newMatrix1 = newDoubleMatrix(w1,k1);
	fillMatrix(newMatrix1,w1,k1);
	cout << endl << "Wprowadzona 1 macierz: " << endl;
	printMatrix(newMatrix1,w1,k1);
	cout << endl;

	int w2,k2;
	double** newMatrix2;
	if(option<=3)
	{
	getMatrixParams(w2,k2);
	newMatrix2=newDoubleMatrix(w2,k2);
	fillMatrix(newMatrix2,w2,k2);
	cout << endl << "Wprowadzona 2 macierz: " << endl;
	printMatrix(newMatrix2,w2,k2);
	cout << endl;
	}

	switch(option){
		case 1:
			cout << "Wynik operacji: " << endl;
			printMatrix( addMatrix(newMatrix1,newMatrix2,w1,k1), w1, k1);
			break;
		case 2:
			cout << "Wynik operacji: " << endl;
			printMatrix( subtractMatrix(newMatrix1,newMatrix2,w1,k1), w1, k1);
			break;
		case 3: 
			cout << "Wynik operacji: " << endl; 
			printMatrix( multiplyMatrix(newMatrix1,newMatrix2,w1,k1,k2), w1, k1);
			break;
		case 4:
			double s;
			cout << "Podaj skalar: \n";
			cin >> s;
			cout << "Wynik operacji: " << endl;
			printMatrix( multiplyByScalar(newMatrix1, w1, k1, s), w1, k1);
			break;
		case 5:
			cout << "Wynik operacji: " << endl;
			printMatrix( transpozeMatrix(newMatrix1,w1,k1), w1, k1);
			break;
		case 6:
			unsigned int p;
			cout << "Podaj potęge: \n";
			cin >> p;
			cout << "Wynik operacji: " << endl;
			printMatrix( powerMatrix(newMatrix1,w1,k1,p), w1, k1);
			break;
		case 7:
			cout << "Wynik operacji: " << endl;
			cout << determinantMatrix(newMatrix1,w1,k1) << endl;
			break;
		case 8:
			cout << "Wynik operacji: " << endl;
			cout << matrixIsDiagonal(newMatrix1,w1,k1) << endl;
			break;
		case 9:
			int w;
			cout << "Podaj wiersz do posortowania (od 0): \n";
			cin >> w;
			cout << "Wynik operacji: " << endl;
			sortRow(newMatrix1[w],k1);
			printMatrix(newMatrix1, w1, k1);
			break;
		case 10:
			sortRowsInMatrix(newMatrix1,w1,k1);
			cout << "Wynik operacji: " << endl;
			printMatrix(newMatrix1, w1, k1);
			break;
		default:
			printHelp();
	}


	return 0;
}
