#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "../include/math.h"

#define WEIGHT_INIT 1
#define NEURON_INIT 1




typedef struct {
	Vector *vector; 
	Matrix *matrix; 
	Vector *bias; 
	Vector *delta; 
}Layer;
typedef struct Layers {
	size_t size;
	size_t index;
	Layer** layers;
} Layers;

Layers * newLayers(size_t);
Layer * constructLayer(size_t);
void initWeightMatrix(Layer* , int [2]);
void addlayer(Layers *, Layer * );
void printLayer(Layer*);
void printAllLayers(Layers*);


Layers * initLayers(){
	Layer * inputLayer = constructLayer(2);
 	Layer * hiddenLayer = constructLayer(2);
 	Layer * outputLayer = constructLayer(1);

	Layers* l = newLayers(3);
 	addlayer(l, inputLayer);
 	addlayer(l, hiddenLayer);
 	addlayer(l, outputLayer
	);
	return l;
}
Vector * inputLayer(Layers * l ){
	return l->layers[0]->vector;
}

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

void  addlayer(Layers* l, Layer* current_layer) {
	if (l->index > l->size - 1) {
		printf("Layers are full"); exit(-1);
	}

	int index = l->index;
	l->layers[index]= current_layer;

	if (l->index != 0) {
		Layer* previouslayer = l->layers[index-1];
		previouslayer->matrix = initMatrix(current_layer->vector->rows,previouslayer->vector->rows);
	}
	l->index++;
	printf("+ New layer added \n");
	

}
void printLayer(Layer* L) {
	if (L == NULL) { printf("layer is null"); exit(-1); }

	printf("\n\n======== LAYER NEURONS: %d ========\n ", L->vector->rows );
	printVector(L->vector);
	printf("\n\n======== LAYER BIAS: %d ========\n ", L->bias->rows );
	printVector(L->bias);
	printf("\n-----------weights----------\n");
	printMatrix(L->matrix);	
	printf("\n");

}

void printAllLayers(Layers* ls) {

	for (int i = 0; i < ls->index-1; i++) {//< to not print the output layer
		printLayer(ls->layers[i]);

	}
}

Layer * constructLayer(size_t neuronsCount) {
	Vector* vector= initVector(neuronsCount);
	Vector* bias= initVector(neuronsCount);
	Layer * L = (Layer *) malloc(sizeof(Layer));
	L->vector = vector;
	L->bias = bias;
	return L;

}
 
