#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int n, fd;

    char buff[50];

    fd = open("test.txt", O_RDONLY);
    printf("The descriptor of the file is : %d", fd);

    n = read(fd, buff, 20);

    write(1, buff, n);

    return 0;
}