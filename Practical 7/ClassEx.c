#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>

int i = 0, j = 0;

void *producer(void *par)
{
    do
    {
        printf("\nInside Producer!!!\n %d", i);
        i++;
        sleep(1);
    } while (1);

    pthread_exit(0);
}

void *consumer(void *par)
{
    do
    {
        printf("\nInside Consumer!!!\n %d", j);
        j++;
        sleep(1);
    } while (1);

    pthread_exit(0);
}

int main()
{
    pthread_t pThread1, cThread2;
    pthread_create(&pThread1, NULL, producer, NULL);
    pthread_create(&cThread2, NULL, consumer, NULL);

    pthread_join(pThread1, NULL);
    pthread_join(cThread2, NULL);

    return 0;
}