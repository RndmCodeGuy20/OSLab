#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    int a = 20, b = 30;
    int c = a + b;
    printf("We are currently in program 🥈 ID : %d\nSum of %d and %d = %d\n", getpid(), a, b, c);
    printf("Program 2 execution done!!! Ending Execution!!!\n");

    return 0;
}