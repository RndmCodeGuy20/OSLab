#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>

int main()
{
    pid_t pid;

    pid = fork();

    if (pid < 0)
    {
        printf("\nProcess Fork FAILED!!!\n");
        return 1;
    }
    else if (pid == 0)
    {
        execlp("/bin/ls", "ls", NULL);
        printf("\nChild Process\n");
    }
    else
    {
        printf("\nChild Complete\n");
    }

    return 0;
}