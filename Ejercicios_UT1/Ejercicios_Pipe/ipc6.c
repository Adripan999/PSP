#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
    pid_t pid2;
    pid_t pid3;
    int pipe1[2]; 
    int pipe2[2]; 
    int pipe3[2];
    int pipe4[2];
    int numero1, numero2, resultadoSuma, resultadoMultiplicacion;

    
    pipe(pipe1);
    pipe(pipe2);
    pipe(pipe3);
    pipe(pipe4);

    pid2 = fork();

    if (pid2 == 0){
        close(pipe1[1]);
        close(pipe3[0]);

        read(pipe1[0], &numero1, sizeof(numero1));
        read(pipe1[0], &numero2, sizeof(numero2));
        resultadoSuma = numero1 + numero2;
        write(pipe3[1], &resultadoSuma, sizeof(resultadoSuma));

        close(pipe1[0]);
        close(pipe3[1]);
    }else{
        pid3 = fork();

        if (pid3 == 0){
            close(pipe2[1]);
            close(pipe4[0]);

            read(pipe2[0], &numero1, sizeof(numero1));
            read(pipe2[0], &numero2, sizeof(numero2));
            resultadoMultiplicacion = numero1 * numero2;
            write(pipe4[1], &resultadoMultiplicacion, sizeof(resultadoMultiplicacion));

            close(pipe2[0]);
            close(pipe4[1]);
        }else{
            close(pipe1[0]);
            close(pipe2[0]);
            close(pipe3[1]);
            close(pipe4[1]);

            printf("Introduce un número: ");
            scanf("%d", &numero1);
            printf("Introduce otro número: ");
            scanf("%d", &numero2);
            write(pipe1[1], &numero1, sizeof(numero1));
            write(pipe2[1], &numero1, sizeof(numero1));
            write(pipe1[1], &numero2, sizeof(numero2));
            write(pipe2[1], &numero2, sizeof(numero2));
            wait(NULL);
            wait(NULL);

            read(pipe3[0], &resultadoSuma, sizeof(resultadoSuma));
            read(pipe4[0], &resultadoMultiplicacion, sizeof(resultadoMultiplicacion));
            printf("Suma: %d\n", resultadoSuma);
            printf("Multiplicación: %d\n", resultadoMultiplicacion);

            close(pipe1[1]);
            close(pipe2[1]);
            close(pipe3[0]);
            close(pipe4[0]);
        }
    }
}