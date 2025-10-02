#define _GNU_SOURCE   
#include <stdio.h>    
#include <stdlib.h>   
#include <stdbool.h>  
#include <assert.h>   
#include <string.h>  

void termina(char *messaggio);

bool pari(int number) { 
    return number % 2 == 0;  
}

int main(int argc, char *argv[]) {

    if(argc < 4) {
        termina("Uso: programma num1 num2 ... numN filepari filedispari");
    }

    int sommapari = 0;  
    int sommadispari = 0;


    FILE *fpari = fopen(argv[argc-2], "w");
    if(fpari == NULL) termina("Errore apertura file per numeri pari!");

    FILE *fdispari = fopen(argv[argc-1], "w");
    if(fdispari == NULL) termina("Errore apertura file per numeri dispari!");

    for(int i = 1; i < argc-2; i++) { 
        int numero = atoi(argv[i]); 

        if(pari(numero)) {
            sommapari += numero;
            fprintf(fpari, "%d\n", numero);  
        } else {
            sommadispari += numero;
            fprintf(fdispari, "%d\n", numero);  
        }
    }

    if(fclose(fpari) != 0) termina("Errore in chiusura del file per numeri pari");
    if(fclose(fdispari) != 0) termina("Errore in chiusura del file per numeri dispari");

    printf("Somma interi pari: %d\n", sommapari);
    printf("Somma interi dispari: %d\n", sommadispari);

    return 0;
}

void termina(char *messaggio) {
    perror(messaggio);
    exit(1);
}
