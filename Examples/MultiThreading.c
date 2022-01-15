#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

void *threadFunc()
{
    sleep(3);
    printf("Inside ThreadFunc1!\n");
    pthread_exit((void *)42);
}

void *threadFunc2()
{
    printf("Inside ThreadFunc2!!!\n");
}

int main(int argc, char const *argv[])
{
    pthread_t threadID;

    printf("Before creating thread!!!\n");

    for (int i = 0; i < 3; i++)
    {
        printf("Thread Number : %d\t", i);

        if (i == 2)
        {
            pthread_create(&threadID, NULL, threadFunc2, NULL);
            pthread_join(threadID, NULL);
        }

        pthread_create(&threadID, NULL, threadFunc, NULL);
        pthread_join(threadID, NULL);
    }

    printf("After Threading!!!\n");

    return 0;
}
