#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void main(){
    pid_t pid1, pid2;
    
    pid1 = fork();
    

    if (pid1 == 0) {
        printf("Soy el proceso 2 voy a dormir durante 10 segundos\n");
        sleep(10);
        printf("Despierto\n");
        exit(0);
    }
    
    pid2 = fork();

    if (pid2 == 0) {
        printf("Soy el proceso 3\n");
        printf("Mi PID es: %d \n", getpid());
        printf("El PID de mi padre es: %d\n", getppid());
    }else {
        pid1 = wait(NULL); // el proceso padre espera a que el proceso hijo 1 termine para ejecutarse.
        pid2 = wait(NULL); // el proceso padre espera a que el proceso hijo 2 termine para ejecutarse.
        printf("Soy el proceso padre\n");
    }
    exit(0); 
}