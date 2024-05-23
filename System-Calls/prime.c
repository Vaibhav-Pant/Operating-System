#include <stdio.h>
#include <stdlib.h>
void prime(int x, int y)
{
    int i;
    if (x % 2 == 0)
    {
        i = x + 1;
    }
    else
    {
        i = x;
    }

    while (i < y)
    {
        if ((i % 3 != 0) && (i % 5 != 0) && (i % 7 != 0))
        {
            printf("%d ", i);
        }
        i += 2;
    }
    printf("\n\n");
}

int main(int argc, char *argv[])
{

    int n = atoi(argv[1]);
    int m = atoi(argv[2]);

    printf("Printing prime number between %d and %d: \n", n, m);

    if ((n < 8) && (m > 8))
    {
        for (int i = n; i <= m; i++)
        {
            if ((i == 2) || (i == 3) || (i == 5) || (i == 7))
            {
                printf("%d ", i);
            }
        }
        prime(9, m);
    }
    else
    {
        prime(n, m);
    }

    return 0;
}
