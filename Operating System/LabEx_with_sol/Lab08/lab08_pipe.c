/*
1. Write a C program as follows. The program receives a number from command
line when a user runs the program. The parent then forks a child to calculate the
summation from 1 to the number that the user specified. The child sends the result
back to the parent via the pipe. The parents then prints the result.
Note: One way to convert an integer to string is to use sprintf() function as follows
sprintf(str, “%d”, sum);
This statement converts the integer store in the variable sum to string and store the result
in the variable str.
------------------------------------------------------
The example output of the program is as follows:
./lab8_pipe 5
Parent: waiting for my child
Child: I am calculating
Child: the result is 15
Child: I am sending data
Child: Goodbye
Parent: sum from my child is 15
Parent: Goodbye
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define SIZE 1024
int main(int argc, char *argv[])
{
	int pfd[2];
  	int nread;
  	int pid;
  	char buf[SIZE];
	int num;
	if (argc != 2) {
		printf("Usage lab7_pipe <number>\n");
		exit(0);	
	}
	num = atoi(argv[1]);
  	if (pipe(pfd) == -1)
  	{
    	perror("pipe failed");
    	exit(1);
  	}
  	if ((pid = fork()) < 0)
  	{
    	perror("fork failed");
    	exit(2);
  	}

	if (pid == 0)
  	{
    	/* child */
    	close(pfd[0]);
		printf("Child: I am calculating\n");
		int i, sum = 0;
		for(i = 1; i <= num; i++) {
			sum += i;
		}
		printf("Child: the result is %d\n", sum);
		sprintf(buf, "%d", sum);
		printf("Child: I am sending data\n");
		write(pfd[1], buf,strlen(buf)+1);
		printf("Child: Goodbye\n");
    	close(pfd[1]);
  } else {
    /* parent */
		close(pfd[1]);
		printf("Parent: waiting for my child\n");
		wait(NULL);
		nread = read(pfd[0], buf, SIZE);
		int sum;
		sum = atoi(buf);
      	printf("Parent: sum from my child is %d\n", sum);
		printf("Parent: Goodbye\n");
		close(pfd[0]);
	}
  exit(0);
}