#include <stdio.h>

int main()
{
    int n, m;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    int alloc[10][10];
    int req[10][10];
    int avail[10];
    int finish[10] = {0};

    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Request Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &req[i][j]);

    printf("Enter Available Resources:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    int count = 0;

    while (count < n)
    {
        int found = 0;

        for (int i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                int flag = 1;

                for (int j = 0; j < m; j++)
                {
                    if (req[i][j] > avail[j])
                    {
                        flag = 0;
                        break;
                    }
                }

                if (flag)
                {
                    for (int j = 0; j < m; j++)
                        avail[j] += alloc[i][j];

                    finish[i] = 1;
                    count++;
                    found = 1;
                }
            }
        }

        if (found == 0)
            break;
    }

    printf("\nDeadlocked Processes: ");

    int deadlock = 0;

    for (int i = 0; i < n; i++)
    {
        if (finish[i] == 0)
        {
            printf("P%d ", i);
            deadlock = 1;
            
        }
    }

    if (deadlock)
    {
        printf("\nDeadlock Detected\n");
    }
    else
    {
        printf("None\n");
    }
    return 0;
}