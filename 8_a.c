#include <stdio.h>

int main()
{
    int start, length, i;

    printf("Enter starting block: ");
    scanf("%d", &start);

    printf("Enter file length (number of blocks): ");
    scanf("%d", &length);

    printf("\nAllocated Blocks:\n");

    for(i = 0; i < length; i++)
    {
        printf("%d ", start + i);
    }

    return 0;
}