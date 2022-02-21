#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Proc
{
    int id;
    int reqSize;
    int allotedBlock;
} a;
typedef struct Block
{
    int isTaken;
    void *size;
} b;
struct Proc arr[1000];
struct Block blocks[1000];
int totalBlockSpace = 0;
void printBlocks(int n)
{
    printf("\n\nBlocks: { ");
    for (int i = 0; i < n; ++i)
    {
        printf("B%d: %d ", i + 1, _msize(blocks[i].size));
    }
    printf("}\n");
}
void printProcs(int n)
{
    printf("\nID\tProcess size\tAllotment\t");
    for (int i = 0; i < n; ++i)
    {
        printf("\nP%d\t %d\t\t", arr[i].id + 1, arr[i].reqSize);
        if (arr[i].allotedBlock != -1)
        {
            printf("B%d", arr[i].allotedBlock + 1);
        }
        else
        {
            printf("Not alloted");
        }
    }
    printf("\n");
}
void firstFit(int bNum, int pNum)
{
    for (int i = 0; i < pNum; ++i)
    {
        for (int j = 0; j < bNum; ++j)
        {
            int s = _msize(blocks[j].size);
            if (arr[i].reqSize <= s && blocks[j].isTaken == 0)
            {
                totalBlockSpace -= arr[i].reqSize;
                arr[i].allotedBlock = j;
                blocks[j].isTaken = 1;
                break;
            }
        }
    }
}
void bestFit(int bNum, int pNum)
{
    for (int i = 0; i < pNum; ++i)
    {
        int currSize = -1, currIndex = -1;
        for (int j = 0; j < bNum; ++j)
        {
            int s = _msize(blocks[j].size);
            if (arr[i].reqSize <= s && blocks[j].isTaken == 0)
            {
                if (currSize > s || currSize == -1)
                {
                    currSize = s;
                    currIndex = j;
                }
            }
        }
        arr[i].allotedBlock = currIndex;
        if (currIndex != -1)
        {
            totalBlockSpace -= arr[i].reqSize;
            blocks[currIndex].isTaken = 1;
        }
    }
}
void worstFit(int bNum, int pNum)
{
    for (int i = 0; i < pNum; ++i)
    {
        int currSize = -1, currIndex = -1;
        for (int j = 0; j < bNum; ++j)
        {
            int s = _msize(blocks[j].size);
            if (arr[i].reqSize <= s && blocks[j].isTaken == 0)
            {
                if (s > currSize || currSize == -1)
                {
                    currSize = s;
                    currIndex = j;
                }
            }
        }
        arr[i].allotedBlock = currIndex;
        if (currIndex != -1)
        {
            totalBlockSpace -= arr[i].reqSize;
            blocks[currIndex].isTaken = 1;
        }
    }
}
int main(void)
{
    printf("\n\n:::::Memory allotment for Processes:::::\n\n"); // detail about resources
    int bNum = 0;
    printf("\nEnter number of memory blocks: ");
    scanf("%d", &bNum);
    printf("\nEnter memory block sizes:\n");
    for (int i = 0; i < bNum; ++i)
    {
        printf("For block %d: ", i + 1);
        int tempSize;
        scanf("%d", &tempSize);
        totalBlockSpace += tempSize;
        blocks[i].isTaken = 0;
        blocks[i].size = malloc(tempSize);
    }
    printBlocks(bNum); // detail about processes
    int pNum = 0;
    printf("\nEnter number of processes: ");
    scanf("%d", &pNum);
    printf("\n\nEnter processes required size:\n");
    for (int i = 0; i < pNum; ++i)
    {
        arr[i].id = i;
        arr[i].allotedBlock = -1;
        printf("For P%d: ", i + 1);
        scanf("%d", &arr[i].reqSize);
    }
        int inp = 0;


    while (inp < 4)
    {
        printf("\n\nChoose process allocation algo:");
        printf("\n1.First Fit");
        printf("\n2.Best Fit");
        printf("\n3.Worst Fit");
        printf("\nInput: ");
        scanf("%d", &inp);

        switch (inp)
        {
        case 1:
            firstFit(bNum, pNum);
            printf("\n\nFirst Fit:");
            break;
        case 2:
            bestFit(bNum, pNum);
            printf("\n\nBest Fit:");
            break;
        case 3:
            worstFit(bNum, pNum);
            printf("\n\nWorst Fit:");
            break;
        default:
            printf("\n\nERROR: Invalid input!!!");
            break;
        }
        printBlocks(bNum);
        printProcs(pNum);
        printf("\nTotal empty space: %d", totalBlockSpace);
        printf("\n\n");
    }

    return 0;
}