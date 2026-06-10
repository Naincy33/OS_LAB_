#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

#define BUFFER_SIZE 5

int buffer[BUFFER_SIZE];   // shared buffer
int in = 0, out = 0;       // indices for producer and consumer

sem_t empty;               // semaphore counting empty slots
sem_t full;                // semaphore counting filled slots
pthread_mutex_t mutex;     // mutex for critical section

// Producer thread function
void* producer(void* arg)
{ 
    int item, i = 0;
    while (1)
    {
        item = i++; // produce an item (simple counter)

        sem_wait(&empty);              // wait if buffer is full
        pthread_mutex_lock(&mutex);    // lock critical section

        buffer[in] = item;             // put item in buffer
        printf("Produced: %d at buffer[%d]\n", item, in);
        in = (in + 1) % BUFFER_SIZE;   // circular increment

        pthread_mutex_unlock(&mutex);  // unlock critical section
        sem_post(&full);               // signal that buffer has a new item

        sleep(1); // simulate production time
    }
}

// Consumer thread function
void* consumer(void* arg)
{
    int item;
    while (1)
    {
        sem_wait(&full);               // wait if buffer is empty
        pthread_mutex_lock(&mutex);    // lock critical section

        item = buffer[out];            // take item from buffer
        printf("Consumed: %d from buffer[%d]\n", item, out);
        out = (out + 1) % BUFFER_SIZE; // circular increment

        pthread_mutex_unlock(&mutex);  // unlock critical section
        sem_post(&empty);              // signal that a slot is free

        sleep(2); // simulate consumption time
    }
}

int main()
{
    pthread_t prod, cons;

    // Initialize semaphores and mutex
    sem_init(&empty, 0, BUFFER_SIZE);  // all slots empty initially
    sem_init(&full, 0, 0);             // no slots filled initially
    pthread_mutex_init(&mutex, NULL);

    // Create producer and consumer threads
    pthread_create(&prod, NULL, producer, NULL);
    pthread_create(&cons, NULL, consumer, NULL);

    // Wait for threads (they run infinitely here)
    pthread_join(prod, NULL);
    pthread_join(cons, NULL);

    // Cleanup (not reached in this infinite loop program)
    sem_destroy(&empty);
    sem_destroy(&full);
    pthread_mutex_destroy(&mutex);

    return 0;
}
