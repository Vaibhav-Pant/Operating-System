#include <stdio.h>
#include <stdlib.h>
#include "cpu_scheduling.h"

void fcfs_input()
{
    printf("Enter the number of processes: ");
    scanf("%d", &process);

    burst_time = (int *)malloc(process * sizeof(int));
    completion_time = (int *)malloc(process * sizeof(int));
    arrive_time = (int *)malloc(process * sizeof(int));
    waiting_time = (int *)malloc(process * sizeof(int));
    turn_around_time = (int *)malloc(process * sizeof(int));

    printf("\nEnter the Burst time.\n\n");
    printf("--------------------------\n");
    printf("| PROCESS | | BURST TIME |\n");
    printf("--------------------------\n");


    for (int i = 0; i < process; i++)
    {
        printf("| P%d      | |     ", i + 1);
        scanf("%d", &burst_time[i]);
        printf("\033[A\033[20C     |\n", 033);
    }
    printf("--------------------------\n");

}

void fcfs_compute()
{

    // Ariive time  = 0 for fcfs.
    for (int i = 0; i < process; i++)
    {
        arrive_time[i] = 0;
    }

    printf("\n");
    // Completion time
    completion_time[0] = burst_time[0];
    for (int i = 1; i < process; i++)
    {
        completion_time[i] = burst_time[i] + completion_time[i - 1];
    }

    // turnAround
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

void fcfs_display()
{
    // Gantt chart
    printf("             Gantt chart \n\n");

    for (int i = 0; i < process; i++)
    {
        printf("|    P%d    ", i + 1);
    }
    printf("|\n0");

    for (int i = 0; i < process; i++)
    {
        printf("         %02d", turn_around_time[i]);
    }
    printf("\n\n");

    // Display Final outputs in table form
    printf("                            Table. Waiting time and Turn around time\n");
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("| PROCESS | | BURST TIME | | ARRIVAL TIME | | COMPLETION TIME | | WAITING TIME | | TURN AROUND TIME |\n");
    printf("-----------------------------------------------------------------------------------------------------\n");

    for (int i = 0; i < process; i++)
    {
        printf("| P%d      | |    %02d      | |     %02d       | |        %02d       | |       %02d     | |        %02d        |\n", i + 1, burst_time[i], arrive_time[i], completion_time[i], waiting_time[i], turn_around_time[i]);
    }
    printf("-----------------------------------------------------------------------------------------------------\n");
    printf("                                                          Avg:| |     %.1f      | |       %.1f        |\n\n\n", average(waiting_time, process), average(turn_around_time, process));
}
