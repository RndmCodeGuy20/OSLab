#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char const *argv[])
{
    int count = write(1, "RCOEM\n", 6);
    
    //- 1 is the file descriptor,
    //- "RCOEM" is the data,
    //- 6 is the count of characters in the word.

    printf("\nNumber of chars : %d\n", count);
    return 0;
}
