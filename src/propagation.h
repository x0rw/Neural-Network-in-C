#include <stdio.h>
void forwardPropagation(Layers *L){
	Layer ** layers=L->layers;
	int layersSize= L->index;
	for(int i= 0; i<layersSize-1;i++){
		layers[i+1]->vector = MatrixMulVect(layers[i]->matrix,layers[i]->vector); 
		
	}
}
