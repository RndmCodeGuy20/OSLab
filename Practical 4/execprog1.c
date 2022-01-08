#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int inp1,inp2;

    printf("We are currently in Program 🥇 with ProcessID : %d\n", getpid());

    printf("Enter the numbers : ");
    scanf("%d %d",&inp1,&inp2);

    char *args[] = {inp1,inp2,NULL};

    execv("./prog2.out", args);

    printf("☢️☢️☢️If you're seeing this line, you encountered an error somewhere!!!☢️☢️☢️\n");

    return 0;
}
