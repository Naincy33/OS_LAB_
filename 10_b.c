#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, head, size, seek = 0;

    printf("Enter disk size: ");
    scanf("%d", &size);

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n];

    printf("Enter requests:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &req[i]);

    printf("Enter head position: ");
    scanf("%d", &head);

    seek += abs(size - 1 - head);

    printf("Approximate Seek Time = %d", seek);

    return 0;
}