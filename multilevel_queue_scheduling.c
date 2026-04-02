#include <stdio.h>
#define MAX 100

struct Process
{
    int id;
    int at;   // Arrival Time
    int bt;   // Burst Time
    int ct;   // Completion Time
    int wt;   // Waiting Time
    int tat;  // Turnaround Time
    int queue; // 0 = System, 1 = User
    int done;
};

// Function to sort processes by arrival time
void sortByArrival(struct Process p[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (p[j].at > p[j + 1].at)
            {
                struct Process temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}

// Function to run FCFS scheduling
void runFCFS(struct Process p[], int n, int *currentTime)
{
    for (int i = 0; i < n; i++)
    {
        // If CPU is idle, jump to arrival time
        if (*currentTime < p[i].at)
            *currentTime = p[i].at;

        p[i].wt = *currentTime - p[i].at;
        p[i].ct = *currentTime + p[i].bt;
        p[i].tat = p[i].ct - p[i].at;

        *currentTime = p[i].ct;
        p[i].done = 1;
    }
}

int main()
{
    int n;
    struct Process all[MAX], systemQueue[MAX], userQueue[MAX];
    int sysCount = 0, userCount = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    // Input all processes
    for (int i = 0; i < n; i++)
    {
        all[i].id = i;

        printf("\nProcess %d\n", i);

        printf("Enter arrival time: ");
        scanf("%d", &all[i].at);

        printf("Enter burst time: ");
        scanf("%d", &all[i].bt);

        printf("Enter type (0 = System, 1 = User): ");
        scanf("%d", &all[i].queue);

        all[i].done = 0;

        // Divide into queues
        if (all[i].queue == 0)
            systemQueue[sysCount++] = all[i];
        else
            userQueue[userCount++] = all[i];
    }

    // Sort both queues by arrival time
    sortByArrival(systemQueue, sysCount);
    sortByArrival(userQueue, userCount);

    int currentTime = 0;

    // Execute System queue first (higher priority)
    runFCFS(systemQueue, sysCount, &currentTime);

    // Then execute User queue
    runFCFS(userQueue, userCount, &currentTime);

    // Merge results back
    for (int i = 0; i < sysCount; i++)
        all[systemQueue[i].id] = systemQueue[i];

    for (int i = 0; i < userCount; i++)
        all[userQueue[i].id] = userQueue[i];

    // Display results
    printf("\nID\tType\tAT\tBT\tCT\tWT\tTAT\n");

    float totalWT = 0, totalTAT = 0;

    for (int i = 0; i < n; i++)
    {
        printf("%d\t%s\t%d\t%d\t%d\t%d\t%d\n",
               all[i].id,
               all[i].queue == 0 ? "System" : "User",
               all[i].at,
               all[i].bt,
               all[i].ct,
               all[i].wt,
               all[i].tat);

        totalWT += all[i].wt;
        totalTAT += all[i].tat;
    }

    printf("\nAverage Waiting Time = %.2f", totalWT / n);
    printf("\nAverage Turnaround Time = %.2f\n", totalTAT / n);

    return 0;
}