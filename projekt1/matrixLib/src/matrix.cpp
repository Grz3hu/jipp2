#include <iostream>
#include <math.h>
#include "matrix.h"

using namespace std;

void printHelp()
{
	cout << "Wybierz operacje: \n";
	cout << "1) Dodawanie macierzy \n";
	cout << "2) Odejmowanie macierzy \n";
	cout << "3) Mnożenie macierzy \n";
	cout << "4) Mnożenie przez skalar \n";
	cout << "5) Transponowanie macierzy \n";
	cout << "6) Potęgowanie macierzy \n";
	cout << "7) Wyznacznik macierzy \n";
	cout << "8) Spr. diagonalnosci \n";
	cout << "9) Sortowanie wiersza \n";
	cout << "10) Sortowanie wszystkich wierszy \n";
	cout << "help) Wyświetlenie pomocy \n";
}

/*!
  @param w matrix height
  @param k matrix width
  */
void getMatrixParams(int &w, int &k)
{
	cout << "Podaj wysokość macierzy: \n";
	cin >> w;
	if(cin.fail())
	{
		cerr << "Nie podano liczby\n";
		exit(EXIT_FAILURE);
	}
	cout << "Podaj szerokość macierzy: \n";  
	cin >> k;
	if(cin.fail())
	{
		cerr << "Nie podano liczby\n";
		exit(EXIT_FAILURE);
	}
}

/*!
  @param w matrix height
  @param k matrix width
  @return pointer to matrix
  */
int** newIntMatrix(int w, int k)
{
	int** newMatrix=new int*[w];
	for(int i=0;i<w;i++)
		newMatrix[i]=new int[k];

	return newMatrix;
}

/*!
  @param w matrix height
  @param k matrix width
  @return pointer to matrix
  */
double** newDoubleMatrix(int w, int k)
{
	double** newMatrix=new double*[w];
	for(int i=0;i<w;i++)
		newMatrix[i]=new double[k];

	return newMatrix;
}


/*!
  @param a pointer to matrix
  @param w matrix height
  @param k matrix width
  */
void fillMatrix(int** a, int w, int k)
{
	for(int i=0;i<w;i++)
	{
		for(int j=0;j<k;j++)
		{
			cout << "Podaj element na pozycje " << i << " " << j << " :" << endl;
			cin >> a[i][j];
			if(cin.fail())
			{
				cerr << "Nie podano liczby\n";
				exit(EXIT_FAILURE);
			}
		}
	}
}

/*!
  @param a pointer to matrix
  @param w matrix height
  @param k matrix width
  */
void fillMatrix(double** a, int w, int k)
{
	for(int i=0;i<w;i++)
	{
		for(int j=0;j<k;j++)
		{
			cout << "Podaj element na pozycje " << i << " " << j << " :" << endl;
			cin >> a[i][j];
			if(cin.fail())
			{
				cerr << "Nie podano liczby\n";
				exit(EXIT_FAILURE);
			}
		}
	}
}

/*!
  @param a pointer to the matrix
  @param w matrix height
  @param k matrix width
  */
