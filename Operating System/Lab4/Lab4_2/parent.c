#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <num1> <num2> <num3> <num4>\n", argv[0]);
        return 1;
    }

    pid_t pid1, pid2;
    int status1, status2;

    pid1 = fork();

    if (pid1 < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid1 == 0) { // First child process
        execlp("./child", "./child", argv[1], argv[2], (char *) NULL);
        perror("execlp failed");
        exit(1);
    }

    pid2 = fork();

    if (pid2 < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid2 == 0) { // Second child process
        execlp("./child", "./child", argv[3], argv[4], (char *) NULL);
        perror("execlp failed");
        exit(1);
    }

    // Parent process waits for both children
    waitpid(pid1, &status1, 0);
    waitpid(pid2, &status2, 0);

    // Extract the exit status
    if (WIFEXITED(status1) && WIFEXITED(status2)) {
        int result1 = WEXITSTATUS(status1);
        int result2 = WEXITSTATUS(status2);
        int final_result = result1 + result2;
        printf("Parent: Final result = %d\n", final_result);
    } else {
        fprintf(stderr, "One of the child processes did not exit normally\n");
        return 1;
    }

    return 0;
}
