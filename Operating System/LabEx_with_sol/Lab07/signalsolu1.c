/*
1. Write the following C program. A parent forks a child process, the parent
executes inside a forever loop. The child sleeps for 5 seconds to give time to the
parent to enter a forever loop. The child then sends the signal SIGINT to the
parent. After the parent receives the signal, it prints “Get SIGINT from child”,
exit the forever loop, print “Bye”, and terminates.
The example output is as follows:
parent: Waiting for my child to send SIGINT
child: Sleeping for 5 seconds
child: sending SIGINT
child: Bye
get SIGINT from child
parent: Bye
Note: Use system call kill() send signal from child to parent. To retrieve the parent
process id use the system call getppid().
*/

#include  <stdio.h>
#include  <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void     ding(int);              
int done = 1;
int main(void)
{
  signal(SIGINT, ding);        
	pid_t pid;
  pid = fork();
  if (pid == 0) {
	  printf("child: Sleeping for 5 seconds\n");
    sleep(5);
    printf("child: sending SIGINT\n");
    kill(getppid(), SIGINT);
		printf("child: Bye\n");
  }
  else {		
    printf("parent: Waiting for my child to send SIGINT\n");			
    while (done);  /* loop and wait    */
    wait(NULL);
    printf("parent: Bye\n");
  }
     return 0;
}

void  ding(int sig)
{
			printf("get SIGINT from child\n");
          done = 0;

}