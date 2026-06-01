#include <stdio.h>

int main()
{
    int n, i;
    char path[100];

    printf("Enter number of files: ");
    scanf("%d", &n);

    printf("Enter file paths:\n");

    for(i = 0; i < n; i++)
    {
        scanf("%s", path);
        printf("Stored: %s\n", path);
    }

    return 0;
}