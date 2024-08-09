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
#define WEIGHT_INIT 1
#define NEURON_INIT 1
// const char* getfield(char* line, int num)
// {
//     const char* tok;
//     for (tok = strtok(line, ",");
//             tok && *tok;
//             tok = strtok(NULL, ",\n"))
//     {
//         if (!--num)
//             return tok;
//     }
//     return NULL;
// }

int main() {
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


//   	FILE * fp;
//     char * line = NULL;
//     size_t len = 0;
//     ssize_t read;

//     fp = fopen("mnist_train.csv", "r");
//     if (fp == NULL)
//         exit(EXIT_FAILURE);
// 	int i = 0;
// 	Matrix * input = initMatrix(50000,784);
// 	Matrix * output = initMatrix(50000,10);
// 	for(int ko = 0; ko<10*50000; ko++)output->matrix[ko]=0;
//     while ((read = getline(&line, &len, fp)) != -1 && i!= 50000) {
// //        printf("%s", line);
// 		int k=0;
// 		char *cline = line;
// 		char * array[20000];
// 		array[k] = strtok(line, ",");
// 		int off = i*10+atoi(array[k]);
// 		output->matrix[off]=1;
// 		int offset;
// 		while(array[k] != NULL){
// 			// if(k %28 ==0) printf("\n");
// 			// if(atoi(array[k]) != 0){
// 			//     printf(" - 1");
// 			// }else	printf(" -%s ",array[k]);
// 			k++;
// 			array[k] = strtok(NULL, ",");
// 			if(array[k]==NULL) break;
// 			offset = i * 784 + k-1;
// 			// printf("offset %d\n",offset);
// 			input->matrix[offset]=atof(array[k])/255;
			
// 		}
		
// 		i++;

//     }

// //	printMatrix(output);
// //	printMatrix(input);
//     fclose(fp);
//     if (line)
//         free(line);



	//	NN(inputs,outputs,10000);
	printf("\n THE ENDs \n");
	return 0;
}
