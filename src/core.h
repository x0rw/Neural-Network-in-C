
void forwardPropagation(Layers *L)

{
  Layer * l;
  Vector *res_vector;
  int layersSize;
  Layer ** layers = L->layers;
  size_t layers_size = L->index;
  for (int i = 0; i < (int)layers_size-1; i++) {
    l = layers[(long)i + 1];
    res_vector = MatrixMulVect(layers[i]->matrix,layers[i]->vector);
    l->vector = res_vector;
  }
  return;
}




void calcDelta(Layers *ls,Vector *ybar)

{
  Layer *l;
  Vector *outdelta;
  Vector *vect;
  Vector *delta;
  
  Layer ** layers = ls->layers;
  size_t layers_size = ls->size;
  Layer * temp_layer = layers[layers_size - 1];
  Vector *lvector = initVector(temp_layer->vector->rows);
  for (int j = 0; j < temp_layer->vector->rows; j++) {
    float m = temp_layer->vector->vector[j];
    lvector->vector[j] = (ybar->vector[j] - m) * (1.0 - m) * m;
  }
  temp_layer->delta = lvector;
  for (int i = (int)layers_size + -2; i>=0; i--) {
    l = layers[i];
    lvector = l->vector;
    outdelta = initVector(lvector->rows);
    for (int j = 0; j < lvector->rows; j++) {
      outdelta->vector[j] = (1.0 - lvector->vector[j]) * lvector->vector[j];
      float dw_sum = 0.0;
      for (int k = 0; k < l->matrix->rows;  k++) {
        dw_sum = l->matrix->matrix[k + l->matrix->rows * j] *
                 temp_layer->delta->vector[k] + dw_sum;
      }
      outdelta->vector[j] = outdelta->vector[j] * dw_sum;
    }
    l->delta = outdelta;
    temp_layer = l;
  }
  return;
}

void backPropagation(Layers *ls){
  Layer *l;
  Layer ** layers = ls->layers;
  size_t layers_size = ls->size;
  Layer *previous_layer = layers[layers_size-1];
  printf("\ndelta: %f ", previous_layer->delta->vector[0]);
  for (int i = (int)layers_size -2; i>=0; i--) {
    l = layers[i];
    int rows= l->matrix->rows;
    int cols= l->matrix->cols;
    float * weight = l->matrix->matrix;
    float * delta = previous_layer->delta->vector;
    float * output = l->vector->vector;

    for(int i=0; i<rows;i++){
		
		for(int j =0; j<cols;j++){
			int offset = j+ cols *i;
            //printf("\nweight: %f \t ", weight[offset]);
            weight[offset] = weight[offset]  + 1 *  output[j]* delta[i]; 
            //printf(" delta: %f \t",  output[j]* delta[i]);
            printf(" updated weight: %f \t", weight[offset]);
		}
        printf("\n===========================\n");
	}
    previous_layer = l;



  }
}