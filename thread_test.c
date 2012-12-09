#include "cma.h"
#include "project_config.h"
#include <pthread.h>
//#include <iostream>
//#include <vector>

#define MSIZE 1024*16
unsigned char mem[MSIZE];


typedef struct thread_pair {
//        thread_pair() { id=0; arg=0; exit_status=NULL; };
        pthread_t id;
        int arg;
        void *exit_status;
};

void *thread_func(void *arg) {
	int i;
	char *strings[10];

	for (i = 0; i<10; i++)
		strings[i] = (char *)class_malloc(1024); //allocate from classmem library
	for (i = 9; i>=0; i--) 
		class_free(strings[i]);
	class_stats();
}

int main() {
	printf("Version %f.%f\n", cs224_project_VERSION_MAJOR, cs224_project_VERSION_MINOR);

	class_memory(mem,MSIZE); // give it memory allocator
	struct thread_pair threads[10];

        void *exit_status;
        printf( "Thread Test begin...\n");

        // main program continues while thread executes
	int i=1;
        for(i=1; i < 10; ++i) {
                threads[i].arg = i;
                pthread_create(&(threads[i].id), NULL, thread_func, &(threads[i].arg));
        }

        // wait for the thread to terminate
        for(i=1; i < 10; ++i) {
                pthread_join(threads[i].id, &(threads[i].exit_status));
        }

	printf("Thread test end...\n");
        return 0;

}

