#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd, n;
    char buff[50];
    char writeBuff[100];

    //- Writing terminal text to file.
    printf("Enter data you want to write in the file : ");
    n = scanf("%c", writeBuff);
    fd = open("WriteFile.txt", O_WRONLY);
    
    
    write(fd, writeBuff, n);

    //- Printing string without printf.
    fd = write(1, "Printing string without printf\n", 30);

    //- Writing content of file to the terminal.
    fd = open("ReadFile.txt", O_RDONLY);
    printf("\nThe descriptor of the file in read only mode is : %d\n", fd);
    n = read(fd, buff, 30);
    write(1, buff, n);

    //- Closing the opened file
    if (close(fd) < 0)
    {
        perror("c1");
        exit(1);
    }
    printf("\nFile closed successfully!\n");

    return 0;
}