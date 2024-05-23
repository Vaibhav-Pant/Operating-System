#include<stdio.h>
#include<unistd.h>
#include <stdbool.h>

// Check for page fault or hit
bool check(int *arr, int value, int frame)
{
    for(int i = 0;  i  < frame; i++)
        if(arr[i] == value)
            return true;

    return false;
}

// Return index position which has to be replaced with the new value
int findIndex(int *arr, int* store, int size, int frames, int currIndex)
{
    int index = 0;
    int count = -999;
    for(int j = 0; j < frames; j++)
    {
        int cnt = 0;
        for(int i = currIndex+1; i < size; i++)
        {
            if(arr[i] != store[j]){ 
                cnt++;
            }else{
                break;
            }
        }
        if(cnt >= count)
        {
            count = cnt;
            index = j;
        }
    }
    return index;
}

void Optimal(int *arr, int frames, int size)
{
    int hit = 0;
    int fault = 0;
    int store[frames];

    // To print the output in tabular form ( Remove if tabular not needed)
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
            if(store[i] == -1)
            {
                store[i] = arr[i];
                fault++;
            }
            else{
                int ind = findIndex(arr, store, size, frames, i);
                store[ind] = arr[i];
                fault++;
            }
            for(int j = 0; j < frames; j++)
                printf("|  %2d   |  ",store[j]);
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

    Optimal(arr, frames, size);
}