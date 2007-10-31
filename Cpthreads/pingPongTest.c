#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;

typedef struct
{
    pthread_t thread;
    char name[10];
    int delay;
} threadData;

void * threadLogic(void * arg)
{
    threadData d = *(threadData *)arg;

    for (; ; sleep (d.delay)) 
    {
        pthread_mutex_lock(&mut);

        printf ("in %s critical section (delay is %d)....\n", d.name, d.delay);

        pthread_mutex_unlock(&mut);
    }
    return NULL;
}

int main(void)
{
    threadData ping, pong;

    strncpy (ping.name, "ping", 5);
    ping.delay = 10;

    strncpy (pong.name, "pong", 4);
    pong.delay = 2;

    pthread_create(&(ping.thread), NULL, threadLogic, &ping);
    pthread_create(&(pong.thread), NULL, threadLogic, &pong);
    
    /* wait for thread to finish */
    pthread_join(ping.thread, NULL);
    pthread_join(pong.thread, NULL);

    return 0;
}

