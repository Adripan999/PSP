#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main() {
    pid_t pid2, pid3, pid4;

    printf("Soy el proceso 1 y mi PID es: %d\n", getpid());
    
    pid2 = fork();
    if (pid2 == 0) {
        printf("Soy el proceso 2 y mi PID es: %d, el PID de mi padre es: %d\n", getpid(), getppid());
        exit(0);
    }else{
        pid3 = fork();
        if (pid3 == 0) {
            printf("Soy el proceso 3 y mi PID es: %d\n", getpid());
            fflush(stdout);

            
            pid4 = fork();
            if (pid4 == 0) {
                printf("Soy el proceso 4 y mi PID es: %d, el PID de mi padre es: %d\n", getpid(), getppid());
                exit(0);
            }
            wait(NULL);
        }
    }
    wait(NULL);
    wait(NULL);
    exit(0);
}
// a)