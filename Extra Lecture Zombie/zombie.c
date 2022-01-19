#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>

int main()
{
    pid_t childPID = fork();

    if (childPID > 0)
    {
        sleep(1);
        printf("We are in the parent process!!!\n");
    }
    else if (childPID == 0)
    {
        printf("We are in the child process!!!\n");
    }

    else
    {
        printf("Ha vau\n");
    }

    return 0;
}