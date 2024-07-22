#include <stdio.h>
#include "../src/structure.h"
#include "TestLib.h"

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

