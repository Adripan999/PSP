#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void main(){
    int fd[2];
    pid_t pid;
    char entrada[100];
    int suma = 0;

    pipe(fd);
 
    pid = fork();

    if (pid == 0){
        close(fd[1]);
 
        do{
            read(fd[0], entrada, sizeof(entrada));
 
            if (entrada[0] != '+'){
                suma = suma + atoi(entrada);
            }
        } while (entrada[0] != '+');
 
        printf("Recibido caracter +\n");
        printf("La suma total es igual a: %d\n", suma);
        close(fd[0]);
        exit(0);
    }else {
        close(fd[0]);
 
        do{
            printf("Numero a sumar: ");
            scanf("%99s", entrada);
            write(fd[1], entrada, sizeof(entrada));

        } while (entrada[0] != '+');
        close(fd[1]);
        wait(NULL);
    }
}