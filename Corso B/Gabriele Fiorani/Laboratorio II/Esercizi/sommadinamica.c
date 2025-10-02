#define _GNU_SOURCE   
#include <stdio.h>    
#include <stdlib.h>   
#include <stdbool.h>  
#include <assert.h>   
#include <string.h>  

int main(int argc, char *argv[]){
    int n;
    puts("Inserisci il numero di elementi: ");
    int e;
    e = scanf("%d", &n);

    if(e != 1){
        puts("Valore da tastiera non trovato!");
        exit(1);
    }

    if(n <= 0){
        puts("Il numero di elementi deve essere positivo!");
        exit(2);
    }

    int *a;
    a = malloc(n * sizeof(int));
    if(a == NULL){
        puts("Malloc Fallita!");
        exit(3);
    }

    for(int i = 0; i < n; i++){
        printf("Inserisci l'elemento di posto %d: ", i);
        e = scanf("%d", &a[i]);
        if(e != 1){
            puts("Valore dell'array non trovato!");
            exit(1);
        }
    }

    int somma = 0;  // Inizializzazione della somma a 0
    for(int i = 0; i < n; i++){
        somma += a[i];
    }

    printf("La somma degli elementi è: %d\n", somma);
    
    free(a);
    return 0;
}
