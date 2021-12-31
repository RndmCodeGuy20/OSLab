#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{

    int id;
    int id2;
    int id3;

    printf("Start of Program!!!\n");

    id = fork();

    if (id > 0)
    {
        printf("We are in Parent Process.\nParent ID : %d\n", getpid());

        //     id3 = fork();

        //     if (id3 > 0)
        //     {
        //         printf("We are in Parent's Parent Process.\nParent Parent ID : %d\n", getpid());
        //     }
        //     else if (id3 == 0)
        //     {
        //         printf("We are in Parent's Child Process.\nParent Child ID : %d\n", getpid());
        //     }
        //     else
        //     {
        //         printf("☢️☢️☢️☢️\n");
        //     }
    }
    else if (id == 0)
    {
        printf("We are in Child Process.\nChild ID : %d\n", getpid());

        id2 = fork();

        if (id2 > 0)
        {
            printf("We are in Child's Parent Process.\nChild Parent ID : %d\n", getpid());
        }
        else if (id2 == 0)
        {
            printf("We are in Child's Child Process.\nChild Child ID : %d\n", getpid());
        }
        else
        {
            printf("☢️☢️☢️☢️\n");
        }
    }
    else
    {
        printf("☢️☢️☢️☢️\n");
    }

    printf("😁😁😁😁😁\n");

    return 0;
}
