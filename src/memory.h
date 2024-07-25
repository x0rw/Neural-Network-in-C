/** 
Here we delcare a custom heap allocator to manage the allocated memory into a table 
*/

#include <stdio>

#ifndef MAX_ALLOC 
#define MAX_ALLOC 100
#endif
struct allocated{
	void * heap_address;
	int size;
};
struct allocated * initAllocationTable(size_t size){
	struct allocated * allc= (struct allocated *)malloc(sizeof(struct allocated)*size);

}
struct allocated alloc_table[MAX_ALLOC];

struct memory_table * initMemoryTable(){
	struct memory_table mt= malloc(sizeof(struct memory_table));
	return &mt
}
void * nnmalloc(size_t size, struct allocated* atb){
	void *heap_addr = (void *)malloc (size);
	if(heap_addr == NULL){
		printf("failed to allocate memory of size %d at nmalloc", size);
		exit(-55);
	}
	struct allocated alloc;
	alloc->size = size;
	alloc->heap_address = heap_addr;
	
}
