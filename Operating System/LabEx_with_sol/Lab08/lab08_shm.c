/*

2. Write a C program to do the same task as question number 1 but use share
memory. The parent must remove the shared memory before existing.
-----------------------------
The example output of the program is as follows:
./lab7_shm 5
Parent: I have created a shared memory for result...
Parent: I have attached the shared memory...
Parent: I am about to fork a child process...
Parent: Waiting for my child
Child: I am calculating
Child: The result is 15
Child: Goodbye
Parent: sum from my child is 15
Parent: I have detached the shared memory...
Parent: I have removed the shared memory...
Parent: Goodbye
*/

#include  <stdio.h>
#include  <stdlib.h>
#include  <sys/types.h>
#include  <sys/ipc.h>
#include  <sys/shm.h>
#include <unistd.h>
#include <sys/wait.h>
void  childProcess(int *ShmPtr, int num);

void  main(int  argc, char *argv[])
{
     int    ShmID;
     int    *sum;
     pid_t  pid;
     int    status, num;
     
     if (argc != 2) {
          printf("Usage lab7_shm <number>\n");
          exit(1);
     }
     num = atoi(argv[1]);
     
     
     ShmID = shmget(IPC_PRIVATE, sizeof(int), IPC_CREAT | 0666);
     if (ShmID < 0) {
          printf("*** shmget error (server) ***\n");
          exit(1);
     }
     printf("Parent: I have created a shared memory for result...\n"); 
     sum = (int *) shmat(ShmID, NULL, 0);
     if ( sum == NULL) {
          printf("*** shmat error (server) ***\n");
          exit(1);
     }
     printf("Parent: I have attached the shared memory...\n");
     
     *sum = 0; //initialize shared memory
                 
     printf("Parent: I am about to fork a child process...\n");
     pid = fork();
     if (pid < 0) {
          printf("*** fork error (server) ***\n");
          exit(1);
     }
     else if (pid == 0) {
          childProcess(sum, num);
          exit(0);
     }
     printf("Parent: Waiting for my child\n");     
     wait(NULL);
     printf("Parent: sum from my child is %d\n", *sum);
     shmdt((void *) sum);
     printf("Parent: I have detached the shared memory...\n");
     shmctl(ShmID, IPC_RMID, NULL);
     printf("Parent: I have removed the shared memory...\n");
     printf("Parent: Goodbye\n");
     exit(0);
}

void  childProcess(int *sum, int num)
{
     printf("Child: I am calculating\n");
     int i;
     for(i =1; i <= num; i++) {
		*sum = *sum + i;
     }
     printf("Child: The result is %d\n", *sum); 
     printf("Child: Goodbye\n");
}