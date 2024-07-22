#include <stdio.h>

void MatrixMulVectorTest(){
	
	printf("==== Testing MatrixMulVector...\n");
	int row = 3;
	int col = 3;	
	Vector * A = initVector(row);
	Vector * X = initVector(row);
	Matrix * B = initMatrix(row,col);
	float matrix[9] = {1,2,3,4,5,6,7,8,9};
	float vector[3] = {1,2,3};
	float xp[3] = {14,32,50};
	
	A->vector = vector;
	X->vector = xp;
	B->matrix = matrix;
	Vector * V;
	V =MatrixMulVect(B, A);	
	check_vect(V,X);
	printf("\n");
}

