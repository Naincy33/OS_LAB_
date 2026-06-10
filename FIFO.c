#include <stdio.h>

int main()
{
    int pages[20], frames[10];
    int n, f, faults = 0;

    printf("Enter number of pages: ");
    scanf("%d", &n);

    printf("Enter page reference string: ");
    for(int i=0;i<n;i++)
        scanf("%d",&pages[i]);

    printf("Enter number of frames: ");
    scanf("%d",&f);

    for(int i=0;i<f;i++)
        frames[i] = -1;

    int index = 0;

    for(int i=0;i<n;i++)
    {
        int found = 0;

        for(int j=0;j<f;j++)
        {
            if(frames[j] == pages[i])
            {
                found = 1;
                break;
            }
        }

        if(!found)
        {
            frames[index] = pages[i];
            index = (index + 1) % f;
            faults++;
        }
    }

    printf("Page Faults = %d\n", faults);

    return 0;
}