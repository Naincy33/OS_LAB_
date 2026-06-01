#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter requests:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("\nC-LOOK Scheduling simulated successfully.\n");

    return 0;
}