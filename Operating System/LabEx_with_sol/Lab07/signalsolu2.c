/*
2. Write the following C program. A parent forks 5 children processes. Each child
prints its own process id and enters a forever loop. Parent sleeps for 2 seconds to
give time to all children to enter their forever loop. Parent then sends SIGTERM
to all children. When each child process receives the SIGTERM, it prints its
process id, and terminates. After all children have been killed, the parent prints
“Parent: I have killed all of my children”. The example output is as follows:
Child: my id is 430
Child: my id is 431
Child: my id is 432
Child: my id is 433
Child: my id is 434
Child: my id is 430, my parent has just terminated me
Child: my id is 434, my parent has just terminated me
Child: my id is 433, my parent has just terminated me
Child: my id is 432, my parent has just terminated me
Child: my id is 431, my parent has just terminated me
Parent: I have killed all of my children
Note: Use the system call kill() send signal from parent to child. The parent needs an
array to store process id of all children. The system call getpid() is used to get the process
id of the process.
*/
#include  <stdio.h>
#include  <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void terminated(int);              
int main(void)
{
    pid_t pid[5];
    int i = 0;
    for (i = 0; i < 5; i++) {
        pid[i] = fork();
        if (pid[i] == 0) {
            signal(SIGTERM, terminated);
            printf("Child: my id is %d\n", getpid());
            while(1);
        }        
    }
    sleep(2);
    for(i = 0; i < 5; i++) {
        kill(pid[i], SIGTERM);
    }
    while(wait(NULL) != -1);
    printf("Parent: I have killed all of my children\n");
    return 0;
}

void terminated (int sig)
{
	printf("Child: my id is %d, my parent has just terminated me\n", getpid());
    exit(0);

}
