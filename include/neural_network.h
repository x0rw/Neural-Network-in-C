#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "../include/math.h"
#include "../include/structure.h"
#include "../include/core.h"


typedef struct neural_network{
	int layers_size;
	Vector * layer_size;
	int learning_rate;
	Matrix * input;
	Matrix * output;
	Layers * layers;
}neural_network;

void construct_network(neural_network * );
void train_network(neural_network *, int );
