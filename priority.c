#include <stdio.h>

struct process
{
    int at, bt, pr;
    int wt, tat, ct;
    int done;
};

#define max 10

void priorityScheduling(struct process p[], int n)
{
    int completed = 0, t = 0;
    float total_wt = 0, total_tat = 0;

    while (completed < n)
    {
        int idx = -1;
        int highest_priority = 9999;

        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= t && p[i].done == 0)
            {
                if (p[i].pr < highest_priority)
                {
                    highest_priority = p[i].pr;
                    idx = i;
                }
                else if (p[i].pr == highest_priority)
                {
                    if (p[i].at < p[idx].at)
                    {
                        idx = i;
                    }
                }
            }
        }

        if (idx != -1)
        {
            p[idx].ct = t + p[idx].bt;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;

            total_wt += p[idx].wt;
            total_tat += p[idx].tat;

            p[idx].done = 1;
            completed++;

            t = p[idx].ct;
        }
        else
        {
            t++; // CPU idle
        }
    }

    printf("\nID\tAT\tBT\tPR\tCT\tWT\tTAT\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i, p[i].at, p[i].bt, p[i].pr,
               p[i].ct, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time: %.2f", total_wt / n);
    printf("\nAverage Turnaround Time: %.2f\n", total_tat / n);
}

int main()
{
    int n;
    struct process p[max];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("\nProcess %d\n", i);

        printf("Enter Arrival Time: ");
        scanf("%d", &p[i].at);

        printf("Enter Burst Time: ");
        scanf("%d", &p[i].bt);

        printf("Enter Priority (lower = higher): ");
        scanf("%d", &p[i].pr);

        p[i].done = 0;
    }

    priorityScheduling(p, n);

    return 0;
}

