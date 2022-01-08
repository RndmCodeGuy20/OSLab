#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    pid_t childPID;

    if (fork() == 0)
    {
        exit(0);
    }
    else
    {
        childPID = wait(NULL);
    }

    printf("Child ID : %d\n", childPID);
    printf("Parent ID : %d\n", getpid());
    
    return 0;
}