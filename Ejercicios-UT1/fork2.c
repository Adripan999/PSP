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
        printf("Adrián de Armas Peña \n");
    }
    else    //Nos encontramos en Proceso padre 
    { 
        pid_hijo = wait(NULL); //espera la finalización del proceso hijo
        printf("Mi PID es: %d \n", getpid());
        printf("El PID de mi hijo es: %d\n", pid_hijo);

    }
     exit(0);
}