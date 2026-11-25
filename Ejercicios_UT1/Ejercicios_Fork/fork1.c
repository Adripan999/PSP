#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void main(){
    pid_t pid, pid_hijo;
    
    pid = fork();
    
    if (pid == 0 )  //Nos encontramos en Proceso hijo 
    {        
        printf("Soy el proceso hijo ... \n");	  
        printf("Mi PID es: %d \n", getpid());
        printf("El PID de mi padre es: %d\n", getppid());
    }
    else    //Nos encontramos en Proceso padre 
    { 
        pid_hijo = wait(NULL); //espera la finalización del proceso hijo
        printf("Soy el proceso padre ... \n");
        printf("Mi PID es: %d \n", getpid());
        printf("El PID de mi padre es: %d\n", getppid());
        printf("El Proceso hijo ha terminado \n");

    }
     exit(0);
}