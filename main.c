#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "include/math.h"
#include "src/structure.h"
#include "src/core.h"

#include "include/neural_network.h"
#include <string.h>
#define WEIGHT_INIT 1
#define NEURON_INIT 1

int main() {

	Matrix * inputs = initMatrix(4,2);
	Matrix * outputs = initMatrix(4,1);
	float inputsf[8] ={1,0,	1,1,	 0,1,	0.0};
	float outputf[4] = {1,	0,	 1,	0};
	int layers[3] = {1,2,1};
	memcpy(inputs->matrix, inputsf,sizeof(float)*8);
	memcpy(outputs->matrix, outputf,sizeof(float)*4);
	Vector * layersV = initVector(3);
	memcpy(layersV->vector, layers,sizeof(int)*3);
	int layers_size=3;
	neural_network nn = {
		.layers_size=layers_size,
		.layer_size = layersV,
		.learning_rate = 0.8,
		.input =inputs,
		.output =outputs
	};
	construct_network(&nn);
	train_network(&nn,10000);
	//	NN(inputs,outputs,10000);
	printf("\n hedddllo \n");
	return 0;
}
