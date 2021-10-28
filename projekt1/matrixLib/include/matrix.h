#ifndef MATRIX_H
#define MATRIX_H

int** newIntMatrix(int w, int k);
double** newDoubleMatrix(int w, int k);

void getMatrixParams(int &w, int &k);
void printHelp();

void fillMatrix(int** newMatrix, int w, int k);
void fillMatrix(double** newMatrix, int w, int k);

void printMatrix(int** a, int w, int k);
void printMatrix(double** a, int w, int k);

int** addMatrix(int** a, int** b, int w, int k);
double** addMatrix(double** a, double** b, int w, int k);

int** subtractMatrix(int** a, int** b, int w, int k);
double** subtractMatrix(double** a, double** b, int w, int k);

int** multiplyMatrix(int** a, int** b, int w1, int k1, int k2);
double** multiplyMatrix(double** a, double** b, int w1, int k1, int k2);

int** multiplyByScalar(int** a, int w, int k, int s);
double** multiplyByScalar(double** a, int w, int k, double s);

int** transpozeMatrix(int** a, int w, int k);
double** transpozeMatrix(double** a, int w, int k);

void copy(int** a, int** dest, int n);
void copy(double** a, double** dest, int n);

int** powerMatrix(int** a, int w, int k, unsigned int p);
double** powerMatrix(double** a, int w, int k, unsigned int p);

int determinantMatrix(int** a, int w, int k);
double determinantMatrix(double** a, int w, int k);

bool matrixIsDiagonal(int** a, int w, int k);
bool matrixIsDiagonal(double** a, int w, int k);

void swap(int& a, int& b);
void swap(double& a, double& b);

void sortRow(int* a, int k);
void sortRow(double* a, int k);

void sortRowsInMatrix(int** a, int w, int k);
void sortRowsInMatrix(double** a, int w, int k);

#endif 
