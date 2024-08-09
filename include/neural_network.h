#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "../include/math.h"
#include "../include/structure.h"
#include "../include/core.h"
#ifndef NEURAL_NETWORK_H
#define NEURAL_NETWORK_H
typedef struct neural_network{
	int layers_size;
	Vector * layer_size;
	int learning_rate;
	Matrix * input;
	Matrix * output;
	Layers * layers;
	int test_mode;
}neural_network;

void construct_network(neural_network * );
void train_network(neural_network *, int );
void test_network(neural_network *);
#endif