void printMatrix(int** a, int w, int k)
{
	for(int i=0;i<w;i++)
	{
		for(int j=0;j<k;j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}

/*!
  @param a pointer to the matrix
  @param w matrix height
  @param k matrix width
  */
void printMatrix(double** a, int w, int k)
{
	for(int i=0;i<w;i++)
	{
		for(int j=0;j<k;j++)
			cout << a[i][j] << " ";
		cout << endl;
	}
}


////////////////////////

/*!
  @param a pointer to the first matrix
  @param b pointer to the second matrix
  @param w matrix height
  @param k matrix width
  @return pointer to new matrix
  */
int** addMatrix(int** a, int** b, int w, int k)
{
	int** newMatrix=new int*[w];
	for(int i=0;i<w;i++)
		newMatrix[i]=new int[k];

	for(int i=0;i<w;i++)
	{
		for(int j=0;j<k;j++)
			newMatrix[i][j]=a[i][j]+b[i][j];
	}

	return newMatrix;
}

/*!
  @param a pointer to the first matrix
  @param b pointer to the second matrix
  @param w matrix height
  @param k matrix width
  @return pointer to new matrix
  */
double** addMatrix(double** a, double** b, int w, int k)
{
	double** newMatrix=new double*[w];
	for(int i=0;i<w;i++)
		newMatrix[i]=new double[k];

	for(int i=0;i<w;i++)
	{
		for(int j=0;j<k;j++)
			newMatrix[i][j]=a[i][j]+b[i][j];
	}

	return newMatrix;
}

/*!
  @param a pointer to the first matrix
  @param b pointer to the second matrix
  @param w matrix height
  @param k matrix width
  @return pointer to new matrix
  */
int** subtractMatrix(int** a, int** b, int w, int k)
{
	int** newMatrix=new int*[w];
	for(int i=0;i<w;i++)
		newMatrix[i]=new int[k];

	for(int i=0;i<w;i++)
	{
		for(int j=0;j<k;j++)
			newMatrix[i][j]=a[i][j]-b[i][j];
	}

	return newMatrix;
}

/*!
  @param a pointer to the first matrix
  @param b pointer to the second matrix
  @param w matrix height
  @param k matrix width
  @return pointer to new matrix
  */
double** subtractMatrix(double** a, double** b, int w, int k)
{
	double** newMatrix=new double*[w];
	for(int i=0;i<w;i++)
		newMatrix[i]=new double[k];

	for(int i=0;i<w;i++)
	{
		for(int j=0;j<k;j++)
			newMatrix[i][j]=a[i][j]-b[i][j];
	}

	return newMatrix;
}

/*!
  @param a pointer to the first matrix
  @param b pointer to the second matrix
  @param w1 matrix a height
  @param k1 matrix a width
  @param k2 matrix b width
  @return pointer to new matrix
  */
int** multiplyMatrix(int** a, int** b, int w1, int k1, int k2)
{
	int** newMatrix=new int*[w1];
	for(int i=0;i<w1;i++)
		newMatrix[i]=new int[k2];

	for(int i = 0; i < w1; ++i)
		for(int j = 0; j < k2; ++j)
			for(int k = 0; k < k1; ++k)
			{
				newMatrix[i][j]+=a[i][k]*b[k][j];
			}

	return newMatrix;
}

/*!
  @param a pointer to the first matrix
  @param b pointer to the second matrix
  @param w1 matrix a height
  @param k1 matrix a width
  @param k2 matrix b width
  @return pointer to new matrix
  */
double** multiplyMatrix(double** a, double** b, int w1, int k1, int k2)
{
	double** newMatrix=new double*[w1];
	for(int i=0;i<w1;i++)
		newMatrix[i]=new double[k2];

	for(int i = 0; i < w1; ++i)
		for(int j = 0; j < k2; ++j)
			for(int k = 0; k < k1; ++k)
			{
				newMatrix[i][j]+=a[i][k]*b[k][j];
			}

	return newMatrix;
}


/*!
  @param a pointer to the first matrix
  @param w matrix height
  @param k matrix width
  @param s scalar value
  @return pointer to new matrix
  */
int** multiplyByScalar(int** a, int w, int k, int s)
{
	int** newMatrix=new int*[w];
	for(int i=0;i<w;i++)
		newMatrix[i]=new int[k];

	for(int i=0;i<w;i++)
	{
		for(int j=0;j<k;j++)
			newMatrix[i][j]=a[i][j]*s;
	}

	return newMatrix;
}

/*!
  @param a pointer to the first matrix
  @param w matrix height
  @param k matrix width
  @param s scalar value
  @return pointer to new matrix
  */
double** multiplyByScalar(double** a, int w, int k, double s)
{
	double** newMatrix=new double*[w];
	for(int i=0;i<w;i++)
		newMatrix[i]=new double[k];

	for(int i=0;i<w;i++)
	{
		for(int j=0;j<k;j++)
			newMatrix[i][j]=a[i][j]*s;
	}

	return newMatrix;
}

/*!
  @param a pointer to the first matrix
  @param w matrix height
  @param k matrix width
  @return pointer to new matrix
  */
int** transpozeMatrix(int** a, int w, int k)
{
	int** newMatrix=new int*[k];
	for(int i=0;i<k;i++)
		newMatrix[i]=new int[w];

	for(int i=0;i<w;i++)
		for(int j=0;j<k;j++)
		{
			newMatrix[j][i]=a[i][j];
		}

	return newMatrix;
}

/*!
  @param a pointer to the first matrix
  @param w matrix height
  @param k matrix width
  @return pointer to new matrix
  */
double** transpozeMatrix(double** a, int w, int k)
{
	double** newMatrix=new double*[k];
	for(int i=0;i<k;i++)
		newMatrix[i]=new double[w];

	for(int i=0;i<w;i++)
		for(int j=0;j<k;j++)
		{
			newMatrix[j][i]=a[i][j];
		}

	return newMatrix;
}


/*!
  @param a pointer to the source matrix
  @param dest pointer to the destination matrix
  @param n matrix size (width or height)
  */
void copy(int** a, int** dest, int n)//only used in powerMatrix
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			dest[i][j]=a[i][j];
}

/*!
  @param a pointer to the first matrix
  @param w matrix height
  @param k matrix width
  @param p power value
  @return pointer to new matrix
  */
int** powerMatrix(int** a, int w, int k, unsigned int p) //w jest rowne k
{
	int** b=new int*[k];
	for(int i=0;i<k;i++)
		b[i]=new int[w];

	int** c;

	copy(a,b,w);
	for(int i=0;i<p-1;i++)
	{
		c=multiplyMatrix(a,b,w,w,w);
		copy(c,b,w);

		//clearing c
		for(int i=0;i<w;i++)
			delete [] c[i];
		delete [] c;
	}

	return b;
}

/*!
  @param a pointer to the source matrix
  @param dest pointer to the destination matrix
  @param n matrix size (width or height)
  */
void copy(double** a, double** dest, int n)//only used in powerMatrix
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			dest[i][j]=a[i][j];
}

