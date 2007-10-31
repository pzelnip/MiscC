#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>

/* the default number of threads to use */
#define NUMTHREADS 10

/* the shared mutex to "guard" access to the screen */ 
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

/* basic structure of a thread */
typedef struct
{
	pthread_t thread;
	int idNum;
	int delay;
} threadData;

/*
threadLogic - the main logic of each thread.  Expects that arg is a pointer
	to a threadData struct
*/
void * threadLogic(void * arg)
{
	threadData d = *(threadData *)arg;

	for (;;)
	{
		pthread_mutex_lock(&mut);

		printf ("in %d critical section (delay is %d)....\n", d.idNum, d.delay);

		pthread_mutex_unlock(&mut);

		sleep (d.delay);
	}

	return NULL;
}

/*
getNumThreads - parses the number of threads specified on the command line.
	If num threads cannot be determined from command line, then the
	default specified in NUMTHREADS is returned.  This function will
	always return an integer > 0. 
*/
int getNumThreads (int argc, char ** argv)
{
	/* if num not specified use default */
	if (argc <= 1) return NUMTHREADS;

	int r = atoi (argv[1]);

	/* sanity check: make sure numthreads is positive number */
	return (r < 1) ? NUMTHREADS : r;
}

int main(int argc, char ** argv)
{
	const int TCOUNT = getNumThreads (argc, argv);

	threadData threads[TCOUNT];
	int x;

	/* initialize & create threads */
	for (x = 0; x < TCOUNT; x++)
	{
		threads[x].idNum = x;
		threads[x].delay = x + 2;
		pthread_create(&(threads[x].thread), NULL, threadLogic, &(threads[x]));
	}
    
	/* wait for thread to finish */
	for (x = 0; x < TCOUNT; x++)
		pthread_join(threads[x].thread, NULL);

    return 0;
}

