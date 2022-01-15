#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>
#include <pthread.h>

int globVar = 0;

void *threadFunc(void *vargp)
{
    int id;
    static int s;

    sleep(1);

    printf("Hello Shantanu ~ ThreadFunc!\n");

    id = (int)vargp;
    globVar++;
    s++;

    printf("ID : %d\n", id);
    printf("S : %d\n", s);
    printf("Global : %d\n", globVar);
}

int main()
{
    pthread_t threadID;

    printf("Before creating thread!!!\n");

    for (int i = 0; i < 3; i++)
    {
        printf("Thread Number : %d --->\t", i);
        pthread_create(&threadID, NULL, threadFunc, (void *)i);
        pthread_join(threadID, NULL);
    }

    printf("After Threading!!!\n");

    return 0;
}