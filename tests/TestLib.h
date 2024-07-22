#include <stdio.h>

static int failed_tests=0;
static int succ_tests=0;
int check_int(int a, int b){
	if(a==b){
		succ_tests++;
		printf("Test Successful\n");
		return 1;
	}
	failed_tests++;
	printf("Test Failed, excpected:%d, \t Recieved:%d\n",b,a);
	return 0;
}


int check_vect(Vector *a, Vector *b){
	for(int i = 0; i<a->rows;i++){
			if(a->vector[i] != b->vector[i]){
				failed_tests++;
				printf("\nTest Failed (MatrixMulVector)!!!\n");
				return 0;

		}
	}
	succ_tests++;
	printf("Test Successful\n");
	return 1;
}
