#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>
#include <stdlib.h>

int reqSeq[50];
int SIZE;

int dist(int a, int b)
{
    if (a > b)
        return a - b;
    return b - a;
}

void fcfs(int n)
{
    int head, i;
    int seekCnt = 0;

    printf("Enter the current head :\n");
    scanf("%d", &head);

    for (i = 0; i < n; i++)
    {
        if (reqSeq[i] < SIZE - 1)
        {
            seekCnt = seekCnt + dist(head, reqSeq[i]);
            head = reqSeq[i];
        }
    }

    printf("Total Distance : %d", seekCnt);
}

int main()
{
    int n, i;
    printf("Enter the Disk Size :\n");
    scanf("%d", &SIZE);

    printf("Enter the number of request in the list :\n");
    scanf("%d", &n);

    printf("Enter request sequence :\n");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &reqSeq[i]);
    }

    fcfs(n);
}