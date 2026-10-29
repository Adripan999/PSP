#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
 
void main()
{
    int pipe1[2]; // P2 -> P1 (DNI)
    int pipe2[2]; // P1 -> P2 (letra)
    int pid;
    int dni;
    char letra;
    char letras[] = "TRWAGMYFPDXBNJZSQVHLCKE";
 
    pipe(pipe1);
    pipe(pipe2);
 
    pid = fork();
 
    if (pid == 0){
        close(pipe1[0]); 
        close(pipe2[1]); 
 
        printf("Introduce el número de tu DNI: ");
        scanf("%d", &dni);
 
        write(pipe1[1], &dni, sizeof(dni));
 
        read(pipe2[0], &letra, sizeof(letra));
        printf("la letra del NIF es %c\n", letra);
 
        close(pipe1[1]);
        close(pipe2[0]);
    }else{
        close(pipe1[1]); 
        close(pipe2[0]); 
 
        read(pipe1[0], &dni, sizeof(dni));
 
        letra = letras[dni % 23];
 
        write(pipe2[1], &letra, sizeof(letra));
 
        close(pipe1[0]);
        close(pipe2[1]);
        wait(NULL);
    }
}