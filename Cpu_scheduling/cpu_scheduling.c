/*

TAKING INPUT FROM USER IN TABULAR FORM MIGHT NOT WORK ON EVERY SYSTEM
IT IS WORKING IN MY VSCODE MIGHT NOW WORK OTHER TERMINAL. 
KEEP THIS IN MIDE, REST EVERYTHING WILL WORK FINE.

*/

#include <stdio.h>
#include <stdlib.h>
#include "fcfs.c"
#include "sjf.c"
#include "priority.c"
#include "round_robin.c"
// #include <windows.h>

#define MAX 50 // Max size of gantt chart (Change according to your need OR use dynamic arrray)

int process;
int time_quantum;
int *burst_time;
int *completion_time;
int *arrive_time;
int *waiting_time;
int *turn_around_time;
int *priority_value;
int gantt_index[MAX];
int gantt_value[MAX];
int *arr;

float average(int arr[], int n);
void menu();

int main()
{
    int a = 1;
    int choice;
    while (a)
    {
        // Sleep(1000);
        menu();
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            fcfs_input();
            fcfs_compute();
            fcfs_display();
            break;

        case 2:
            int x;
            printf("\n1. Non Preemptive\n");
            printf("2. Preemptive\n");
            printf("Choose (1/2): ");
            scanf("%d", &x);
            if (x == 1)
            {

                sjf_np_input();
                sjf_np_compute();
                sjf_np_display();
            }
            else if (x == 2)
            {

                sjf_p_input();
                sjf_p_compute();
                sjf_p_display();
                int gantt_index[MAX] = {0};
                int gantt_value[MAX] = {0};
                for (int i = 0; i < MAX; i++)
                {
                    gantt_index[i] = 0;
                    gantt_value[i] = 0;
                }
            }
            break;

        case 3:
            printf("\n1. Non Preemptive\n");
            printf("2. Preemptive\n");
            printf("Choose (1/2): ");
            scanf("%d", &x);
            if (x == 1)
            {
                priority_np_input();
                priority_np_compute();
                priority_np_display();
                int gantt_index[MAX] = {0};
                int gantt_value[MAX] = {0};
                for (int i = 0; i < MAX; i++)
                {
                    gantt_index[i] = 0;
                    gantt_value[i] = 0;
                }
            }
            else if (x == 2)
            {

                priority_p_input();
                priority_p_compute();
                priority_p_display();
                int gantt_index[MAX] = {0};
                int gantt_value[MAX] = {0};
                for (int i = 0; i < MAX; i++)
                {
                    gantt_index[i] = 0;
                    gantt_value[i] = 0;
                }
            }
            break;

        case 4:

            r_r_input();
            r_r_compute();
            r_r_display();
            int gantt_index[MAX] = {0};
            int gantt_value[MAX] = {0};
            for (int i = 0; i < MAX; i++)
            {
                gantt_index[i] = 0;
                gantt_value[i] = 0;
            }
            break;

        case 5:
            a = 0;
            break;

        default:
            break;
        }
    }

    return 0;
}

void menu()
{
    printf("--------------------MENU--------------------\n");
    printf("1. First come first serve ( FCFS )\n");
    printf("2. Shortest Job first ( SJF )\n");
    printf("3. Priority Scheduling Algorithm\n");
    printf("4. Round Robin Algorithm\n");
    printf("5. Exit\n");
    printf("Choose (1/2/3/4/5): ");
}

float average(int array[], int n)
{
    int avg = 0;
    for (int i = 0; i < n; i++)
    {
        avg += array[i];
    }
    return (float)avg / (float)n;
}
