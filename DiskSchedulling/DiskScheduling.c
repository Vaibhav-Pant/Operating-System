#include <stdio.h>
#include <stdlib.h>

void display()
{
    printf("--------------------------------------------\n");
    printf("| S.No |              MENU                 |\n");
    printf("--------------------------------------------\n");
    printf("|   1  |              FCFS                 |\n");
    printf("|   2  |              SSTF                 |\n");
    printf("|   3  |              SCAN                 |\n");
    printf("|   4  |              C-SCAN               |\n");
    printf("|   5  |              LOOK                 |\n");
    printf("|   6  |              C-LOOK               |\n");
    printf("|   7  |              Exit                 |\n");
    printf("--------------------------------------------\n");
    printf("Choose (1/2/3/4/5/6/7): ");
}

void fcfs()
{
    int head, n, seekTime = 0;
    printf("Enter the number of request sequence: ");
    scanf("%d", &n);
    int arr[n], sequence[n + 1];
    printf("Enter the request sequence: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the initial head position: ");
    scanf("%d", &head);
    printf("\n");

    // Assign head value at sequecne[0]
    sequence[0] = head;

    printf(" ------------------------------------------------- \n");
    printf("|    Value    |  |    Head    |  |    SeekTime   |\n");
    printf(" ------------------------------------------------- \n");
    for (int i = 0; i < n; i++)
    {
        printf("|     %3d     |  ", arr[i]);
        printf("|    %3d     |  ", head);
        int seek = abs(head - arr[i]);
        seekTime += seek;
        printf("|      %3d      |\n", seek);
        head = arr[i];
        sequence[i + 1] = head;
    }
    printf(" ------------------------------------------------- \n");
    printf("                    Seek Time => |      %d      |\n", seekTime);
    printf("                                 -----------------   \n");
    // printf("Total seek Time: %d\n", seekTime);
    printf("\nSequence of operation:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d --> ", sequence[i]);
    }
    printf("%d\n\n\n", sequence[n]);
}

int getMinSSTF(int *arr, int *used, int n, int head)
{
    int index = -1;
    int diff = 999;
    for (int i = 0; i < n; i++)
    {
        if (diff > abs(head - arr[i]) && used[i] != 1)
        {
            diff = abs(head - arr[i]);
            index = i;
        }
    }
    return index;
}

void sstf()
{
    int head, n, seekTime = 0;
    printf("Enter the number of request sequence: ");
    scanf("%d", &n);
    int arr[n], sequence[n + 1], used[n];
    printf("Enter the request sequence: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        used[i] = 0;
    }
    printf("\nEnter the initial head position: ");
    scanf("%d", &head);
    printf("\n");

    // Assign head value at sequecne[0]
    sequence[0] = head;

    printf(" ------------------------------------------------- \n");
    printf("|    Value    |  |    Head    |  |    SeekTime   |\n");
    printf(" ------------------------------------------------- \n");
    for (int i = 0; i < n; i++)
    {
        int index = getMinSSTF(arr, used, n, head);
        printf("|     %3d     |  ", arr[index]);
        printf("|    %3d     |  ", head);
        int seek = abs(head - arr[index]);
        seekTime += seek;
        printf("|      %3d      |\n", seek);
        head = arr[index];
        sequence[i + 1] = head;
        used[index] = 1;
    }
    printf(" ------------------------------------------------- \n");
    printf("                    Seek Time => |      %d      |\n", seekTime);
    printf("                                 -----------------   \n");
    // printf("Total seek Time: %d\n", seekTime);
    printf("\nSequence of operation:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d --> ", sequence[i]);
    }
    printf("%d\n\n\n", sequence[n]);
}

int getNextIndexSCAN(int *arr, int *used, int n, int head, int direction)
{
    int index = -1;
    int diff = 999;

    // Case for c-scan dirrection change
    if (arr[n - 1] == head && direction == 0)
    {
        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                return i;
            }
        }
    }

    // This only workd for C-LOOK
    if (direction == 2)
    {
        int ind = -1;
        int minVal = 999;
        for (int i = 0; i < n; i++)
        {
            if (minVal >= arr[i])
            {
                minVal = arr[i];
                ind = i;
            }
        }
        return ind;
    }

    for (int i = 0; i < n; i++)
    {
        if (direction == 0)
        {
            if (arr[i] <= head && used[i] != 1)
            {
                if (diff > abs(head - arr[i]))
                {
                    diff = abs(head - arr[i]);
                    index = i;
                }
            }
        }
        else
        {
            if (arr[i] > head && used[i] != 1)
            {
                if (diff > abs(head - arr[i]))
                {
                    diff = abs(head - arr[i]);
                    index = i;
                }
            }
        }
    }
    return index;
}

