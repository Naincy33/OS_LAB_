#include <stdio.h>

int main()
{
    int n, indexBlock, i;

    printf("Enter index block: ");
    scanf("%d", &indexBlock);

    printf("Enter number of blocks: ");
    scanf("%d", &n);

    int blocks[n];

    printf("Enter block numbers:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &blocks[i]);

    printf("\nIndex Block = %d\n", indexBlock);

    printf("Allocated Blocks:\n");
    for(i = 0; i < n; i++)
        printf("%d ", blocks[i]);

    return 0;
}