#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

#define N 5

pthread_mutex_t forkm[N];

void *philosopher(void *arg)
{
    int id = *(int *)arg;

    while(1)
    {
        printf("P%d Thinking\n", id);

        if(id%2==0)
        {
            pthread_mutex_lock(&forkm[id]);
            pthread_mutex_lock(&forkm[(id+1)%N]);
        }
        else
        {
            pthread_mutex_lock(&forkm[(id+1)%N]);
            pthread_mutex_lock(&forkm[id]);
        }

        printf("P%d Eating\n", id);

        sleep(1);

        pthread_mutex_unlock(&forkm[id]);
        pthread_mutex_unlock(&forkm[(id+1)%N]);
    }
}

int main()
{
    pthread_t p[N];
    int id[N];

    for(int i=0;i<N;i++)
    {
        pthread_mutex_init(&forkm[i], NULL);
        id[i]=i;
        pthread_create(&p[i], NULL, philosopher, &id[i]);
    }

    for(int i=0;i<N;i++)
        pthread_join(p[i], NULL);

    return 0;
}