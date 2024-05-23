#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include<sys/types.h>
#include<sys/wait.h>


void print_odd(int n, int m){
	printf("Printing odd number: \n");
	for(int i = n; i <= m; i+=2)
	{
		printf("%d ",i);
	}
	printf("\n");
}



void print_even(int n, int m){
	printf("Printing even numbers: \n");
	for(int i = n; i <= m; i+=2)
	{
		printf("%d ",i);
	}
	printf("\n");
}



int main(){

	int n,m;
	
	printf("Enter the value of n and m: ");
	scanf("%d",&n);	
	scanf("%d",&m);	


        pid_t odd, even;
        odd = fork();
	
	// Odd print calling
        if(odd < 0)
        {
		printf("Fork failed for odd.");
		exit(1);
	}
	else if (odd == 0){
		if(n%2 == 0)
		{
			print_odd(n+1,m);
		}
		else{
			print_odd(n,m);
		}
	}
	else{
		// Even print calling
		wait(NULL);
		even = fork();
		if(even < 0){
			printf("fork failed for even.");
			exit(1);
		}
		else if(even == 0){
			if(n%2 == 0)
			{
				print_even(n,m);
			}
			else{	
				print_even(n+1,m);
			}
		}
	}


	return 0;
}

