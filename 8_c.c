#include <stdio.h>

int main()
{
    int n, i;

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    int block[n];

    printf("Enter block numbers:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &block[i]);

    printf("\nLinked Allocation:\n");

    for(i = 0; i < n - 1; i++)
        printf("%d -> ", block[i]);

    printf("%d -> NULL", block[n - 1]);

    return 0;
}