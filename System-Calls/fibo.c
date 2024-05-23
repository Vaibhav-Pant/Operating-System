#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
        int a = 0;
        int b = 1;
        int n = atoi(argv[1]);
        printf("Printing Fibonacci series upto %d terms: \n",n);
        printf("%d %d ", a,b);  
        for(int i = 2; i < n; i++)
        {
                int c = a+b;
                printf("%d ",c);
                a = b;
                b = c;
        }
        printf("\n\n"); 

        return 0;
}

