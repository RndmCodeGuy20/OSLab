#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    printf("We are in program 2 ID : %d\n", getpid());
    printf("Program 2 execution done\n");

    return 0;
}