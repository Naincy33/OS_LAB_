#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

int buffer = 0;

sem_t empty, full;
pthread_mutex_t mutex;

void *producer(void *arg)
{
    while(1)
    {
        sem_wait(&empty);

        pthread_mutex_lock(&mutex);

        buffer++;
        printf("Produced: %d\n", buffer);

        pthread_mutex_unlock(&mutex);

        sem_post(&full);

        sleep(1);
    }
}

void *consumer(void *arg)
{
    while(1)
    {
        sem_wait(&full);

        pthread_mutex_lock(&mutex);

        printf("Consumed: %d\n", buffer);
        buffer--;

        pthread_mutex_unlock(&mutex);

        sem_post(&empty);

        sleep(2);
    }
}

int main()
{
    pthread_t p, c;

    sem_init(&empty, 0, 1);
    sem_init(&full, 0, 0);

    pthread_mutex_init(&mutex, NULL);

    pthread_create(&p, NULL, producer, NULL);
    pthread_create(&c, NULL, consumer, NULL);

    pthread_join(p, NULL);
    pthread_join(c, NULL);

    return 0;
}