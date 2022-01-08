#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int Table[5][6];

void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}

void sortByArrival(int num, int Table[][6])
{
    for (int i = 0; i < num; i++)
    {
        for (int j = 0; j < num - i - 1; j++)
        {
            if (Table[j][1] > Table[j + 1][1])
            {
                for (int k = 0; k < 5; k++)
                {
                    swap(Table[j][k], Table[j + 1][k]);
                }
            }
        }
    }
}

void computeCompletion(int num, int Table[][6])
{
    int temp, val;
    Table[0][3] = Table[0][1] + Table[0][2];
    Table[0][5] = Table[0][3] - Table[0][1];
    Table[0][4] = Table[0][5] - Table[0][2];

    for (int i = 1; i < num; i++)
    {
        temp = Table[i - 1][3];
        int low = Table[i][2];
        for (int j = i; j < num; j++)
        {
            if (temp >= Table[j][1] && low >= Table[j][2])
            {
                low = Table[j][2];
                val = j;
            }
        }
        Table[val][3] = temp + Table[val][2];
        Table[val][5] = Table[val][3] - Table[val][1];
        Table[val][4] = Table[val][5] - Table[val][2];
        for (int k = 0; k < 6; k++)
        {
            swap(Table[val][k], Table[i][k]);
        }
    }
}

int main()
{
    int num, temp;

    printf("Enter number of processes : ");
    scanf("%d", &num);

    printf("Enter process ID : ");
    for (int i = 0; i < num; i++)
    {
        printf("Process number %d : ", i + 1);
        printf("Enter ID : ");
        scanf("%d", &Table[i][0]);

        printf("\nEnter Arrival Time : ");
        scanf("%d", &Table[i][1]);

        printf("\nEnter Burst Time : ");
        scanf("%d", &Table[i][2]);
    }

    printf("Initial Table : \n\n");
    printf("Process ID\tArrival Time\tBurst Time\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d\t\t%d\t\t%d\n", Table[i][0], Table[i][1], Table[i][2]);
    }

    sortByArrival(num, Table);
    computeCompletion(num, Table);

    printf("Final Table : \n\n");
    printf("Process ID\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");
    for (int i = 0; i < num; i++)
    {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\n", Table[i][0], Table[i][1], Table[i][2], Table[i][4], Table[i][5]);
    }
}
