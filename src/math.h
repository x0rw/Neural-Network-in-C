#include <stdio.h>

typedef struct Matrix{
	int rows;
	int cols;
	float *matrix;

}Matrix;

typedef struct Vector{
	int rows;
	float *vector;

}Vector;
Vector * initVector(int rows){
	Vector * vect = (Vector *)malloc(sizeof(Vector));
	float * vector = (float *)calloc( rows,sizeof(float));
	if(vect == NULL){
		printf("\nCouldn't allocate memory for the Vector\n");
		exit(1);
	}
	vect->rows= rows;
	vect->vector = vector;
	return vect;
}
Vector * initMatrix(int rows, int cols){
	Matrix * mat = (Matrix *)malloc(sizeof(Matrix));
	float * matrix = (float *)calloc( rows * cols, sizeof(float));
	if(mat == NULL || matrix==NULL ){
		printf("\nCouldn't allocate memory for the Vector\n");
		exit(1);
	}
	mat->rows= rows;
	mat->cols= cols;
	mat->matrix = matrix;
	return mat;
}


Vector* MatrixMulVect(Matrix * A, Vector * B){
	int rows =A->rows;
	int cols =A->cols;
	float *matrix = A->matrix;
	float *vector= B->vector;
	Vector * resultVector = initVector(rows); 
	float * result = resultVector->vector;
	for(int i=0; i<rows;i++){
		result[i]=0;
		for(int j =0; j<cols;j++){
			int offset = j+ rows *i;
			result[i]+=matrix[offset]*vector[j];
		}
	}

	return resultVector;
}

void printVector(Vector * V){
	for(int i =0; i<V->rows;i++){
	printf(" %f\n", V->vector[i]);
	}
}
