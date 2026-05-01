#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t pid;
    int i;

    for (i = 0; i < 2; i++)
    {
        pid = fork();
        if (pid == 0)
        {
            printf("child %d\n", i);
            
            
            //exit(0);
        }
    }

    while (wait(NULL) != -1); // wait for all children to finish
    printf("parent goodbye\n");
    return 0;
}
