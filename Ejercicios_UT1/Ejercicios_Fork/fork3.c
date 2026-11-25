#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
void main() {

    printf("Inicio\n");
    pid_t pid = fork();
    printf("Después del fork\n");
    if (pid == 0) {
        printf("Soy el hijo\n");
    } else {
        printf("Soy el padre\n");
    }   
    printf("Fin\n");

}
// a) En le código existen 2 procesos el proceso padre y un proceso hijo
// b) El proceso padre ejecuta las instrunciones de las lineas 8, 10, 14 y 16 y el proceso hijo ejecuta las intrucciones de las líneas 10, 12 y 16
// C) El unico mensaje que no se repite es el de la línea 10, el resto de mensajes se repiten y además puedes aparecer en distinto orden.