void scan()
{
    int head, n, seekTime = 0, disk_size, direction;
    printf("Enter the Disk - Size: ");
    scanf("%d", &disk_size);
    printf("Enter the number of Request Sequence: ");
    scanf("%d", &n);
    int arr[n + 1], sequence[n + 2], used[n + 1];
    printf("Enter the Request Sequence: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        used[i] = 0;
    }
    printf("\nEnter the initial head position: ");
    scanf("%d", &head);
    printf("Enter the direction (L=0/R=1): ");
    scanf("%d", &direction);
    printf("\n");

    // Assign head value at sequecne[0]
    sequence[0] = head;
    if (direction == 0)
    {
        used[n] = 0;
        arr[n] = 0;
    }
    else
    {
        used[n] = 0;
        arr[n] = disk_size - 1;
    }

    printf(" ------------------------------------------------- \n");
    printf("|    Value    |  |    Head    |  |    SeekTime   |\n");
    printf(" ------------------------------------------------- \n");

    for (int i = 0; i < n + 1; i++)
    {
        int index = getNextIndexSCAN(arr, used, n + 1, head, direction);

        // Swap direction
        if (arr[index] == disk_size - 1 && direction == 1)
        {
            direction = 0;
        }
        else if (arr[index] == 0 && direction == 0)
        {
            direction = 1;
        }

        printf("|     %3d     |  ", arr[index]);
        printf("|    %3d     |  ", head);
        int seek = abs(head - arr[index]);
        seekTime += seek;
        printf("|      %3d      |\n", seek);
        head = arr[index];
        sequence[i + 1] = head;
        used[index] = 1;
    }
    // sequence[n+1] = head;
    printf(" ------------------------------------------------- \n");
    printf("                    Seek Time => |      %d      |\n", seekTime);
    printf("                                 -----------------   \n");
    // printf("Total seek Time: %d\n", seekTime);
    printf("\nSequence of operation:\n");
    for (int i = 0; i < n + 1; i++)
    {
        printf("%d --> ", sequence[i]);
    }
    printf("%d\n\n\n", sequence[n + 1]);
}

void c_scan()
{
    int head, n, seekTime = 0, disk_size, direction = 1;
    printf("Enter the Disk - Size: ");
    scanf("%d", &disk_size);
    printf("Enter the number of Request Sequence: ");
    scanf("%d", &n);
    int arr[n + 2], sequence[n + 3], used[n + 2];
    printf("Enter the Request Sequence: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        used[i] = 0;
    }

    printf("\nEnter the initial head position: ");
    scanf("%d", &head);
    printf("\n");

    // Assign head value at sequecne[0]
    sequence[0] = head;
    arr[n] = 0;
    used[n] = 0;
    arr[n + 1] = disk_size - 1;
    used[n + 1] = 0;

    printf(" ------------------------------------------------- \n");
    printf("|    Value    |  |    Head    |  |    SeekTime   |\n");
    printf(" ------------------------------------------------- \n");

    for (int i = 0; i < n + 2; i++)
    {
        int index = getNextIndexSCAN(arr, used, n + 2, head, direction);
        // Swap direction
        printf("|     %3d     |  ", arr[index]);
        printf("|    %3d     |  ", head);
        int seek = abs(head - arr[index]);
        seekTime += seek;
        printf("|      %3d      |\n", seek);
        head = arr[index];
        sequence[i + 1] = head;
        used[index] = 1;
        if (arr[index] == disk_size - 1 && direction == 1)
        {
            direction = 0;
        }
        else if (arr[index] == 0 && direction == 0)
        {
            direction = 1;
        }
    }
    // sequence[n+1] = head;
    printf(" ------------------------------------------------- \n");
    printf("                    Seek Time => |      %d      |\n", seekTime);
    printf("                                 -----------------   \n");
    // printf("Total seek Time: %d\n", seekTime);
    printf("\nSequence of operation:\n");
    for (int i = 0; i < n + 2; i++)
    {
        printf("%d --> ", sequence[i]);
    }
    printf("%d\n\n\n", sequence[n + 2]);
}

