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
    int *sharedMem;
    int shmID;

    shmID = shmget((key_t)2002, 1024, 0666 | IPC_CREAT);
    printf("Unique key of segment : %d\n", shmID);

    sharedMem = shmat(shmID, NULL, 0);
    printf("Process is attached at address : %p\n", sharedMem);

    sharedMem[0] = 1000;

    int n1 = fork();
    int n2 = fork();

    if (n1 > 0 && n2 > 0)
    {
        printf("\nParent process ID : %d\n", getpid());
    }
    else if (n1 > 0 && n2 == 0)
    {
        printf("\nChild A process ID : %d\n", getpid());

        for (int i = 0; i < 5; i++)
        {
            sharedMem[0] = sharedMem[0] + 200;
        }

        printf("\nFinal shared memory value in Child A : %d\n", sharedMem[0]);
    }
    else if (n1 == 0 && n2 > 0)
    {
        printf("\nChild B process ID : %d\n", getpid());

        for (int i = 0; i < 5; i++)
        {
            sharedMem[0] = sharedMem[0] + 100;
        }

        printf("\nFinal shared memory value in Child B : %d\n", sharedMem[0]);
    }

    int shmREM = shmctl(shmID, IPC_RMID, NULL);

    return 0;
}