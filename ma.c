#include "cma.h"
#include "project_config.h"

#define MSIZE 1024*16
unsigned char mem[MSIZE];

int main(int argc, char * argv[]) {
	printf("Version %f.%f\n", cs224_project_VERSION_MAJOR, cs224_project_VERSION_MINOR);

	int i;
	char *strings[10];
	class_memory(mem,MSIZE); // give it memory allocator

	for (i = 0; i<10; i++)
		strings[i] = (char *)class_malloc(1024); //allocate from classmem library
	for (i = 9; i>=0; i--) 
		class_free(strings[i]);
	class_stats();

	return 0;
}
