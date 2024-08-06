#ifndef STRUCTURE_H
#define STRUCTURE_H
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include "../include/math.h"

#define WEIGHT_INIT 1
#define NEURON_INIT 1




typedef struct {
	Vector *vector; 
	Matrix *matrix; 
	Vector *bias; 
	Vector *delta; 
}Layer;
typedef struct Layers {
	size_t size;
	size_t index;
	Layer** layers;
} Layers;

Layers * newLayers(size_t);
Layer * constructLayer(size_t);
void initWeightMatrix(Layer* , int [2]);
void addlayer(Layers *, Layer * );
void printLayer(Layer*);
void printAllLayers(Layers*);
Vector * inputLayer(Layers *);
Layers * initLayers();
Vector * lastLayer(Layers * );
void printOutput(Layers * );
#endif