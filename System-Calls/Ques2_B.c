#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{

	int n, num1, num2;
	pid_t process_fibo, process_prime;
	process_fibo = fork();

	if(process_fibo < 0){
		printf("fork failed for fibo.\n");
		exit(1);
	}
	else if(process_fibo == 0){

		printf("Enter the value of n: ");
		scanf("%d",&n);
		char num[100];
		sprintf(num, "%d", n);
		char *args[] = {"./fibonaci",num, NULL};
		execv(args[0],args);
	}

	else{
		wait(NULL);
		process_prime = fork();
		if(process_prime < 0){
			printf("fork failed for prime.\n");
			exit(1);
		}
		else if(process_prime == 0)
		{
			printf("Enter Value of n and m: ");
			scanf("%d %d",&num1, &num2);
			char a1[100];
		        char a2[100];
			sprintf(a1, "%d", num1);
			sprintf(a2, "%d", num2);
			char *args[] = {"./prime_number",a1,a2,NULL};
			execv(args[0],args);
		}
		else{
			wait(NULL);
		}
	}


	return 0;
}

