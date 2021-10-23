#include "matrix.h"
#include <math.h>

using namespace std;

//int

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

/////////////////////////////////////////////////////////////////////////////
void copy(int** a, int** dest, int n)//only used in powerMatrix
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			dest[i][j]=a[i][j];
}

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
/////////////////////////////////////////////////////////////////////////////

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

bool matrixIsDiagonal(int** a, int w, int k)
{
	for(int i=0;i<w;i++)
		for(int j=0;j<k;j++)
			if(j!=i && a[i][j]!=0)
				return false;
	return true;
}

void swap(int& a, int& b)
{
	int tmp=a;
	a=b;
	b=tmp;
}

void sortRow(int* t, int k)
{
	for(int i=0;i<k;i++)
		for(int j=0;j<k-i-1;j++)
			if(t[j]>t[j+1])
				swap(t[j],t[j+1]);
}

void sortRowsInMatrix(int** t, int w, int k)
{
	for(int i=0;i<w;i++)
	{
		sortRow(t[i],k);
	}
}

//double

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

/////////////////////////////////////////////////////////////////////////////
void copy(double** a, double** dest, int n)//only used in powerMatrix
{
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			dest[i][j]=a[i][j];
}

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
/////////////////////////////////////////////////////////////////////////////

double determinantMatrix(double** a, int n)
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
			det = det + (pow(-1, x) * a[0][x] * determinantMatrix( suba, n - 1 ));
		}
	}

	for(int i=0;i<n;i++)
		delete [] suba[i];
	delete [] suba;

	return det;
}

bool matrixIsDiagonal(double** a, int w, int k)
{
	for(int i=0;i<w;i++)
		for(int j=0;j<k;j++)
			if(j!=i && a[i][j]!=0)
				return false;
	return true;
}

void swap(double& a, double& b)
{
	double tmp=a;
	a=b;
	b=tmp;
}

void sortRow(double* t, int k)
{
	for(int i=0;i<k;i++)
		for(int j=0;j<k-i-1;j++)
			if(t[j]>t[j+1])
				swap(t[j],t[j+1]);
}

void sortRowsInMatrix(double** t, int w, int k)
{
	for(int i=0;i<w;i++)
	{
		sortRow(t[i],k);
	}
}
