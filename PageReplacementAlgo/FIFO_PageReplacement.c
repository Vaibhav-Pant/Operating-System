#include<stdio.h>
#include<unistd.h>
#include <stdbool.h>

bool check(int *arr, int value, int frame)
{
    for(int i = 0;  i  < frame; i++)
        if(arr[i] == value)
            return true;

    return false;
}

void fifo(int *arr, int frames, int size)
{
    int hit = 0;
    int fault = 0;
    int store[frames];
    int ptr = 0;

    printf("\n------------");
    for(int i = 0; i < frames; i++)
    {
        printf("-----------");
    }
    printf("\n");

    printf("|  String  |  ");
    for(int i = 0; i < frames; i++)
    {
        printf("|  F-%d  |  ",i+1); 
        store[i] = -1;
    }

    printf("\n------------");
    for(int i = 0; i < frames; i++)
    {
        printf("-----------");
    }
    printf("\n");


    for(int i = 0; i < size; i++)
    {
        printf("|     %d    |  ", arr[i]);
        if(!check(store, arr[i], frames ))
        {
            if(ptr >= frames)
            {
                ptr = 0;
            }
            store[ptr++] = arr[i];
            fault++;
            for(int j = 0; j < frames; j++)
            {
                printf("|  %2d   |  ",store[j]);
            }
        }
        else{
            for(int j = 0; j < frames; j++)
                printf("|       |  ");

            hit++;
        }
        printf("\n");
    }

    printf("\nPage Fault: %d\n", fault);
    printf("Page Hit: %d\n", hit);
    printf("Fault Ratio: %.2f\n", (double)fault/size);
    printf("Hit Ratio: %.2f\n", (double)hit/size);

}

// 1 2 3 4 1 2 5 1 2 3 4 5 2 = 13
// 7 0 1 2 0 3 0 4 2 3 0 3 0 3 2 1 2 0 1 7 0 1  = 22

int main()
{
    int frames;
    int size;
    printf("Enter size of string: ");
    scanf("%d", &size);

    printf("Enter the string with spaces.\n");
    int arr[size];
    for(int i = 0; i < size; i++)
    {
        scanf("%d",&arr[i]);
    }

    printf("\nEnter the number of frames: ");
    scanf("%d", &frames);

    fifo(arr, frames, size);
}
