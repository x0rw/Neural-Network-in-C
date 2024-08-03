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



void train(Layers *l ,Vector * expected){
  printVector(expected);
	forwardPropagation(l);
	calcDelta(l,expected);
	backPropagation(l);
	meanSquareErrorCost(lastLayer(l),expected);
	errDiffVector(lastLayer(l),expected);
}
Layers * NN(Matrix * input, Matrix * output,int epoch){
	Layers * l = initLayers();
	Vector *  inputlayer =inputLayer(l); 
	Vector * expected=initVector(output->cols);
	int output_cols = output->cols;
	int rows = input->rows;
	int cols = input->cols;
	for(int k=0; k<epoch  ; k++){
		
		for(int i=0; i<rows; i++){
			memcpy(inputLayer(l)->vector,input->matrix+(i*cols),cols* sizeof(float)); 	
			memcpy(expected->vector,output->matrix+i*output_cols,output_cols* sizeof(float)); 	
			train(l, expected);
			printOutput(l);
		}
	}
	return l;
}


void meanSquareErrorCost(Vector* V, Vector* EV){
  int size = V->rows;
  float err=0.0f;
  for (int i = 0; i < size; i++){
    err += (V->vector[i] - EV->vector[i]) * (V->vector[i] - EV->vector[i]);
  }
  err = err/ (size+1);
  printf("\n\nMSE : %f \n", err);
}


void errDiffVector(Vector* V, Vector* EV){
  int size = V->rows;
  for (int i = 0; i < size; i++){
//    printf("VECT ERR: %f\n ",V->vector[i] - EV->vector[i]);
  }

}
void forwardPropagation(Layers *L)

{
  Layer * l;
  Vector *res_vector;
  int layersSize;
  Layer ** layers = L->layers;
  size_t layers_size = L->index;
  for (int i = 0; i < (int)layers_size-1; i++) {
    l = layers[i + 1];
    res_vector = MatrixMulVect(layers[i]->matrix,layers[i]->vector,layers[i]->bias);
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
    lvector->vector[j] = (ybar->vector[j] - m) * (1 - m) * m;
  }
  temp_layer->delta = lvector;
  for (int i = layers_size -2; i>=0; i--) {
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
  for (int ik = (int)layers_size -2; ik>=0; ik--) {
    l = layers[ik];
    int rows= l->matrix->rows;
    int cols= l->matrix->cols;
    float * weight = l->matrix->matrix;
    float * delta = previous_layer->delta->vector;
    float * output = l->vector->vector;
    float * bias = l->bias->vector;

    for(int i=0; i<rows; i++){
      for(int j =0; j<cols; j++){
        int offset = j + cols * i;
        bias[j] = bias[j]  + LR * delta[i]; 
        weight[offset] = weight[offset]  + LR *  output[j] * delta[i];
        }
	}
    previous_layer = l;



  }
}
