#include <stdio.h>

#define MAX 10

struct Task
{
    int id;
    int bt;
    int period;
    int deadline;
    int share;
    int at;

    int ct;
    int wt;
    int tat;
};

// RMS
void RMS(struct Task t[], int n)
{
    struct Task temp;
    int time = 0;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(t[j].period > t[j+1].period)
            {
                temp = t[j];
                t[j] = t[j+1];
                t[j+1] = temp;
            }
        }
    }

    printf("\n===== RMS =====\n");
    printf("PID\tBT\tPeriod\tCT\tWT\tTAT\n");

    for(int i=0;i<n;i++)
    {
        
        time += t[i].bt;
        t[i].ct = time;
        t[i].tat = t[i].ct - t[i].at;
        t[i].wt = t[i].tat - t[i].bt;

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               t[i].id,
               t[i].bt,
               t[i].period,
               t[i].ct,
               t[i].wt,
               t[i].tat);
    }
}

// EDF
void EDF(struct Task t[], int n)
{
    struct Task temp;
    int time = 0;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(t[j].deadline > t[j+1].deadline)
            {
                temp = t[j];
                t[j] = t[j+1];
                t[j+1] = temp;
            }
        }
    }

    printf("\n===== EDF =====\n");
    printf("PID\tBT\tDeadline\tCT\tWT\tTAT\n");

    for(int i=0;i<n;i++)
    {
       
        time += t[i].bt;
        t[i].ct = time;
        t[i].tat = t[i].ct-t[i].at;
        t[i].wt = t[i].tat-t[i].bt;

        printf("P%d\t%d\t%d\t\t%d\t%d\t%d\n",
               t[i].id,
               t[i].bt,
               t[i].deadline,
               t[i].ct,
               t[i].wt,
               t[i].tat);
    }
}

// Proportional Scheduling
void PSS(struct Task t[], int n)
{
    struct Task temp;
    int time = 0;

    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(t[j].share > t[j+1].share)
            {
                temp = t[j];
                t[j] = t[j+1];
                t[j+1] = temp;
            }
        }
    }

    printf("\n===== PSS =====\n");
    printf("PID\tBT\tShare\tCT\tWT\tTAT\n");

    for(int i=0;i<n;i++)
    {
        
        time += t[i].bt;
        t[i].ct = time;
        t[i].tat = t[i].ct - t[i].at;
        t[i].wt = t[i].tat - t[i].bt;

        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               t[i].id,
               t[i].bt,
               t[i].share,
               t[i].ct,
               t[i].wt,
               t[i].tat);
    }
}

int main()
{
    int n;

    struct Task original[MAX];
    struct Task rms[MAX];
    struct Task edf[MAX];
    struct Task pss[MAX];

    printf("Enter number of tasks: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        original[i].id = i;

        printf("\nTask P%d\n",i);

        printf("enter arrival time: ");
        scanf("%d",&original[i].at);

        printf("Enter Burst Time: ");
        scanf("%d",&original[i].bt);

        printf("Enter Period: ");
        scanf("%d",&original[i].period);

        printf("Enter Deadline: ");
        scanf("%d",&original[i].deadline);

        printf("Enter Share: ");
        scanf("%d",&original[i].share);
    }

    // Copy arrays
    for(int i=0;i<n;i++)
    {
        rms[i] = original[i];
        edf[i] = original[i];
        pss[i] = original[i];
    }

    RMS(rms,n);
    EDF(edf,n);
    PSS(pss,n);

    return 0;
}