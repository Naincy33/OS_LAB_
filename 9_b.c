#include <stdio.h>

int main()
{
    int users, files, i, j;

    printf("Enter number of users: ");
    scanf("%d", &users);

    for(i = 1; i <= users; i++)
    {
        printf("\nUser %d\n", i);

        printf("Enter number of files: ");
        scanf("%d", &files);

        char fname[20];

        for(j = 1; j <= files; j++)
        {
            printf("Enter file name: ");
            scanf("%s", fname);

            printf("User%d/%s\n", i, fname);
        }
    }

    return 0;
}