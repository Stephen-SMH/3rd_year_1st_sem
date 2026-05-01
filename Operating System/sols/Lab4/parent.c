#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
/* parent.c */

int main(int argc, char *argv[]){
  pid_t pid[2], w;	
  int i, result[2], status;
  for (i = 0; i < 2; ++i) {		
    if ((pid[i] = fork()) == 0) {	
		if (i == 0) {
			execl("child", "child", argv[1], argv[2], NULL);
		}
		else {
      		execl("child", "child", argv[3], argv[4], NULL);
		}
    } 
  }

  for( i=0; (w = waitpid( pid[i], &status, 0)) && w != -1; ++i ) {
  	result[i] = WEXITSTATUS(status);
  }
	printf("The result is %d\n", result[0] + result[1]);
  	exit(0);
}
