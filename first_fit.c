#include <stdio.h>

int main()
{
    int nb,np;

    printf("Enter number of memory blocks: ");
    scanf("%d",&nb);

    int block[20];

    for(int i=0;i<nb;i++)
    {
        printf("Block %d size: ",i+1);
        scanf("%d",&block[i]);
    }

    printf("Enter number of processes: ");
    scanf("%d",&np);

    int process[20];

    for(int i=0;i<np;i++)
    {
        printf("Process %d size: ",i+1);
        scanf("%d",&process[i]);
    }

    printf("\nProcess\tSize\tBlock\n");

    for(int i=0;i<np;i++)
    {
        int allocated=0;

        for(int j=0;j<nb;j++)
        {
            if(block[j] >= process[i])
            {
                printf("%d\t%d\t%d\n",
                       i+1,
                       process[i],
                       j+1);

                block[j] -= process[i];
                allocated=1;
                break;
            }
        }

        if(allocated==0)
        {
            printf("%d\t%d\tNot Allocated\n",
                   i+1,
                   process[i]);
        }
    }

    return 0;
}