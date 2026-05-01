#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
  int i;
  pid_t pid;
  do
  {
	  printf("1. ls\n");
	  printf("2. date\n");
	  printf("3. ps\n");
	  printf("0. Exit\n");
	  printf("\nYour Selection => ");
	  scanf("%d", &i);
	  while(getchar() != '\n');
	  if (i > 0 && i <= 3)  {
			pid = fork();
			if (pid == 0) 
			{
				switch(i) {
					case 1:
						execlp("ls", "ls", NULL);
						perror("cannot execute ls");
						exit(1);
					case 2:
						execlp("date", "date", NULL);
						perror("cannot execute date");
						exit(1);
					case 3:
						execlp("ps", "ps", NULL);
						perror("cannot execute ps");
						exit(1);
				}
			}
			if (pid < 0)
			{
				perror("fork failed");
				exit(1);
			}
			else {
				wait(NULL);
			}
	  }
  } while (i!=0);
  printf("Good Bye\n");  
}