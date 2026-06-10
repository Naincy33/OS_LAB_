#include <stdio.h>

int main()
{
    int pages[20], frames[10], time[10];
    int n, f, faults = 0, counter = 0;

    printf("Enter number of pages: ");
    scanf("%d",&n);

    printf("Enter pages: ");
    for(int i=0;i<n;i++)
        scanf("%d",&pages[i]);

    printf("Enter number of frames: ");
    scanf("%d",&f);

    for(int i=0;i<f;i++)
    {
        frames[i] = -1;
        time[i] = 0;
    }

    for(int i=0;i<n;i++)
    {
        int found = 0;

        for(int j=0;j<f;j++)
        {
            if(frames[j] == pages[i])
            {
                counter++;
                time[j] = counter;
                found = 1;
            }
        }

        if(!found)
        {
            int pos = 0;

            for(int j=1;j<f;j++)
            {
                if(time[j] < time[pos])
                    pos = j;
            }

            frames[pos] = pages[i];

            counter++;
            time[pos] = counter;

            faults++;
        }
    }

    printf("Page Faults = %d\n", faults);

    return 0;
}