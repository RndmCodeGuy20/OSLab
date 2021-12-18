#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char const *argv[])
{
    printf("My name is Shantanu Mane!\nI am in OS lab\n-----------%d\n",getpid());

    return 0;
}
