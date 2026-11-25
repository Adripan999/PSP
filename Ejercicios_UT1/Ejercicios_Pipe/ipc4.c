#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

void main(){
    int fd1[2];
    int fd2[2];
    pid_t pid;
    int numero, resultado, i;
    

    pipe(fd1);
    pipe(fd2);
 
    pid = fork();

    if (pid == 0){
        close(fd1[1]);
        close(fd2[0]);

        read(fd1[0], &numero, sizeof(numero));

        resultado = 1;
        for(i=1; i<=numero; i++){
            resultado *= i;
        }
        write(fd2[1], &resultado, sizeof(resultado));

        close(fd1[0]);
        close(fd2[1]);
    }else{
        close(fd1[0]);
        close(fd2[1]);

        srand(time(NULL));
        numero = rand() % 11;

        printf("numero generado %d\n", numero);
        write(fd1[1], &numero, sizeof(numero));
 
        read(fd2[0], &resultado, sizeof(resultado));
        printf("el factorial de %d es %d\n", numero, resultado);

        close(fd1[1]);
        close(fd2[0]);
        wait(NULL);
    }
}