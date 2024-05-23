#include<stdio.h>
#include<stdlib.h>
#include "cpu_scheduling.h"

int *arr;
int count_array;
int initial_gantt_index;

void swappp(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void priority_np_input()
{
    
    printf("Enter the number of processes: ");
    scanf("%d", &process);

    burst_time = (int *)malloc(process * sizeof(int));
    completion_time = (int *)malloc(process * sizeof(int));
    arrive_time = (int *)malloc(process * sizeof(int));
    waiting_time = (int *)malloc(process * sizeof(int));
    turn_around_time = (int *)malloc(process * sizeof(int));
    priority_value = (int *)malloc(process * sizeof(int));

    printf("\nEnter the Burst time and priority.\n\n");
    printf("---------------------------------------\n");
    printf("| PROCESS | | BURST TIME | | PRIORITY |\n");
    printf("---------------------------------------\n");

    for (int i = 0; i < process; i++)
    {
        printf("| P%d      | |     ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("\033[A\033[20C     |\n", 033);

        printf("\033[A\033[20C     | |    ", 033);
        scanf("%d", &priority_value[i]);
        printf("\033[A\033[33C     |\n", 033);
    }
    printf("---------------------------------------\n");

}

void getIndexValue(int *array)
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
            if (array[j] < array[min])
            {
                min = j;
            }
        }
        swappp(&array[i], &array[min]);
        swappp(&arr1[i], &arr1[min]);
    }

    for (int i = 0; i < process; i++)
    {
        array[i] = arr1[i];
    }
    printf("\n");
}

void priority_np_compute()
{
    arr = (int *)malloc(process * sizeof(int));
    for (int i = 0; i < process; i++)
    {
        arr[i] = priority_value[i];
    }
    getIndexValue(arr);

    // Completion time
    completion_time[arr[0]] = burst_time[arr[0]];
    for (int i = 1; i < process; i++)
    {
        completion_time[arr[i]] = burst_time[arr[i]] + completion_time[arr[i-1]];
    }

    // Arive time  = 0 for non preemptive
    for (int i = 0; i < process; i++)
    {
        arrive_time[i] = 0;
    }

    // turn around time
    for (int i = 0; i < process; i++)
    {
        turn_around_time[i] = completion_time[i] - arrive_time[i];
    }

    // waiting time
    for (int i = 0; i < process; i++)
    {
        waiting_time[i] = turn_around_time[i] - burst_time[i];
    }
}

void priority_np_display()
{
  // Gantt chart
    printf("\n             Gantt chart \n");
    printf("             -----------\n\n");

    for (int i = 0; i < process; i++)
    {
        printf("|    P%d    ", arr[i] + 1);
    }
    printf("|\n0");

    for (int i = 0; i < process; i++)
    {
        printf("         %02d", turn_around_time[arr[i]]);
    }
    printf("\n\n");

    // Display Final outputs in table form
    printf("                            Table. Waiting time and Turn around time\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("| PROCESS | | BURST TIME | | ARRIVAL TIME | | COMPLETION TIME | | WAITING TIME | | TURN AROUND TIME |\n");
    printf("-----------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < process; i++)
    {
        printf("| P%d      | |    %02d      | |     %02d       | |        %02d       | |       %02d     | |        %02d        |\n", i + 1, burst_time[i], arrive_time[i], completion_time[     i], waiting_time[i], turn_around_time[i]);
    }
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("                                                          Avg:| |      %.1f     | |       %.1f       |\n\n\n", average(waiting_time, process), average(turn_around_time, process));
}

void priority_p_input(){
    printf("Enter the number of processes: ");
    scanf("%d", &process);

    burst_time = (int *)malloc(process * sizeof(int));
    completion_time = (int *)malloc(process * sizeof(int));
    arrive_time = (int *)malloc(process * sizeof(int));
    waiting_time = (int *)malloc(process * sizeof(int));
    turn_around_time = (int *)malloc(process * sizeof(int));
    priority_value = (int *)malloc(process * sizeof(int));

    printf("\nEnter the Burst time, Arrival time and priority.\n\n");
    printf("--------------------------------------------------------\n");
    printf("| PROCESS | | BURST TIME | | ARRIVAL TIME | | PRIORITY |\n");
    printf("--------------------------------------------------------\n");

    for (int i = 0; i < process; i++)
    {
        printf("| P%d      | |     ", i + 1);
        scanf("%d", &burst_time[i]);
        // printf("\033[A\033[20C     |\n", 033);

        printf("\033[A\033[20C     | |      ", 033);
        scanf("%d", &arrive_time[i]);
        printf("\033[A\033[36C      | |     ", 033);
        scanf("%d", &priority_value[i]);
        printf("\033[A\033[52C   |\n", 033);


    }
    printf("--------------------------------------------------------\n");
}

void priority_p_compute()
{
    int *remaining_priority = (int *)malloc(process * sizeof(int));
    int *remaining_burst = (int *)malloc(process * sizeof(int));

    int current_time = INT_MAX;
    int check_index_change = 0;

    for (int i = 0; i < process; i++)
    {

        if(arrive_time[i] < current_time)
        {
            current_time = arrive_time[i];
            check_index_change = i;
        }
        else if(arrive_time[i] == current_time)
        {
            if(priority_value[i] <= priority_value[check_index_change])
            {
                current_time = arrive_time[i];
                check_index_change = i;
            }
        }
        remaining_burst[i] = burst_time[i];
        remaining_priority[i] = priority_value[i];
    }
    
    initial_gantt_index = current_time;
    int completed = 0;
    int shortest_job_index;
    count_array = 0;

    while (completed != process)
    {
        // printf("inside while\n");
        shortest_job_index = -1;
        int shortest_burst = __INT_MAX__;

        // Find the shortest remaining time job
        for (int i = 0; i < process; i++)
        {
            if (arrive_time[i] <= current_time &&remaining_priority[i] <= shortest_burst &&remaining_priority[i] >= 0 && remaining_burst[i] > 0)
            {
                shortest_burst = remaining_priority[i];
                shortest_job_index = i;
            }
        }

        if (shortest_job_index == -1)
        {
            current_time++;
            continue;
        }


        if ((check_index_change != shortest_job_index))
        {
            gantt_index[count_array] = check_index_change + 1;
            gantt_value[count_array] = current_time;
            count_array++;
        }

        // Execute the shortest job for 1 unit of time
        remaining_burst[shortest_job_index]--;
        current_time++;

        //assign prev value 
        check_index_change = shortest_job_index;

        // If the job is completed
        if (remaining_burst[shortest_job_index]== 0)
        {
            completion_time[shortest_job_index] = current_time;
            turn_around_time[shortest_job_index] = completion_time[shortest_job_index] - arrive_time[shortest_job_index];
            waiting_time[shortest_job_index] = turn_around_time[shortest_job_index] - burst_time[shortest_job_index];

            gantt_index[count_array] = check_index_change + 1;
            gantt_value[count_array] = current_time;
            completed++;
        }
    }

}

void priority_p_display()
{
        // Gantt chart
    printf("\n                      Gantt chart \n");
    printf("                       -----------\n\n");

    for (int i = 0; i <= count_array; i++)
    {
        printf("|    P%d    ", gantt_index[i]);
    }
    printf("|\n%02d",initial_gantt_index);

    for (int i = 0; i <= count_array; i++)
    {
        printf("         %02d", gantt_value[i]);
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
    printf("                                                          Avg:| |      %.1f     | |       %.1f       |\n\n\n", average(waiting_time, process), average(turn_around_time, process));
}

