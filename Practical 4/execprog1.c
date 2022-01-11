#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{

    printf("We are currently in Program 🥇 with ProcessID : %d\n", getpid());

    execv("./prog2.out", argv);

    printf("☢️☢️☢️If you're seeing this line, you encountered an error somewhere!!!☢️☢️☢️\n");

    return 0;
}
