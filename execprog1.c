#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    printf("Process ID of program is : %d\n", getpid());

    char *args[] = {"Monday", "Tuesday", "Wednesday", "Thursday", NULL};

    execv("./prog2.out", args);

    printf("Back to program 1!\n");

    return 0;
}
