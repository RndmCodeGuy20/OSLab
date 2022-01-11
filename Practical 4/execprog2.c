#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{

    printf("We are currently in Program 🥈 with ProcessID : %d\n", getpid());

    printf("Name is : %s\nAge is : %s\n\n", *(argv + 1), *(argv + 2));

    printf("Program 2 execution done!!! Ending Execution!!!\n");

    return 0;
}