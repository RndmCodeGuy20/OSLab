#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd;

    //- Creating a new file.
    fd = creat("FileCreated.txt", O_RDONLY);
    printf("File descriptor value of file creation : %d\n", fd);

    //- Writing in newly created file
    

    return 0;
}