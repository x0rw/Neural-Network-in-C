#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "src/structure.h"
#include "src/propagation.h"
#define WEIGHT_INIT 1
#define NEURON_INIT 1

int main() {
 	Layer inputLayer = constructLayer(2);
 	Layer hiddenLayer = constructLayer(400);
 	Layer outputLayer = constructLayer(100);
 	Layer outputLayer1 = constructLayer(10);
	inputLayer.vector->vector[0]=21;
 	inputLayer.vector->vector[1]=45.2;
	printf("tab1:%f,\n",inputLayer.vector->vector[1]);
	Layers* l = newLayers(4);
 	addlayer(l, &inputLayer);
 	addlayer(l, &hiddenLayer);
 	addlayer(l, &outputLayer);
 	addlayer(l, &outputLayer1);
	forwardPropagation(l);
 	printAllLayers(l);
	printf("=============");	
	outputN(l);









	printf("hedddllo");
	return 0;
}
