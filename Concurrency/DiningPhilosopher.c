#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

#define N 5
#define THINKING 2
#define HUNGRY 1
#define EATING 0
#define LEFT (num + 4) % N
#define RIGHT (num + 1) % N

int state[N];
int phil[N] = {0, 1, 2, 3, 4};

sem_t mutex;
sem_t S[N];

void test(int num)
{
    if (state[num] == HUNGRY && state[LEFT] != EATING && state[RIGHT] != EATING)
    {
        state[num] = EATING;
        sleep(2);
        printf("Philosopher %d takes fork %d and %d\n", num + 1, LEFT + 1, num + 1);
        printf("Philosopher %d is Eating\n", num + 1);
        sem_post(&S[num]);
    }
}

void take_fork(int num)
{
    sem_wait(&mutex);
    state[num] = HUNGRY;
    printf("Philosopher %d is Hungry\n", num + 1);
    test(num);
    sem_post(&mutex);
    sem_wait(&S[num]);
    sleep(1);
}

void put_fork(int num)
{

    sem_wait(&mutex);
    state[num] = THINKING;
    printf("Philosopher %d putting fork %d and %d down\n", num + 1, LEFT + 1, num + 1);
    printf("Philosopher %d is thinking\n", num + 1);
    test(LEFT);
    test(RIGHT);
    sem_post(&mutex);
}

void *philosopher(void *num)
{
    while (1)
    {
        int *i = num;
        sleep(1);
        take_fork(*i);
        sleep(0);
        put_fork(*i);
    }
}

int main()
{
    int i;
    pthread_t thread_id[N];
    sem_init(&mutex, 0, 1);
    for (i = 0; i < N; i++)
    {
        sem_init(&S[i], 0, 0);
    }

    for (i = 0; i < N; i++)
    {
        pthread_create(&thread_id[i], NULL, philosopher, &phil[i]);
        printf("Philosopher %d is thinking\n", i + 1);
    }
    for (i = 0; i < N; i++)
    {
        pthread_join(thread_id[i], NULL);
    }
}
