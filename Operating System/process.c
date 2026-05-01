# include <stdio.h>
# include <stdlib.h>
# include <pthread.h> 
# include <unistd.h>
# include <sys/wait.h>
# include <sys/types.h>
int main()
{
      pid_t pid;
      int i;

      for(i = 0; i < 3; i++)
      {
            pid = fork();  // create a new process
            if(pid == 0)
            {
                  printf("child %d\n", i +1);
                  printf("child %d\n", getpid());
                  exit(0);
            }
            
      }

      while (wait(NULL) != -1);
      printf("Goodbye!\n");

      return 0;
}