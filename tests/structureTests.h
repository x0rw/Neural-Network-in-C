#include <stdio.h>
#include "../src/structure.h"
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
void LayersTest(){
	printf("==== Testing newLayers...\n");
	Layers * nl1=newLayers(15);
	Layers * nl2=newLayers(100);
	Layers * nl3=newLayers(1);
	check_int(nl1->size,15);
	check_int(nl2->size,100);
	check_int(nl3->size,1);
	
	printf("\n");
}
void LayerConstructTest(){


	printf("==== Testing constructLayer...\n");
	Layer nl1= constructLayer(1);
	check_int(nl1.neuronsCount,1);
	
	Layer nl2= constructLayer(100);
	check_int(nl2.neuronsCount,100);

	printf("\n");
}

