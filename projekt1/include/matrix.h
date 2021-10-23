#ifndef MATRIX_H
#define MATRIX_H

//int
int** addMatrix(int** a, int** b, int w, int k);

int** subtractMatrix(int** a, int** b, int w, int k);

int** multiplyMatrix(int** a, int** b, int w1, int k1, int k2);

int** multiplyByScalar(int** a, int w, int k, int s);

int** transpozeMatrix(int** a, int w, int k);

void copy(int** a, int** dest, int n);

int** powerMatrix(int** a, int w, int k, unsigned int p);

int determinantMatrix(int** a, int w, int k);

bool matrixIsDiagonal(int** a, int w, int k);

void swap(int& a, int& b);

void sortRow(int* t, int k);

void sortRowsInMatrix(int** t, int w, int k);

//double

double** addMatrix(double** a, double** b, int w, int k);

double** subtractMatrix(double** a, double** b, int w, int k);

double** multiplyMatrix(double** a, double** b, int w1, int k1, int k2);

double** multiplyByScalar(double** a, int w, int k, double s);

double** transpozeMatrix(double** a, int w, int k);

void copy(double** a, double** dest, int n);

double** powerMatrix(double** a, int w, int k, unsigned int p);

double determinantMatrix(double** a, int w, int k);

bool matrixIsDiagonal(double** a, int w, int k);

void swap(double& a, double& b);

void sortRow(double* t, int k);

void sortRowsInMatrix(double** t, int w, int k);

#endif 
