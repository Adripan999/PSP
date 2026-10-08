#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main(){
    pid_t pid1, pid2, pid3;
    pid1 = fork();
    if (pid1 == 0){
        printf("Soy el proceso 2 voy a dormir durante 5 segundos\n");
        sleep(5);
        printf("Soy el proceso 2 y acabo de despertar\n");
    }else{
        pid2 = fork();
        if (pid2 == 0){
            printf("Soy el proceso 3 y voy a dormir 2 segundos\n");
            sleep(2);
            printf("Soy el proceso 3 y acabo de despertar\n");
        }else{
            pid3 = fork();
            if (pid3 == 0){
                printf("Soy el proceso 4 y voy a dormir 4 segundos\n");
                sleep(4);
                printf("Soy el proceso 4 y acabo de despertar\n");
            }else{
                pid1 = wait(NULL); // el proceso padre espera a que el proceso hijo 1 termine para ejecutarse.
                pid2 = wait(NULL); // el proceso padre espera a que el proceso hijo 2 termine para ejecutarse.
                pid3 = wait(NULL); // el proceso padre espera a que el proceso hijo 3 termine para ejecutarse.
                printf("Soy el proceso padre\n");
            }
        }
    }
    exit(0);
}

//a) Si, el primero que termina es el proceso 3 ya que es el proceso que duerme menos tiempo.

//b) Si eliminamos la instrucción sleep los procesos se ejecutan segun en el orden de ejecución que decida tener el proceso padre, es decir estos no tiene un orden fijo