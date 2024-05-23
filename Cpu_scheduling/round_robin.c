#include <stdio.h>
#include <stdlib.h>
#include "cpu_scheduling.h"

int count_array;
int *ready_queue;
int *remaining_time;
int rear = -1;
int front = -1;

void swapp(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int isEmpty()
{
    if (rear < front)
    {
        return 1;
    }
    return 0;
}
void enqueue(int x)
{
    if (rear == process - 1)
    {
        ready_queue = (int *)realloc(ready_queue, sizeof(int) * (rear + 1));
    }
    if (front == -1)
    {
        front = 0;
    }
    rear = rear + 1;
    ready_queue[rear] = x;
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        return -1;
    }
    else
    {
        return ready_queue[front++];
    }
}

void Gindex(int *array)
{
    int arr1[process];
    for (int i = 0; i < process; i++)
    {
        arr1[i] = i;
    }

    for (int i = 0; i < process; i++)
    {
        int min = i;

        for (int j = i + 1; j < process; j++)
        {
            if (remaining_time[j] < remaining_time[min])
            {
                min = j;
            }
        }
        swapp(&remaining_time[i], &remaining_time[min]);
        swapp(&arr1[i], &arr1[min]);
    }

    for (int i = 0; i < process; i++)
    {
        array[i] = arr1[i];
    }

    printf("\n");
}

void r_r_input()
{
    printf("Enter the number of processes: ");
    scanf("%d", &process);

    printf("Enter the value of Time Quantum: ");
    scanf("%d", &time_quantum);

    burst_time = (int *)malloc(process * sizeof(int));
    completion_time = (int *)malloc(process * sizeof(int));
    arrive_time = (int *)malloc(process * sizeof(int));
    waiting_time = (int *)malloc(process * sizeof(int));
    turn_around_time = (int *)malloc(process * sizeof(int));

    printf("\nEnter the Burst time and arrival time.\n\n");
    printf("------------------------------------------\n");
    printf("| PROCESS | | BURST TIME | | ARRIVE TIME |\n");
    printf("------------------------------------------\n");

    for (int i = 0; i < process; i++)
    {
        printf("| P%d      | |     ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("\033[A\033[20C     |\n", 033);

        printf("\033[A\033[20C     | |      ", 033);
        scanf("%d", &arrive_time[i]);
        printf("\033[A\033[36C     |\n", 033);
    }
    printf("------------------------------------------\n\n");
}

void r_r_compute()
{
    int *arr = (int *)malloc(process * sizeof(int));
    remaining_time = (int *)malloc(process * sizeof(int));
    int *remaining_burst = (int *)malloc(process * sizeof(int));
    ready_queue = (int *)malloc(process * sizeof(int));

    for (int i = 0; i < process; i++)
    {
        remaining_time[i] = arrive_time[i];
        remaining_burst[i] = burst_time[i];
    }
    Gindex(arr);
    int current_time = remaining_time[0];
    count_array = 0;

    for (int idx = 0; idx < process;)
    {
        if (remaining_burst[idx] != 0)
        {
            enqueue(arr[idx++]);
            while (!isEmpty())
            {
                int id = dequeue();
                if (remaining_burst[id] <= time_quantum)
                {
                    current_time += remaining_burst[id];
                    remaining_burst[id] = 0;
                    gantt_index[count_array] = id + 1;
                    gantt_value[count_array] = current_time;
                    count_array++;
                    completion_time[id] = current_time;
                }
                else
                {
                    remaining_burst[id] -= time_quantum;
                    current_time += time_quantum;
                    gantt_index[count_array] = id + 1;
                    gantt_value[count_array] = current_time;
                    count_array++;
                }

                while (idx < process && current_time >= remaining_time[idx])
                {
                    enqueue(arr[idx++]);
                }
                if (remaining_burst[id] != 0)
                {
                    enqueue(id);
                }
            }
        }
    }

    for (int i = 0; i < process; i++)
    {
        turn_around_time[i] = completion_time[i] - arrive_time[i];
    }

    for (int i = 0; i < process; i++)
    {
        waiting_time[i] = turn_around_time[i] - burst_time[i];
    }

}

void r_r_display()
{
    // Gantt chart
    printf("\n                      Gantt chart \n");
    printf("                       -----------\n\n");

    for (int i = 0; i < count_array; i++)
    {
        printf("|  P%d  ", gantt_index[i]);
    }
    printf("|\n%d", remaining_time[0]);

    for (int i = 0; i < count_array; i++)
    {
        printf("     %02d", gantt_value[i]);
    }
    printf("\n\n");

    // // Display Final outputs in table form
    printf("                            Table. Waiting time and Turn around time\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("| PROCESS | | BURST TIME | | ARRIVAL TIME | | COMPLETION TIME | | WAITING TIME | | TURN AROUND TIME |\n");
    printf("-----------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < process; i++)
    {
        printf("| P%d      | |    %02d      | |     %02d       | |        %02d       | |       %02d     | |        %02d        |\n", i + 1, burst_time[i], arrive_time[i], completion_time[i], waiting_time[i], turn_around_time[i]);
    }
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("                                                          Avg:| |      %.1f     | |       %.1f        |\n\n\n", average(waiting_time, process), average(turn_around_time, process));
}

