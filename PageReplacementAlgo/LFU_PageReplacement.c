/*

THIS CODE IS NOT WORKING CORRECTLY
OUTPUT IS NOT CORRECT !!!

*/



#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>

// Check for page fault or hit
bool check(int *arr, int value, int frame)
{
    for (int i = 0; i < frame; i++)
        if (arr[i] == value)
            return true;

    return false;
}

int getIndex(int *arr, int *store, int *elem, int *freqOfelem, int ptr_elem, int frames, int *fifo_ptr)
{
    int index = 0;
    int count = 999;
    int freq_equal = 0;
    for (int i = 0; i < frames; i++)
    {
        for (int j = 0; j < ptr_elem; j++)
        {
            if (elem[j] == store[i])
            {
                int freq = freqOfelem[j];
                if (freq < count)
                {
                    count = freq;
                    index = i;

                    freq_equal++;
                }
                else if (count == freq)
                {
                    freq_equal++;
                }
                break;
            }
        }
    }

    if (index != *fifo_ptr && freq_equal > 1)
    {
        return *fifo_ptr;
    }

    return index;
}

void Optimal(int *arr, int frames, int size)
{
    int hit = 0;
    int fault = 0;
    int ptr_elem = 0;
    int fifo_ptr = 0;
    int store[frames];
    int elem[size];
    int freqOfelem[size];

    // To print the output in tabular form ( Remove if tabular not needed)
    printf("\n------------");
    for (int i = 0; i < frames; i++)
    {
        printf("-----------");
    }
    printf("\n");

    printf("|  String  |  ");
    for (int i = 0; i < frames; i++)
    {
        printf("|  F-%d  |  ", i + 1);
        store[i] = -1;
    }

    printf("\n------------");
    for (int i = 0; i < frames; i++)
    {
        printf("-----------");
    }
    printf("\n");

    for (int i = 0; i < size; i++)
    {
        printf("|     %d    |  ", arr[i]);

        if (!check(store, arr[i], frames)) // Fault condition
        {
            if (fifo_ptr >= frames)
                fifo_ptr = 0;

            if (store[i] == -1)
            {
                store[i] = arr[i];

                elem[ptr_elem] = arr[i];
                freqOfelem[ptr_elem] = 1;
                ptr_elem++;

                fault++;
                fifo_ptr++;
            }
            else
            {
                // New element is there, add to elem array and assign its frequency.
                int flag = 0;
                for (int j = 0; j < ptr_elem; j++)
                {
                    if (elem[j] == arr[i])
                    {
                        freqOfelem[j] += 1;
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    elem[ptr_elem] = arr[i];
                    freqOfelem[ptr_elem] = 1;
                }

                int ind = getIndex(arr, store, elem, freqOfelem, ptr_elem, frames, &fifo_ptr);
                if (ind >= frames)
                {
                    ind = ind % frames;
                }
                // Make frequency of the element ==> store[ind] to  0.
                for (int j = 0; j < ptr_elem; j++)
                {
                    if (elem[j] == store[ind])
                    {
                        freqOfelem[j] = 0;
                        break;
                    }
                }
                store[ind] = arr[i];

                fifo_ptr++;
                ptr_elem++;
                fault++;
            }

            for (int j = 0; j < frames; j++)
                printf("|  %2d   |  ", store[j]);
        }
        else // Hit condition
        {
            for (int j = 0; j < ptr_elem; j++)
            {
                if (elem[j] == arr[i])
                {
                    freqOfelem[j] += 1;
                    break;
                }
            }

            for (int j = 0; j < frames; j++)
                printf("|       |  ");

            hit++;
            fifo_ptr++;
        }
        printf("\n");
    }

    printf("\nPage Fault: %d\n", fault);
    printf("Page Hit: %d\n", hit);
    printf("Fault Ratio: %.2f\n", (double)fault / size);
    printf("Hit Ratio: %.2f\n", (double)hit / size);
}

// 7 0 2 4 3 1 4 7 2 0 4 3 0 3 2 7 = 16

int main()
{
    int frames;
    int size;
    printf("Enter size of string: ");
    scanf("%d", &size);

    printf("Enter the string with spaces.\n");
    int arr[size];
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the number of frames: ");
    scanf("%d", &frames);

    Optimal(arr, frames, size);
}
