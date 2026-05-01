#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main() {
    pid_t pid;
    int i;
    for (i = 0; i < 5; i++) {
        pid = fork();   // create a child process
        if (pid == 0) {
            printf("I am child %d\n", i);
            if (i % 2 == 0) {
                for (int j = 0; j < 4; j++) {
                    pid_t pid2 = fork();
                    if (pid2 == 0) {
                        printf("I am sub-child %d of child %d\n", j, i);
                        exit(0);
                    }
                }
            } else {
                for (int j = 0; j < 5; j++) {
                    pid_t pid3 = fork();
                    if (pid3 == 0) {
                        printf("I am sub-child %d of child %d\n", j, i);
                        exit(0);
                    }
                }
            }
            while (wait(NULL) != -1);
            exit(0);
        }
    }   
    while (wait(NULL) != -1);
    printf("I am parent\n");
    return 0;
}


