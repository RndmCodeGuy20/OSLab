/**
 * @file FdupesAssg.c
 * @authors Akshita Deshmukh, Ninad Kadu, Prajwal Deshmukh, Shantanu Mane 
 * @brief A C program to simulate the UNIX system utility call Fdupes, which deletes duplicate files in a   certain directory.
 * @version  1.0.4
 * @date 2021-12-20
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <sys/stat.h>
#include <stdlib.h>
#include <limits.h>
#include <sys/file.h>
#include <fcntl.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>

struct directory
{
    char fileName[100];
    long int fileSize;
    int fileMode;
    int gid;
};

void samefile(struct stat stats)
{
    struct stat f;
    if (stats.st_mode & R_OK)
    {
        printf("Read Mode 📖\n");
    }
    if (stats.st_mode & W_OK)
    {
        printf("Write Mode 📝\n");
    }
    if (stats.st_mode & X_OK)
    {
        printf("Execute Mode 👾\n");
    }
}

int main()
{
    struct directory dir[50];
    struct stat file;
    int i = 0, j = 0, ctr = 0;
    char *s;
    char buf[100];

    s = getcwd(buf, sizeof(buf));
    printf("\nCurrent Working Directory : %s \n", s);

    struct dirent *dRnt;

    DIR *dr = opendir(".");

    if (dr == NULL)
    {
        printf("Directory could NOT be opened!!!");
        return 0;
    }

    while ((dRnt = readdir(dr)) != NULL)
    {
        stat(dRnt->d_name, &file);
        printf("\n\nFile Name 📛 : %s\nFile Size 🔢 : %ld\nEffective GID 🆔 : %d\n", dRnt->d_name, file.st_size, file.st_gid);

        dir[i].fileMode = file.st_mode;
        dir[i].fileSize = file.st_size;

        strcpy(dir[i].fileName, dRnt->d_name);

        dir[i].gid = file.st_gid;

        printf("st_mode of the file : %d\n", file.st_mode);

        samefile(file);
        printf("\n");

        i++;
        ctr++;
    }

    closedir(dr);
    for (i = 0; i < ctr; i++)
    {
        for (j = i + 1; j < ctr; j++)
        {
            if ((dir[i].fileSize == dir[j].fileSize) && (dir[i].gid == dir[j].gid && (dir[i].fileMode == dir[j].fileMode)))
            {
                if (unlink(dir[j].fileName) == 0)
                {
                    printf("Duplicate file '%s' is SUCCESSFULLY DELETED!!! ☠️ \n", dir[j].fileName);
                }
            }
        }
    }
    return 0;
}