void look()
{
    int head, n, seekTime = 0, direction;
    // printf("Enter the Disk - Size: ");
    // scanf("%d",&disk_size);
    printf("Enter the number of Request Sequence: ");
    scanf("%d", &n);
    int arr[n], sequence[n + 1], used[n], minVal = 999, maxVal = -999;
    printf("Enter the Request Sequence: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        used[i] = 0;

        // Get min and max value
        if (maxVal <= arr[i])
        {
            maxVal = arr[i];
        }
        if (minVal >= arr[i])
        {
            minVal = arr[i];
        }
    }

    printf("\nEnter the initial head position: ");
    scanf("%d", &head);
    printf("Enter the direction (L=0/R=1): ");
    scanf("%d", &direction);
    printf("\n");

    // Assign head value at sequecne[0]
    sequence[0] = head;

    printf(" ------------------------------------------------- \n");
    printf("|    Value    |  |    Head    |  |    SeekTime   |\n");
    printf(" ------------------------------------------------- \n");

    for (int i = 0; i < n; i++)
    {
        int index = getNextIndexSCAN(arr, used, n, head, direction);
        printf("|     %3d     |  ", arr[index]);
        printf("|    %3d     |  ", head);
        int seek = abs(head - arr[index]);
        seekTime += seek;
        printf("|      %3d      |\n", seek);
        head = arr[index];
        sequence[i + 1] = head;
        used[index] = 1;

        // Swap direction
        if (arr[index] == maxVal && direction == 1)
        {
            direction = 0;
        }
        else if (arr[index] == minVal && direction == 0)
        {
            direction = 1;
        }
    }
    printf(" ------------------------------------------------- \n");
    printf("                    Seek Time => |      %d      |\n", seekTime);
    printf("                                 -----------------   \n");
    printf("\nSequence of operation:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d --> ", sequence[i]);
    }
    printf("%d\n\n\n", sequence[n]);
}

void c_look()
{
    int head, n, seekTime = 0, direction = 1;
    // printf("Enter the Disk - Size: ");
    // scanf("%d",&disk_size);
    printf("Enter the number of Request Sequence: ");
    scanf("%d", &n);
    int arr[n], sequence[n + 1], used[n], minVal = 999, maxVal = -999;
    printf("Enter the Request Sequence: ");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
        used[i] = 0;
        if (maxVal <= arr[i])
        {
            maxVal = arr[i];
        }
        if (minVal >= arr[i])
        {
            minVal = arr[i];
        }
    }

    printf("\nEnter the initial head position: ");
    scanf("%d", &head);
    printf("\n");

    // Assign head value at sequecne[0]
    sequence[0] = head;

    printf(" ------------------------------------------------\n");
    printf("|    Value    |  |    Head    |  |    SeekTime   |\n");
    printf(" ------------------------------------------------ \n");

    for (int i = 0; i < n; i++)
    {
        int index = getNextIndexSCAN(arr, used, n, head, direction);
        // Swap direction
        printf("|     %3d     |  ", arr[index]);
        printf("|    %3d     |  ", head);
        int seek = abs(head - arr[index]);
        seekTime += seek;
        printf("|      %3d      |\n", seek);
        head = arr[index];
        sequence[i + 1] = head;
        used[index] = 1;
        if (arr[index] == maxVal && direction == 1)
        {
            direction = 2;
        }
        else if (arr[index] == minVal && direction == 2)
        {
            direction = 1;
        }
    }

    printf(" ------------------------------------------------- \n");
    printf("                    Seek Time => |      %d      |\n", seekTime);
    printf("                                 -----------------   \n");
    printf("\nSequence of operation:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d --> ", sequence[i]);
    }
    printf("%d\n\n\n", sequence[n]);
}

int main()
{
    while (1)
    {
        int ask;
        display();
        scanf("%d", &ask);

        if (ask == 1)
        {
            fcfs();
            // 34 1 52 63 123 67 91 100
            // 176 79 34 60 92 11 41 114
        }
        else if (ask == 2)
        {
            sstf();
            // 176 79 34 60 92 11 41 114
            // 98 183 37 122 14 124 65 67
            // 84 19 92 64 10 24 27 53 12 4
        }
        else if (ask == 3)
        {
            scan();
            // 84 19 92 64 10 24 27 53 12 4
            // 98 183 37 122 14 124 65 67
        }
        else if (ask == 4)
        {
            c_scan();
            // 98 183 37 122 14 124 65 67
            // 98 183 37 14 124 65 67
        }
        else if (ask == 5)
        {
            look();
            // 98 183 37 122 14 124 65 67
        }
        else if (ask == 6)
        {
            c_look();
            // 98 183 37 122 14 124 65 67
            // 98 183 37 122 14 124 65 67
        }
        else
        {
            break;
        }
    }

    return 0;
}