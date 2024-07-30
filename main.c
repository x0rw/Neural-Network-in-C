#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "src/structure.h"
#include "src/core.h"
#define WEIGHT_INIT 1
#define NEURON_INIT 1
void train(Layers *l ,Vector * expected){
	forwardPropagation(l);
	calcDelta(l,expected);
	backPropagation(l);
	meanSquareErrorCost(lastLayer(l),expected);
	errDiffVector(lastLayer(l),expected);
}
void t2(Layers * l, Layer * inputLayer){
	Vector * expected=initVector(1);



	inputLayer->vector->vector[0]=1;
 	inputLayer->vector->vector[1]=0;
	expected->vector[0]=1;
	train(l, expected);


	inputLayer->vector->vector[0]=1;
 	inputLayer->vector->vector[1]=1;
	expected->vector[0]=0;
	train(l, expected);

	inputLayer->vector->vector[0]=0;
 	inputLayer->vector->vector[1]=0;
	expected->vector[0]=0;
	train(l, expected);
	train(l, expected);
	inputLayer->vector->vector[0]=0;
 	inputLayer->vector->vector[1]=1;
	expected->vector[0]=1;
	train(l, expected);

}
int main() {
 	Layer inputLayer = constructLayer(2);
 	Layer hiddenLayer = constructLayer(3);
 	Layer outputLayer = constructLayer(1);

	Layers* l = newLayers(3);
 	addlayer(l, &inputLayer);
 	addlayer(l, &hiddenLayer);
 	addlayer(l, &outputLayer);
	
	l->layers[0]->matrix->matrix[0]=0.1;
	l->layers[0]->matrix->matrix[1]=-0.8;
	l->layers[0]->matrix->matrix[2]=-0.4;
	l->layers[0]->matrix->matrix[3]=0.6;

	l->layers[1]->matrix->matrix[0]=-0.3;
	l->layers[1]->matrix->matrix[1]=0.9;
 	printAllLayers(l);
//	printOutput(l);

	for (int i = 0; i < 10000; i++)
	{
		t2(l, &inputLayer);
	}
	
	inputLayer.vector->vector[0]=0;
 	inputLayer.vector->vector[1]=1;
	forwardPropagation(l);
	Vector * expected=initVector(1);

	printOutput(l);
	printf("hedddllo");
	return 0;
}
