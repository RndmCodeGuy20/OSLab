#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <string.h>

int main()
{
    int k;
    int *sharedMem;
    int buffArr[20];
    int shmID;

    shmID = shmget((key_t)7262, 1024, 0666 | IPC_CREAT);
    printf("Unique key of segment : %d\n", shmID);

    sharedMem = shmat(shmID, NULL, 0);
    printf("Process is attached at address : %p\n", sharedMem);

    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &buffArr[i]);
        *(sharedMem + i) = buffArr[i];
    }

    for (int i = 0; i < 10; i++)
    {
        printf("Data entered by user is : %d\n", *(sharedMem + i));
    }

    return 0;
}