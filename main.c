#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "src/structure.h"
#include "src/core.h"
#define WEIGHT_INIT 1
#define NEURON_INIT 1

int main() {
 	Layer inputLayer = constructLayer(2);
 	Layer hiddenLayer = constructLayer(2);
 	Layer outputLayer = constructLayer(1);
	inputLayer.vector->vector[0]=0.35;
 	inputLayer.vector->vector[1]=0.9;
	Layers* l = newLayers(3);
 	addlayer(l, &inputLayer);
 	addlayer(l, &hiddenLayer);
 	addlayer(l, &outputLayer);
	l->layers[0]->matrix->matrix[0]=0.1;
	l->layers[0]->matrix->matrix[1]=0.8;
	l->layers[0]->matrix->matrix[2]=0.4;
	l->layers[0]->matrix->matrix[3]=0.6;

	l->layers[1]->matrix->matrix[0]=0.3;
	l->layers[1]->matrix->matrix[1]=0.9;
 	printAllLayers(l);
	printf("===++++++++++++++++==========");	
	forwardPropagation(l);
 	printAllLayers(l);
	printf("=============");	
	printOutput(l);
	Vector * expected=initVector(1);
	expected->vector[0]=0.5;
	//errorVect(lastLayer(l),expected);
	//meanSquareErrorCost(lastLayer(l),expected);
	calcDelta(l,expected);
	printf("\nlayer======\n");
	printVector(l->layers[0]->delta);
	printf("\nlayer======\n");
	printVector(l->layers[1]->delta);
	printf("\nlayer======\n");
	printVector(l->layers[2]->delta);

	backPropagation(l);


	printf("hedddllo");
	return 0;
}
