#include <stdio.h>

int main()
{
    int nb,np;

    printf("Enter number of blocks: ");
    scanf("%d",&nb);

    int block[20];

    for(int i=0;i<nb;i++)
        scanf("%d",&block[i]);

    printf("Enter number of processes: ");
    scanf("%d",&np);

    int process[20];

    for(int i=0;i<np;i++)
        scanf("%d",&process[i]);

    printf("\nProcess\tSize\tBlock\n");

    for(int i=0;i<np;i++)
    {
        int worst=-1;

        for(int j=0;j<nb;j++)
        {
            if(block[j] >= process[i])
            {
                if(worst==-1 ||
                   block[j] > block[worst])
                {
                    worst=j;
                }
            }
        }

        if(worst!=-1)
        {
            printf("%d\t%d\t%d\n",
                   i+1,
                   process[i],
                   worst+1);

            block[worst]-=process[i];
        }
        else
        {
            printf("%d\t%d\tNot Allocated\n",
                   i+1,
                   process[i]);
        }
    }

    return 0;
}