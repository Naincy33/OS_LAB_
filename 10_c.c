#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, head, i, seek = 0;

    printf("Enter number of requests: ");
    scanf("%d", &n);

    int req[n], visited[n];

    printf("Enter requests:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &req[i]);
        visited[i] = 0;
    }

    printf("Enter head position: ");
    scanf("%d", &head);

    int count = 0;

    while(count < n)
    {
        int min = 9999, index = -1;

        for(i = 0; i < n; i++)
        {
            if(!visited[i] && abs(req[i] - head) < min)
            {
                min = abs(req[i] - head);
                index = i;
            }
        }

        seek += min;
        head = req[index];
        visited[index] = 1;
        count++;
    }

    printf("Total Seek Time = %d", seek);

    return 0;
}