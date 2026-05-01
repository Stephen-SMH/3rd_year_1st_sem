#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
      pid_t pid; // process id
      for (int i = 0; i < 3; i++)
      {
            pid = fork(); // create a copy parent and child
            if (pid == 0)
            {
                  if (i == 0)
                  {
                        execlp("cd", "cd", "test"); // exit
                        printf("ok\n");
                  }
                  else if (i == 1)
                  {
                        execlp("/bin/echo", "echo", "good afternoon"); // this is recognized as a built in command it shound;t be
                        // it means my system has echo as a funciton normally this should be treated as a program
                        // external command  ()
                        // built in (cd, echo, ls)
                        // should treat echo as a program not a shell built in
                        // the problem is that echo is recognized as both a built in and a program
                        printf("ok\n");
                  }
                  else
                  {
                        execlp("/bin/echo", "echo", "good night");
                        printf("ok\n");
                  }
            }
      }
            while (wait(NULL) != -1); // wait for all children to finish return the pid of the child that finished if not -1
            printf("goodbye\n");
            return 0;
      
}

// built in and program