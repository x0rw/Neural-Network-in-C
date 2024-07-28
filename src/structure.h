#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "math.h"
#define WEIGHT_INIT 1
#define NEURON_INIT 1




typedef struct {
	Vector *vector; 
	Matrix *matrix; 
	Vector *delta; 
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
Vector * lastLayer(Layers * l ){
 return l->layers[l->index-1]->vector;
}
void printOutput(Layers * l){
	
	printVector(lastLayer(l));

}

void  addlayer(Layers* l, Layer* lay) {
	if (l->index > l->size - 1) {
		printf("Layers are full"); exit(-1);
	}

	int index = l->index;
	l->layers[index]= lay;

	if (l->index != 0) {
		Layer* previouslayer = l->layers[index-1];
		previouslayer->matrix = initMatrix(lay->vector->rows,previouslayer->vector->rows);
	}
	l->index++;
	printf("+ New layer added \n");
	

}
void printLayer(Layer* L) {
	if (L == NULL) { printf("layer is null"); exit(-1); }
	printf("\n\n======== LAYER NEURONS: %d ========\n ", L->vector->rows );
	printVector(L->vector);
	printf("\n-----------weights----------\n");
	printMatrix(L->matrix);	
	printf("\n");

}

void printAllLayers(Layers* ls) {

	for (int i = 0; i < ls->index-1; i++) {//< to not print the output layer
		printLayer(ls->layers[i]);

	printf("\n");
	printf("\n");
	printf("\n");
	}
}

Layer constructLayer(size_t neuronsCount) {
	Vector* vector= initVector(neuronsCount);
	Layer L;
	L.vector = vector;
	return L;

}
 
