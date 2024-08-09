#include "../include/neural_network.h"

void construct_network(neural_network * nn){
	nn->layers =  newLayers(nn->layers_size);
	//construct layers
	for (int i = 0; i<nn->layers_size; i++)
	{
		Layer * cl = constructLayer((int)nn->layer_size->vector[i]);
	 	addlayer(nn->layers, cl);
	}
}
void train_network(neural_network *nn, int epoch){
	Layers * l=nn->layers;
	void (*func)(neural_network *, Vector *);
	if(nn->test_mode == 1){
		func = test_net;
	}else {func = train;};
	Matrix * input = nn->input;
	Matrix * output = nn->output;
	Vector *  inputlayer =l->layers[0]->vector; 
	Vector * expected=initVector(output->cols);
	int output_cols = output->cols;
	int rows = input->rows;
	int cols = input->cols;
	for(int k=0; k<epoch  ; k++){	
		for(int i=0; i<rows; i++){
			vectorize(input, inputlayer, i);
			vectorize(output, expected, i);

			func(nn, expected);
		//	printOutput(l);
		}
	//printf("heee\n\n\n\n\ndddddddd");	
	//printVector(expected);
	}


}
void test_network(neural_network *nn){

	train_network(nn, 2);

}




// (gdb) p output
// $2 = (Matrix *) 0x4ba80f0
// (gdb) p *output
// $3 = {rows = 4, cols = 1, matrix = 0x4ba8140}
// (gdb) p *expected
// $4 = {rows = 1, vector = 0x4ba8d20}
// (gdb) p *expected

