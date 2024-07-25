#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "src/structure.h"
#include "src/propagation.h"
#define WEIGHT_INIT 1
#define NEURON_INIT 1


int main() {
 	Layer inputLayer = constructLayer(3);
 	Layer hiddenLayer = constructLayer(2);
 	Layer outputLayer = constructLayer(2);
	
 	Layers* l = newLayers(3);
 	addlayer(l, &inputLayer);
 	addlayer(l, &hiddenLayer);
 	addlayer(l, &outputLayer);
	forwardPropagation(l);
 	printAllLayers(l);









	printf("hedddllo");
	return 0;
}
