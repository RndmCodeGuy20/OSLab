#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

int shared = 1;
sem_t s;

void *methA()
{
    int x1;
    sem_wait(&s);

    x1 = shared;
    printf("\nValue of shared in Thread One : %d\n", x1);

    x1++;

    printf("\nLocal Value of shared in Thread One After Increment : %d\n", x1);
    sleep(2); //` Preemption

    shared = x1;

    printf("\nValue of shared in Thread One After Increment : %d\n", shared);

    sem_post(&s);
}

void *methB()
{
    int x2;
    sem_wait(&s);

    x2 = shared;
    printf("\nValue of shared in Thread Two : %d\n", x2);

    x2++;

    printf("\nLocal Value of shared in Thread Two After Increment : %d\n", x2);
    sleep(1); //` Preemption

    shared = x2;

    printf("\nValue of shared in Thread Two After Increment : %d\n", shared);

    sem_post(&s);
}

int main()
{
    sem_init(&s, 0, 1);

    pthread_t pThread1, cThread2;
    pthread_create(&pThread1, NULL, methA, NULL);
    pthread_create(&cThread2, NULL, methB, NULL);

    pthread_join(pThread1, NULL);
    pthread_join(cThread2, NULL);

    printf("\n\nFinal value of shared variable : %d\n", shared);

    return 0;
}