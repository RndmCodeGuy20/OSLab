#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int n, fd, fd2;

    char buff[50];

    fd = open("test.txt", O_RDONLY);
    printf("The descriptor of the file is : %d\n", fd);

    n = read(fd, buff, 20);
    printf("\n%d\n", n);
    fd2 = open("write.txt", O_WRONLY | O_CREAT, 0642);
    write(f
d2, buff, n);
    return 0;
}