#include <stdio.h>

#define max 10

struct process
{
    int at;  // Arrival Time
    int bt;  // Burst Time
    int rt;  // Remaining Time
    int wt;  // Waiting Time
    int tat; // Turnaround Time
    int ct;  // Completion Time
};

void roundRobin(struct process p[], int n, int tq)
{
    int t = 0; // current time
    int completed = 0;
    float total_wt = 0, total_tat = 0;

    while (completed < n)
    {
        int executed = 0;

        for (int i = 0; i < n; i++)
        {
            if (p[i].at <= t && p[i].rt > 0)
            {
                executed = 1;

                if (p[i].rt > tq)
                {
                    t += tq;
                    p[i].rt -= tq;
                }
                else
                {
                    t += p[i].rt;
                    p[i].rt = 0;

                    p[i].ct = t;
                    p[i].tat = p[i].ct - p[i].at;
                    p[i].wt = p[i].tat - p[i].bt;

                    total_wt += p[i].wt;
                    total_tat += p[i].tat;

                    completed++;
                }
            }
        }

        if (executed == 0)
        {
            t++; // CPU idle
        }
    }

    printf("\nID\tAT\tBT\tCT\tWT\tTAT\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n", i, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat);
    }

    printf("\nAverage Waiting Time: %.2f\n", total_wt / n);
    printf("Average Turnaround Time: %.2f\n", total_tat / n);
}

int main()
{
    int n, tq;
    struct process p[max];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time for process %d: ", i);
        scanf("%d", &p[i].at);

        printf("Enter burst time for process %d: ", i);
        scanf("%d", &p[i].bt);

        p[i].rt = p[i].bt; // Remaining time initially = burst time
    }

    printf("Enter Time Quantum: ");
    scanf("%d", &tq);

    roundRobin(p, n, tq);

    return 0;
}