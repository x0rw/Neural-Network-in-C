#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "src/structure.h"
#define WEIGHT_INIT 1
#define NEURON_INIT 1


int main() {
 	Layer inputLayer = constructLayer(3);
 	Layer hiddenLayer = constructLayer(2);
 	Layer outputLayer = constructLayer(2);
 	Layers* l = newLayers(3);
 	addlayer(l, &hiddenLayer);
 	addlayer(l, &inputLayer);
 	addlayer(l, &outputLayer);
 	printAllLayers(l);









	printf("hedddllo");
	return 0;
}
