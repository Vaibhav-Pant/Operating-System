#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>

#define SIZE 3  //Size of common buffer
#define RUN 9   // Run for <RUN> time max, change as per need.

sem_t empty, full, mutex;
int buffer[SIZE];
int in = 0, out = 0;
int prod_cnt = 0;
void *producer() 
{
    int item;
    for (int i = 0; i < RUN; i++) {
        prod_cnt++;
        sem_wait(&empty); 
        sem_wait(&mutex);
        buffer[in] = prod_cnt; 
        printf("Producer produced item: %d\n", prod_cnt);
        in = (in + 1) % SIZE;
        sem_post(&mutex);
        sem_post(&full);
    }
    pthread_exit(NULL);
}

void *consumer()
{
    int item;
    for (int i = 0; i < RUN; i++) {
        sem_wait(&full);
        sem_wait(&mutex);
        item = buffer[out]; 
        printf("Consumer consumed item: %d\n", item);
        out = (out + 1) % SIZE;
        sem_post(&mutex);
        sem_post(&empty);
    }
    pthread_exit(NULL);
}

int main() {
    pthread_t producer_thread, consumer_thread;

    sem_init(&empty, 0, SIZE);
    sem_init(&full, 0, 0); 
    sem_init(&mutex, 0, 1);
    
    pthread_create(&producer_thread, NULL, producer, NULL);
    pthread_create(&consumer_thread, NULL, consumer, NULL);

    pthread_join(producer_thread, NULL);
    pthread_join(consumer_thread, NULL);
    
    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
    
    return 0;
}