#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

void main(){
    int fd[2];
    pid_t pid;
    char buffer[100];
    int suma = 0;

    pipe(fd);
 
    pid = fork();

    if (pid == 0){
        
    }
}