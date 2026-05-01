#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h> 
#include <sys/wait.h>
int main()
{
	pid_t pid;
	int i, j, numChild;
	for (i = 0; i < 5; ++i) {
		pid = fork();
		if (pid == 0) {
			if (i % 2 == 0) {
				numChild = 4;
			}
			else {
				numChild = 5;			
			} 
			for (j = 0; j < numChild; ++j) {
				pid = fork();
				if (pid == 0) {
				 	printf("I am sub-child %d of child %d\n",	j, i);
				   exit(0); //sub-child exit
				}
				//child
			}
			//child
			while (wait(NULL) != -1); // wait for all sub-children
			printf("I am child %d\n",i); 
			exit(0); //child exit
		}
		//parent
   }
   //parent
  while(wait(NULL) != -1); // wait for all children
  printf("I am parent\n");	
  return 0;
}