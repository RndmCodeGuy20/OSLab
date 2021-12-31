#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

int sum = 0;

void *Summation(void *arg)
{
    int *limPtr = (int *)arg;
    int lim = *limPtr;

    for (int i = 0; i < lim; i++)
    {
        sum += i;
    }
    pthread_exit(0);
}

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("Usage : %s <num>\n", argv[0]);
        exit(-1);
    }

    int lim = atoll(argv[1]);

    pthread_t threadID;
    pthread_attr_t thrdAttr;

    pthread_attr_init(&thrdAttr);
    pthread_create(&threadID, &thrdAttr, Summation, &lim);
    pthread_join(threadID, NULL);
    printf("\nSum = %d\n", sum);

    return 0;
}
