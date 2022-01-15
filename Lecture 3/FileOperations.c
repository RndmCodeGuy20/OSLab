#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    char choice = 'A';
    char str[20];
    int FD, secFD;
    char *buff = (char *)calloc(64, sizeof(char));

    printf("\n📂📂📁📁 File Operations Program : Shantanu Mane 📁📁📂📂\n\n");
    while (1)
    {
        printf("C. Create a File\nO. Open a File\nS. Close a File\nW. Write in a File\nR. Read from a File\nU. Unlink a File\nL. Lseek\nX. Exit from the Program\n");
        scanf("%c", &choice);

        switch (choice)
        {
        case 'C':
            FD = creat("ExampleFile.txt", O_RDONLY);
            printf("File Descriptor for File Creation : %d\n", FD);
            close(FD);
            break;

        case 'O':
            FD = open("ExampleFile.txt", O_RDONLY | O_CREAT | O_WRONLY);
            printf("File Descriptor for File Opening : %d\n", FD);
            close(FD);
            break;

        case 'S':
            close(FD);
            printf("File Descriptor for File Closing : %d\n", FD);
            break;

        case 'W':
            FD = open("ExampleFile.txt", O_WRONLY | O_CREAT);
            secFD = write(FD, "Shantanu Mane created this file!!!\n", strlen("Shantanu Mane created this file!!!\n"));

            printf("File Descriptor of File Opening : %d\n", FD);
            printf("File Descriptor for File Writing : %d\n", secFD);
            close(FD);
            close(secFD);
            break;

        case 'R':
            FD = open("ExampleFile.txt", O_RDONLY);
            secFD = read(FD, buff, 128);

            printf("File Descriptor of File Opening : %d\n", FD);
            printf("File Descriptor for File Reading : %d\n", secFD);
            buff[secFD] = '\0';

            printf("String read from the file : %s", buff);
            close(FD);

        case 'U':
            close(FD);
            secFD = unlink("ExampleFile.txt");
            printf("File Descriptor for File Unlinking : %d\n", secFD);
            break;

        case 'L':
            FD = open("ExampleFile.txt", O_RDONLY);
            secFD = lseek(FD, -1, SEEK_END);

            char ptr;
            printf("File Descriptor for File Seeking : %d\n", secFD);

            for (int i = secFD; i > 0; i--)
            {
                lseek(FD, -1, 1);
                read(FD, &ptr, 1);
                printf("%c", ptr);
                lseek(FD, -1, 1);
            }
            read(FD, buff, 19);

        default:
            exit(0);
            break;
        }
    }

    return 0;
}