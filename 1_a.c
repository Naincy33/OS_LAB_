#include <stdio.h>

#define max 10

struct process
{
    int at;  // Arrival Time
    int bt;  // Burst Time
    int wt;  // Waiting Time
    int tat; // Turnaround Time
    int ct;  // Completion Time
};

// Sort processes by arrival time
void sortProcesses(struct process p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                struct process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

// FCFS Scheduling
void FCFS(struct process p[], int n)
{
    int t = 0; // Current time

    sortProcesses(p, n); // IMPORTANT

    for (int i = 0; i < n; i++)
    {
        if (t < p[i].at)
        {
            t = p[i].at;
        }

        p[i].wt = t - p[i].at;
        p[i].ct = t + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;

        t = p[i].ct;
    }

    // printf("\n%-5s%-5s%-5s%-5s%-5s%-5s\n", "PID", "AT", "BT", "CT", "WT", "TAT");
    printf("PID\tAT\tBT\tCT\tWT\tTAT\n");
    for (int i = 0; i < n; i++)
    {
        /* printf("%-5d%-5d%-5d%-5d%-5d%-5d\n",
                i, p[i].at, p[i].bt, p[i].ct, p[i].wt, p[i].tat);*/
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               i, p[i].at, p[i].bt,
               p[i].ct, p[i].wt, p[i].tat);
    }

    float awt = 0.0, atat = 0.0;

    for (int i = 0; i < n; i++)
    {
        awt += p[i].wt;
        atat += p[i].tat;
    }

    awt /= n;
    atat /= n;

    printf("\nAverage Waiting Time = %.2f", awt);
    printf("\nAverage Turnaround Time = %.2f\n", atat);
}

int main()
{
    int n;
    struct process p[max];

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        printf("Enter arrival time for process %d: ", i);
        scanf("%d", &p[i].at);

        printf("Enter burst time for process %d: ", i);
        scanf("%d", &p[i].bt);
    }

    FCFS(p, n);

    return 0;
}