#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "src/structure.h"
#include "src/core.h"
#include <string.h>
#define WEIGHT_INIT 1
#define NEURON_INIT 1

void train(Layers *l ,Vector * expected){
	forwardPropagation(l);
	calcDelta(l,expected);
	backPropagation(l);
	meanSquareErrorCost(lastLayer(l),expected);
	errDiffVector(lastLayer(l),expected);
}
Layers * NN(Matrix * input, Matrix * output,int epoch){
	Layers * l = initLayers();
	Vector *  inputlayer =inputLayer(l); 
	Vector * expected=initVector(output->cols);
	int output_cols = output->cols;
	int rows = input->rows;
	int cols = input->cols;
	for(int k=0; k<epoch; k++){
		
		for(int i=0; i<rows; i++){
			memcpy(inputLayer(l)->vector,input->matrix+(i*cols),cols* sizeof(float)); 	
			memcpy(expected->vector,output->matrix+i*output_cols,output_cols* sizeof(float)); 	
			train(l, expected);
			printOutput(l);
		}
	}
	return l;
}
int main() {

	Matrix * inputs = initMatrix(4,2);
	Matrix * outputs = initMatrix(4,1);
	float fi[8] ={1,0,	1,1,	 0,1,	0.0};
	float fo[4] = {1,	0,	 1,	0};
	memcpy(inputs->matrix, fi,sizeof(float)*8);
	memcpy(outputs->matrix, fo,sizeof(float)*4);
	NN(inputs,outputs,10000);
 //	Layer inputLayer = constructLayer(2);
 //	Layer hiddenLayer = constructLayer(2);
 //	Layer outputLayer = constructLayer(1);

//	Layers* l = newLayers(3);
// 	addlayer(l, &inputLayer);
// 	addlayer(l, &hiddenLayer);
// 	addlayer(l, &outputLayer);
	

//	for (int i = 0; i < 2000; i++)
//	{
//		if (i%100 == 0)
//		{
		//	printf("iteration %d \n", i);
		//	printOutput(l);

//		}
		
	//	t2(l, &inputLayer);	

//	}
	
	//inputLayer.vector->vector[0]=1;
 	//inputLayer.vector->vector[1]=1;
	//forwardPropagation(l);
	//Vector * expected=initVector(1);

	//printOutput(l);
	printf("hedddllo");
	return 0;
}
