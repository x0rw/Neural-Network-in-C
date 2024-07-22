#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
// #include "src/structure.h"
#include "src/math.h"
#define WEIGHT_INIT 1
#define NEURON_INIT 1


int main() {

	int row = 3;
	int col = 3;	
	Vector * A = initVector(row);
	Matrix * B = initMatrix(row,col);
	float matrix[9] = {1,2,3,4,5,6,7,8,9};
	float vector[3] = {1,2,3};
	
	A->vector = vector;
	B->matrix = matrix;
	Vector * V;
	V =MatrixMulVect(B, A);	
	printVector(V);
//int *result = matrixMulVect(&Matrix,&Vector,9,3);
//	gcLayer inputLayer = constructLayer(3);
//	gcLayer hiddenLayer = constructLayer(2);
//	gcLayer outputLayer = constructLayer(2);
//	gcLayers* l = newLayers(3);
//	gcaddlayer(l, &hiddenLayer);
//	gcaddlayer(l, &inputLayer);
//	gcaddlayer(l, &outputLayer);
//	gcprintAllLayers(l);









	printf("hedddllo");
	return 0;
}
