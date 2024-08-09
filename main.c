#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "include/math.h"
#include "include/structure.h"
#include "include/neural_network.h"
#include <string.h>
#include <string.h>
#include <sys/types.h>
void xor_learn(){
	
	//linear input matrix of size 4 x 2
	Matrix * inputs = initMatrix(4,2);
	float inputsf[8] ={1,0,	1,1,	 0,1,	0,0};
	memcpy(inputs->matrix, inputsf,sizeof(float)*8);
	
	//linear input matrix of size 4 x 1
	Matrix * outputs = initMatrix(4,1);
	float outputf[4] = {1,	0,	 1,	0};
	memcpy(outputs->matrix, outputf,sizeof(float)*4);

	//layers Vector {2,2,1} 2 neurons at the input 2 inputs at the hidden layer 1 output
	Vector * layersV = initVector(3);
	float layers[3] = {2,2,1};
	memcpy(layersV->vector, layers,sizeof(float)*3);
	
	
	int layers_size=3;
	int learning_rate=1;
	neural_network nn = {
		.layers_size=layers_size,
		.layer_size = layersV,
		.learning_rate = learning_rate,
		.input =inputs,
		.output =outputs

	};
	construct_network(&nn);
	train_network(&nn,2000);
	nn.test_mode = 1;
	test_network(&nn);

}
int main() {
	
	xor_learn();

	printf("\n THE ENDs \n");
	return 0;
}
