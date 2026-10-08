#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
    pid_t p2, p3, p4;

    p2 = fork();

    if (p2 == 0){
        printf("Soy el proceso 2, mi PID es: %d, el de mi padre es: %d y la suma de nuestros PID es: %d\n", getpid(), getppid(), getpid() + getppid());
        p3 = fork();

        if (p3 == 0){
            printf("Soy el proceso 3, mi PID es: %d, el de mi padre es: %d y la suma de nuestros PID es: %d\n", getpid(), getppid(), getpid() + getppid());
            p4 = fork();

            if (p4 == 0){
                printf("Soy el proceso 4, mi PID es: %d, el de mi padre es: %d y la suma de nuestros PID es: %d\n", getpid(), getppid(), getpid() + getppid());
            }else{
                p2 = wait(NULL);
                p3 = wait(NULL);
                p4 = wait(NULL);
                printf("Todos los procesos han finalizado.\n");
            }
        }
    }     
    exit(0);
}