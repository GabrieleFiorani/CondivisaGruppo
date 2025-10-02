#define _GNU_SOURCE   
#include <stdio.h>    
#include <stdlib.h>   
#include <stdbool.h>  
#include <assert.h>   
#include <string.h>  

void termina(char *messaggio);

bool primo(int k){
    if(k < 2) return false; 
    if(k == 2) return true;  
    if(k % 2 == 0) return false; 
    
    for(int i = 3; i * i <= k; i += 2){
        if(k % i == 0) return false;
    }
    return true;
}

int main(int argc, char *argv[]){

    int n;
    if(argc != 3){
        printf("Uso: %s intero_pos nome_file\n", argv[0]);  
        return 1;
    }

    n = atoi(argv[1]);
    if(n < 1) termina("è richiesto un intero *positivo*!");

    int *a;
    int capacità = 10;
    int messi = 0;
    a = malloc(capacità * sizeof(int));
    if(a == NULL) termina("Malloc fallita!");


    for(int i = 2; i <= n; i++){
        if(primo(i)){
            if(messi == capacità){
                capacità = 2 * capacità;
                a = realloc(a, capacità * sizeof(int));
                if(a == NULL) termina("Realloc fallita!");
            }
            a[messi] = i;
            messi++;
        }
    }

    a = realloc(a, messi * sizeof(int));
    if(a == NULL) termina("Realloc fallita!");

    FILE *f = fopen(argv[2], "w");
    if(f == NULL) termina("Apertura del file fallita");

    for(int i = 0; i < messi; i++){
        fprintf(f, "%d\n", a[i]);
    }

    if(fclose(f) != 0) termina("Errore in chiusura del file");

    printf("--- contenuto di a: %p\n", (void*)a);
    free(a);
    return 0;
}

void termina(char *messaggio){
    perror(messaggio);
    exit(1);
}
