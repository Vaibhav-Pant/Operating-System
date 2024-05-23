#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define n 5         // For 5 processes. Change as per your need !!

struct data
{
    int memory_size;
    int process_size;
    int allocation;
    int fragments;
};
struct data detail[n];

int Random()
{
    int ub = 1000;
    int lb = 100;

    return (rand() % (ub - lb + 1)) + lb;
}
void InitialFill()
{
    srand ( time(NULL) );
    for (int i = 0; i < n; i++)
    {
        detail[i].memory_size = Random();
        detail[i].allocation = 0;
        detail[i].process_size = 0;
    }
}

int ProgramMenu()
{
    printf("1. First Fit\n");
    printf("2. Best Fit\n");
    printf("3. Worst Fit\n");
    printf("4. Exit\n");
    int choose;
    printf("Choose from (1/2/3/4): ");
    scanf("%d", &choose);
    return choose;
}

int InsideMenu()
{
    printf("1. Allocate Memory\n");
    printf("2. Deallocate Memory\n");
    printf("3. Display Memory\n");
    printf("4. Exit\n");
    int choose;
    printf("Choose from (1/2/3/4): ");
    scanf("%d", &choose);
    return choose;
}

void Display()
{
    printf(" --------------------------------------------------------------------------------------------------\n");
    printf("|    Index    | |      Size     | |     P_size      | |     Fragments      | |    Allocation      |\n");
    printf(" --------------------------------------------------------------------------------------------------\n");
    for (int i = 0; i < n; i++)
    {
        printf("|      %d      | |      %3d      | |     %3d         | |       %3d          | |          %1d         |\n", i, detail[i].memory_size, detail[i].process_size, detail[i].fragments, detail[i].allocation);
    }
    printf(" --------------------------------------------------------------------------------------------------\n");
}

void Deallocate()
{
    int index;
    printf("Enter the index value: ");
    scanf("%d", &index);

    detail[index].process_size = 0;
    detail[index].fragments = 0;
    detail[index].allocation = 0;

    Display();
}

void FitFill()
{
    int value, flag = 0;
    printf("Enter the process size: ");
    scanf("%d", &value);

    for (int i = 0; i < n; i++)
    {
        if (detail[i].memory_size > value && detail[i].allocation == 0)
        {
            detail[i].allocation = 1;
            detail[i].fragments = detail[i].memory_size - value;
            detail[i].process_size = value;
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        printf("\nProcess not allocated in Memory.\n");
    }
    else
    {
        Display();
    }
}

void BestFill()
{
    int value;
    printf("Enter the process size: ");
    scanf("%d", &value);


    int bestIndex = -1;
    for(int j = 0; j < n; j++)
    {
        if(detail[j].memory_size >= value && detail[j].allocation == 0)
        {
            if(bestIndex == -1)
            {
                bestIndex = j;  
            }
            else if (detail[j].memory_size < detail[bestIndex].memory_size)
            {
                bestIndex = j;
            }
        }
    }

    if(bestIndex != -1)
    {
        detail[bestIndex].process_size = value;
        detail[bestIndex].allocation = 1;
        detail[bestIndex].fragments = detail[bestIndex].memory_size - value;
        Display();
    }
    else{
        printf("\nProcess not allocated in Memory.\n");
    }

}

void WorstFill()
{
 int value;
    printf("Enter the process size: ");
    scanf("%d", &value);


    int bestIndex = -1;
    for(int j = 0; j < n; j++)
    {
        if(detail[j].memory_size >= value && detail[j].allocation == 0)
        {
            if(bestIndex == -1)
            {
                bestIndex = j;  
            }
            else if (detail[j].memory_size > detail[bestIndex].memory_size)
            {
                bestIndex = j;
            }
        }
    }

    if(bestIndex != -1)
    {
        detail[bestIndex].process_size = value;
        detail[bestIndex].allocation = 1;
        detail[bestIndex].fragments = detail[bestIndex].memory_size - value;
        Display();
    }
    else{
        printf("\nProcess not allocated in Memory.\n");
    }
}

int main()
{
    InitialFill();
    Display();
    int ask = ProgramMenu();

    while (1)
    {
        if(ask == 4)
        {
            break;
        }
        int s_ask = InsideMenu();
        if (s_ask == 1)
        {
            if(ask == 1)
            {
                FitFill();
            }
            else if(ask == 2)
            {
                BestFill();
            }
            else if(ask == 3)
            {
                WorstFill();
            }
        }
        else if (s_ask == 2)
        {
            Deallocate();
        }
        else if (s_ask == 3)
        {
            Display();
        }
        else{
            break;
        }
    }

    return 0;
}