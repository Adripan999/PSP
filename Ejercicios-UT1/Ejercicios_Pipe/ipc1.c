#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <time.h>

void main(){
    int fd[2];
    time_t hora;
    char *fecha;
    time(&hora);
    fecha = ctime(&hora);

    pipe(fd);

    pid_t pid = fork();

    if (pid == 0)
    {
        close(fd[1]);
        char *recibido1;

        read(fd[0],&recibido1, sizeof(recibido1));
        printf("Soy el proceso hico con PID: %d\n", getpid());
        printf("Fecha/hora: %s", recibido1);
        
        
    }else{
        close(fd[0]);
        write(fd[1], &fecha, sizeof(fecha));
        close(fd[1]);
        wait(NULL);
    }
    
}