
#include "../include/math.h"
float sigmoid(float f){
	    return (1 / (1 + powf(EULER_NUMBER, -f)));
}

void printVector(Vector *V){
	for(int i=0; i<V->rows;i++){
		printf("%.5lf\n",V->vector[i]);
	}
	printf("\n");
}

void printMatrix(Matrix *M){
	int rows =M->rows;
	int cols =M->cols;
	for(int i=0; i<rows;i++){
	printf("\n");
	for(int j =0; j<cols;j++){
		int offset = j+ cols *i;
		
		printf("%.2lf\t", M->matrix[offset]);
	}
	}



}

void randMatrix(Matrix * A){
	srand(time(NULL));
	int rows =A->rows;
	int cols =A->cols;
	float *matrix = A->matrix;
	for(int i=0; i<rows;i++){
		for(int j =0; j<cols;j++){
			int offset = j+ cols *i;
			matrix[offset]=(float )rand() / RAND_MAX - 0.5;	
			//matrix[offset]=1.22;	
		}
	}

}



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
Matrix * initMatrix(int rows, int cols){
	Matrix * mat = (Matrix *)malloc(sizeof(Matrix));
	float * matrix = (float *)calloc( rows * cols, sizeof(float));
	if(mat == NULL || matrix==NULL ){
		printf("\nCouldn't allocate memory for the Vector\n");
		exit(1);
	}
	mat->rows= rows;
	mat->cols= cols;
	mat->matrix = matrix;
	randMatrix(mat);
	return mat;
}

Vector* MatrixMulVect(Matrix * A, Vector * B, Vector * C){
	int rows =A->rows;
	int cols =A->cols;
	float * matrix= A->matrix;	
	float *vector= B->vector;
	float *vectorC= C->vector;

	if(cols == 1){//a matrix could be a vector
		Vector * resultVector = initVector(1); 
		float r= 0.0f;
		for(int i = 0; i<rows;i++){
			r +=matrix[i]*vector[i] +vectorC[i]  ;
			
		}
		resultVector->vector[0] = r;
		return resultVector;
	}	
	Vector * resultVector = initVector(rows); 
	float * result = resultVector->vector;
	for(int i=0; i<rows;i++){
		result[i]=0;
		for(int j =0; j<cols;j++){
			int offset = j+ cols *i;
			result[i]+=(float) matrix[offset]* (float)vector[j] + (float)vectorC[j];
		}
		result[i] = sigmoid(result[i]);
	}
	return resultVector;
}

void * vectorize(Matrix * source, Vector *destination,  int row){
	memcpy(destination->vector, source->matrix+ row * source->cols, source->cols * sizeof(float)); 	
}
