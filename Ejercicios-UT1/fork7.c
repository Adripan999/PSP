#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
void main() {
    printf("CCC \n");
    if (fork() != 0){
        wait(NULL);
        printf("AAA \n");
    }
    else{
        printf("BBB \n");
    } 
    exit(0);
}

//a)

/*b) 
el código propuesto puede generar 2 salidas diferentes
la primera salida es: CCC AAA BBB
la segunda salida es: CCC BBB AAA
estos dos tipos de salidas se producen porque el proceso padre y el proceso hijo se ejecutan de manera simultanea, 
por lo que no se puede predecir cuál de los dos procesos se ejecutará primero después de la llamada a fork().*/

//c)