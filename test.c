#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>

int main()
{
    int n, fd;
    char buff[50];

    creat("test2.txt", O_WRONLY);

    fd = open("test.txt", O_RDONLY);
    int fd2 = open("test2.txt", O_RDONLY);

    printf("\nfile descriptor : %d\n", fd2);

    n = read(fd, buff, 100);

    write(1, buff, n);

    unlink("test.txt");

    return 0;
}