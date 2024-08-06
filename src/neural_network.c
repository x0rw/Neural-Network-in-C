#include "../include/neural_network.h"

void construct_network(neural_network * nn){
	Layers* ls = newLayers(nn->layers_size);
	//construct layer
	for (int i = 0; i<nn->layers_size; i++)
	{
		Layer * cl = constructLayer(nn->layer_size->vector[i]);
	 	addlayer(ls, cl);
	}
	nn->layers= ls;
	printf("\n%d Layers Constructed\n",nn->layers_size);
	
}
void train_network(neural_network *nn, int epoch){
	Layers * ls = nn->layers;
	Layers * l = initLayers();
	Matrix * input = nn->input;
	Matrix * output = nn->output;
	Vector *  inputlayer =inputLayer(l); 
	Vector * expected=initVector(output->cols);
	int output_cols = output->cols;
	int rows = input->rows;
	int cols = input->cols;
	for(int k=0; k<epoch  ; k++){	
		for(int i=0; i<rows; i++){
			vectorize(input, inputlayer, i);
			vectorize(output, expected, i);

			train(l, expected);
			printOutput(l);
		}
	}

}





