

#ifndef CORE_H
#define CORE_H
#include "../include/structure.h"
#include "../include/neural_network.h"

#ifndef LR
#define LR 0.8
#endif
void test_net(neural_network *,Vector * );
void calcDelta(Layers *,Vector *);
void forwardPropagation(Layers *);
void backPropagation(neural_network *);
void errDiffVector(Vector* , Vector*);
void meanSquareErrorCost(Vector* , Vector* );
void train(neural_network * , Vector *);
#endif