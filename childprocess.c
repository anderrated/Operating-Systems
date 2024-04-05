// AUTHOR: Andrea A. Laserna
// CMSC 125 LAB - Forking Process

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    int num;

    printf("Enter number: \n");
    scanf("%d", &num);

    printf("[Parent] time started: 1\n");
    // Creating a process
    for(int i=1; i<num+1; i++) {
        pid_t p = fork();
        if (p == 0) {
            printf("[Child %d] time started: %d\n", i, i+1);
            exit(0);
        } else if (p > 0) {
            // Parent waits for child
            wait(NULL);
        } else {
            printf("fork failed");
            return 1;
        }
    }

    printf("[Parent] time ended: %d\n", num+2);
    printf("All child processes done executing. Parent exiting.");
    return 0;
}
