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

// int shmget(key_t key, size_t size, int shmflag);
// void *shmat(int shmID, const void *shmadrr, int shmflag);

int main()
{
    int k;
    void *sharedMem;
    char buffer[200];
    int shmID;

    shmID = shmget((key_t)2345, 1024, 0666 | IPC_CREAT);
    printf("Unique key of segment : %d\n", shmID);

    sharedMem = shmat(shmID, NULL, 0);
    printf("Process is attached at address : %p\n", sharedMem);

    read(0, buffer, 100);
    strcpy(sharedMem, buffer);

    printf("Data entered by user is : %s\n", (char *)sharedMem);

    return 0;
}