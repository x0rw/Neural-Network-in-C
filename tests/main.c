#include <stdio.h>
#include "structureTests.h"
#include "mathTests.h"



int main(){
		
	LayersTest();
	LayerConstructTest();
	MatrixMulVectorTest();
	int total_tests=failed_tests+succ_tests;
	printf("Number of tests:%d\n", total_tests);
	printf("- %d/%d tests failed\n",failed_tests, total_tests);
	printf("+ %d/%d tests succeded\n",succ_tests, total_tests);
}
