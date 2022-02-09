#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

int pointer = 0;
int buffer[10];

sem_t s;

void *producer()
{
    int tempBuff[20];
    sem_wait(&s);

    printf("\nProducer is producing values and storing in buffer!!!\n");

    for (int i = 0; i < 10; i++)
    {
        tempBuff[i] = (3 * i + 1) / 2;
    }

    sleep(1); //` Preemption

    for (int i = 0; i < 10; i++)
    {
        buffer[i] = tempBuff[i];
    }

    sem_post(&s);
}

void *consumer()
{
    int x2;
    sem_wait(&s);

    printf("\nConsumer is consuming the values!!!\n");

    sleep(1);

    for (int i = 0; i < 10; i++)
    {
        printf("%d   ", buffer[i]);
    }

    printf("\n");

    sem_post(&s);
}

int main()
{
    sem_init(&s, 0, 1);

    pthread_t pThread1, cThread2;
    
    pthread_create(&pThread1, NULL, producer, NULL);
    pthread_create(&cThread2, NULL, consumer, NULL);

    pthread_join(pThread1, NULL);
    pthread_join(cThread2, NULL);

    return 0;
}