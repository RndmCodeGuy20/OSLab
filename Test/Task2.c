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

int main(int argc, char const *argv[])
{
    int k;
    void *sharedMem;
    char buffer[200];
    int shmID;

    shmID = shmget((key_t)2345, 1024, 0666 | IPC_CREAT);
    printf("Unique key of segment : %d\n", shmID);

    sharedMem = shmat(shmID, NULL, 0);
    printf("Process is attached at address : %p\n", sharedMem);

    printf("Reading the data from shared memory : %s\n", (char *)sharedMem);

    return 0;
}

//- Task1 -> create a segment, attach segment, write an array to this segment
//- Task2 -> attach shared memory content, calculate sum from array
//- Task3 -> odd and even elements