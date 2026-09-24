#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void main(){
    pid_t pid1, pid2;
    
    pid1 = fork();
    

    if (pid1 == 0) {
        printf("Soy el proceso hijo 1\n");
        printf("Mi PID es: %d \n", getpid());
        printf("El PID de mi padre es: %d\n", getppid());
        exit(0); // despues de ejecutar el proceso hijo 1 este hace un exit para que no se repita la ejecucion del proceso hijo 2
    }
    
    pid2 = fork();

    if (pid2 == 0) {
        sleep(3);
        printf("Soy el proceso hijo 2\n");
        printf("Mi PID es: %d \n", getpid());
        printf("El PID de mi padre es: %d\n", getppid());
    }else {
        pid1 = wait(NULL); // el proceso padre espera a que el proceso hijo 1 termine para ejecutarse.
        pid2 = wait(NULL); // el proceso padre espera a que el proceso hijo 2 termine para ejecutarse.
        printf("Soy el proceso padre ... \n");
        printf("Mi PID es: %d \n", getpid());
        printf("El PID de mi padre es: %d\n", getppid());
        printf("Los procesos hijos han terminado \n");
    }
    exit(0);
}