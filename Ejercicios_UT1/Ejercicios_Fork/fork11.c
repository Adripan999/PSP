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
// a) El orden de ejecución de los procesos no siempre es el mismo, pueden existir 3 formas de que este proceso termine:
// P1 → P2 → P3 → P4
// P1 → P3 → P2 → P4
// P1 → P3 → P4 → P2
// Teniendo en cuenta que el orden de  ejecución de los procesos es de derecha a izquierda.