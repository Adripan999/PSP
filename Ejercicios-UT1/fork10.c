#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
    pid_t p2, p3;
    int suma = 0;

    p2 = fork();

    if (p2 == 0){
        suma = 0;
        for (int i = 1; i <= 100; i++){suma += i;}
        printf("Soy el proceso 2 y he realizado la suma de los numeros 1..100 y el resultado es: %d\n", suma);
    }else{
        p3 = fork();

        if (p3 == 0){
            suma = 0;
            for (int i = 101; i <= 200; i++){suma += i;}
            printf("Soy el proceso 3 y he realizado la suma de los numeros 101..200 y el resultado es: %d\n", suma);
        }else{
            p2 = wait(NULL);
            p3 = wait(NULL);
            printf("Todos los cálculos han finalizado.\n");
        }
    }

    
    exit(0);
}