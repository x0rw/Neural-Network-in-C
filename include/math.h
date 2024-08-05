#ifndef MATH_H
#define MATH_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>
#define EULER_NUMBER 2.71828

typedef struct Matrix{
	int rows;
	int cols;
	float *matrix;

}Matrix;

typedef struct Vector{
	int rows;
	float *vector;

}Vector;

float sigmoid(float f);
void printVector(Vector *);
void printMatrix(Matrix *);
void randMatrix(Matrix * );
Vector * initVector(int );
Matrix * initMatrix(int , int);
Vector* MatrixMulVect(Matrix *, Vector *, Vector *);
void * vectorize(Matrix * , Vector *,  int );

#endif
