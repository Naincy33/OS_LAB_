#include <stdio.h>

int main()
{
    int n,m;

    printf("Enter number of processes: ");
    scanf("%d",&n);

    printf("Enter number of resources: ");
    scanf("%d",&m);

    int alloc[10][10];
    int max[10][10];
    int need[10][10];
    int avail[10];
    int finish[10]={0};
    int safe[10];

    printf("Enter Allocation Matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&alloc[i][j]);
        }
    }

    printf("Enter Max Matrix:\n");
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            scanf("%d",&max[i][j]);
        }
    }

    printf("Enter Available Resources:\n");
    for(int i=0;i<m;i++)
    {
        scanf("%d",&avail[i]);
    }

    // Need Matrix
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }

    int count=0;

    while(count<n)
    {
        int found=0;

        for(int i=0;i<n;i++)
        {
            if(finish[i]==0)
            {
                int flag=1;

                for(int j=0;j<m;j++)
                {
                    if(need[i][j] > avail[j])
                    {
                        flag=0;
                        break;
                    }
                }

                if(flag)
                {
                    for(int j=0;j<m;j++)
                    {
                        avail[j]+=alloc[i][j];
                    }

                    safe[count]=i;
                    count++;
                    finish[i]=1;
                    found=1;
                }
            }
        }

        if(found==0)
            break;
    }

    if(count==n)
    {
        printf("\nSystem is in SAFE State\n");

        printf("Safe Sequence: ");

        for(int i=0;i<n;i++)
        {
            printf("P%d ",safe[i]);
        }
    }
    else
    {
        printf("\nSystem is NOT in Safe State");
    }

    return 0;
}