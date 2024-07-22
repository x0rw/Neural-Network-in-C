#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "math.h"
#define WEIGHT_INIT 1
#define NEURON_INIT 1




typedef struct {
	int neuronsCount;
	int* neuronsVector;
	int* weightMatrix;
	int weightMatrixDimension[2];
}Layer;
typedef struct Layers {
	size_t size;
	size_t index;
	Layer** layers;
} Layers;

Layers * newLayers(size_t);
Layer constructLayer(size_t);
void initWeightMatrix(Layer* , int [2]);
void addlayer(Layers *, Layer * );
void printLayer(Layer*);
void printAllLayers(Layers*);

Layers * newLayers(size_t size) {
	Layers* ls = (Layers*)malloc(sizeof(Layers));
	Layer** l = (Layer **)malloc(sizeof(Layer *) * size);

	if (l == NULL) {
		printf("failed to malloc layerpointer");

		exit(-1);
	}
	
	ls->size = size;
	ls->index = 0;
	ls->layers = l;
	return ls;

}
void  addlayer(Layers* l, Layer* lay) {
	if (l->index > l->size - 1) {
		printf("Layers are full"); exit(-1);
	}

	int index = l->index;
	printf("=%d=", l->index);	
	l->layers[index]= lay;

	if (l->index != 0) {
			Layer* previouslayer = l->layers[index-1];

			int weightdim[2] = { previouslayer->neuronsCount,lay->neuronsCount};
			initWeightMatrix(previouslayer, weightdim);
		}
	l->index++;
	printf("+ New layer added \n");
	

}
void printLayer(Layer* L) {
	if (L == NULL) { printf("layer is null"); exit(-1); }
	int* neuronVect = L->neuronsVector;
	printf("========NEURONS: %d ========\n ", L->neuronsCount );
	for (int i = 0; i < L->neuronsCount; i++) {
		printf(" %d, ", neuronVect[i]);
	}
	int* Mat = L->weightMatrix;
	
	printf("\n ======== WEIGHTS ======== \n");

	
		int row = L->weightMatrixDimension[0];
		int columns = L->weightMatrixDimension[1];
		for (int i = 0; i < row; i++) {

			for (int j = 0; j < columns; j++) {
				int offset = i + row * j; //rows-major ordering
					printf("%d \t", Mat[offset]);
			}
			printf("\n");

		}

	printf("]\n======================\n ");

}

void printAllLayers(Layers* ls) {

	for (int i = 0; i < ls->index-1; i++) {//< to not print the output layer
		printLayer(ls->layers[i]);

	}
}

Layer constructLayer(size_t neuronsCount) {
	int* neuronsVector = (int*)malloc(sizeof(int) * neuronsCount);
	if (neuronsVector == NULL) {
		printf("failled to malloc neuronsVector");
		exit(-1);
	}
	for (int i = 0; i < neuronsCount; i++) {
		neuronsVector[i] = NEURON_INIT;
	}
	Layer L;
	L.neuronsVector = neuronsVector;
	L.neuronsCount = neuronsCount;
	return L;

}
 void initWeightMatrix(Layer* l, int dim[2]) {
	 int row = dim[0];
	 int columns = dim[1];
	 printf("\n rows:%d, columns%d \n", row, columns);
	 int* matrix = (int*)malloc(row * columns* sizeof(int));
	 if (matrix == NULL) {
		 printf("cannot allocate memory for the matrix");
		 exit(0);
	 }
	 for (int i = 0; i < row; i++) {

		 for (int j = 0; j < columns; j++) {
			int offset = i + row * j; //rows-major ordering
			matrix[offset] = WEIGHT_INIT;
		 }
		 
	 }
	 l->weightMatrix = matrix;
	 l->weightMatrixDimension[0] = dim[0];
	 l->weightMatrixDimension[1] = dim[1];

 }



