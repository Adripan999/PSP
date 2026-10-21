#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <sys/wait.h>

void main(){
    int fd[2];
    pid_t pid;
    int aleatorio1, aleatorio2;

    pipe(fd);
 
    pid = fork();

    if (pid == 0){
        close(fd[0]);
        srand(time(NULL));
        aleatorio1 = rand() % 50 + 1;
        aleatorio2 = rand() % 50 + 1;

        write(fd[1], &aleatorio1, sizeof(aleatorio1));
        write(fd[1], &aleatorio2, sizeof(aleatorio2));

    }else{
        close(fd[1]);
        read(fd[0], &aleatorio1, sizeof(aleatorio1));
        read(fd[0], &aleatorio2, sizeof(aleatorio2));

        printf("%d + %d = %d\n", aleatorio1, aleatorio2, aleatorio1 + aleatorio2);
        printf("%d - %d = %d\n", aleatorio1, aleatorio2, aleatorio1 - aleatorio2);
        printf("%d * %d = %d\n", aleatorio1, aleatorio2, aleatorio1 * aleatorio2);
        printf("%d / %d = %d\n", aleatorio1, aleatorio2, aleatorio1 / aleatorio2);
        close(fd[0]);
    }

}