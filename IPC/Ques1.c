#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void fact(int num)
{
    int x = 1;
    for (int i = 2; i <= num; i++)
    {
        x *= i;
    }

    printf("Factorial of %d: %d\n", num, x);
}

int main()
{
    int pds[2];
    int status = pipe(pds);
    char writedata[10];
    char readdata[10];

    int pid = fork();
    if (pid == -1)
    {
        printf("Error in fork");
        return 0;
    }
    else if (pid == 0)
    {
        int askUser;
        printf("Enter the value of n: ");
        scanf("%d", &askUser);
        sprintf(writedata, "%d", askUser);
        printf("Writing data...\n");
        write(pds[1], writedata, sizeof(writedata));
        printf("Data entered in pipe: %s\n", writedata);
    }
    else
    {
        wait(NULL);
        printf("Reading data: \n");
        read(pds[0], readdata, sizeof(readdata));
        printf("Data read from pipe: %s\n", readdata);
        printf("Calling Fact\n");

        fact(atoi(readdata));
    }
}