/*!
  @param a pointer to the first matrix
  @param w matrix height
  @param k matrix width
  @param p power value
  @return pointer to new matrix
  */
double** powerMatrix(double** a, int w, int k, unsigned int p)
{
	double** b=new double*[k];
	for(int i=0;i<k;i++)
		b[i]=new double[w];

	double** c;

	copy(a,b,w);
	for(int i=0;i<p-1;i++)
	{
		c=multiplyMatrix(a,b,w,w,w);
		copy(c,b,w);

		//clearing c
		for(int i=0;i<w;i++)
			delete [] c[i];
		delete [] c;
	}

	return b;
}


/*!
  @param a pointer to the first matrix
  @param n matrix height
  @param k matrix width
  @return determinant value
  */
int determinantMatrix(int** a, int n, int k) //n jest rowne k
{
	int det = 0;

	int** suba=new int*[n];
	for(int i=0;i<n;i++)
		suba[i]=new int[n];

	if (n==2)
		return ((a[0][0] * a[1][1]) - (a[1][0] * a[0][1]));
	else {
		for (int x = 0; x < n; x++) {
			int subi = 0;
			for (int i = 1; i < n; i++) {
				int subj = 0;
				for (int j = 0; j < n; j++) {
					if (j == x)
						continue;
					suba[subi][subj] = a[i][j];
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1, x) * a[0][x] * determinantMatrix(suba, n-1, 0));
		}
	}

	for(int i=0;i<n;i++)
		delete [] suba[i];
	delete [] suba;

	return det;
}

/*!
  @param a pointer to the first matrix
  @param n matrix height
  @param k matrix width
  @return determinant value
  */
double determinantMatrix(double** a, int n, int k)
{
	double det = 0;

	double** suba=new double*[n];
	for(int i=0;i<n;i++)
		suba[i]=new double[n];

	if (n==2)
		return ((a[0][0] * a[1][1]) - (a[1][0] * a[0][1]));
	else {
		for (int x = 0; x < n; x++) {
			int subi = 0;
			for (int i = 1; i < n; i++) {
				int subj = 0;
				for (int j = 0; j < n; j++) {
					if (j == x)
						continue;
					suba[subi][subj] = a[i][j];
					subj++;
				}
				subi++;
			}
			det = det + (pow(-1, x) * a[0][x] * determinantMatrix( suba, n - 1, 0));
		}
	}

	for(int i=0;i<n;i++)
		delete [] suba[i];
	delete [] suba;

	return det;
}


/*!
  @param a pointer to the first matrix
  @param w matrix height
  @param k matrix width
  @return bool value, true means it is diagonal
  */
bool matrixIsDiagonal(int** a, int w, int k)
{
	for(int i=0;i<w;i++)
		for(int j=0;j<k;j++)
			if(j!=i && a[i][j]!=0)
				return false;
	return true;
}

/*!
  @param a pointer to the first matrix
  @param w matrix height
  @param k matrix width
  @return bool value, true means it is diagonal
  */
bool matrixIsDiagonal(double** a, int w, int k)
{
	for(int i=0;i<w;i++)
		for(int j=0;j<k;j++)
			if(j!=i && a[i][j]!=0)
				return false;
	return true;
}

/*!
  @param a first variable
  @param b second variable
  */
void swap(int& a, int& b)
{
	int tmp=a;
	a=b;
	b=tmp;
}

/*!
  @param a first variable
  @param b second variable
  */
void swap(double& a, double& b)
{
	double tmp=a;
	a=b;
	b=tmp;
}

/*!
  @param a pointer to the first matrix
  @param k matrix width
  */
void sortRow(int* a, int k)
{
	for(int i=0;i<k;i++)
		for(int j=0;j<k-i-1;j++)
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
}

/*!
  @param a pointer to the first matrix
  @param k matrix width
  */
void sortRow(double* a, int k)
{
	for(int i=0;i<k;i++)
		for(int j=0;j<k-i-1;j++)
			if(a[j]>a[j+1])
				swap(a[j],a[j+1]);
}

/*!
  @param a pointer to the first matrix
  @param w matrix height
  @param k matrix width
  */
void sortRowsInMatrix(int** a, int w, int k)
{
	for(int i=0;i<w;i++)
	{
		sortRow(a[i],k);
	}
}

/*!
  @param a pointer to the first matrix
  @param w matrix height
  @param k matrix width
  */
void sortRowsInMatrix(double** a, int w, int k)
{
	for(int i=0;i<w;i++)
	{
		sortRow(a[i],k);
	}
}
