#include "../include/structure.h"

#ifndef LR
#define LR 0.8
#endif
void calcDelta(Layers *,Vector *);
void forwardPropagation(Layers *);
void backPropagation(Layers *);
void errDiffVector(Vector* , Vector*);
void meanSquareErrorCost(Vector* , Vector* );
void train(Layers * , Vector *);
Layers * NN(Matrix * , Matrix *, int);
