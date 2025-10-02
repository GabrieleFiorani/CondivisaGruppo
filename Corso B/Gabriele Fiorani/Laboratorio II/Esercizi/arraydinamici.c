#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>


void termina(char *messaggio) {}

int main(int argc, char *argv[]) {
    int n;

    printf("Inserisci il numero N: ");
    if (scanf("%d", &n) != 1) {
        termina("Valore da tastiera non valido!");
    }

    if (n <= 0) {
        termina("Il numero di elementi deve essere positivo!");
    }

    int *a = malloc(n * sizeof(int));
    if (a == NULL) termina("Errore allocazione memoria!");

    int *b = malloc(n * sizeof(int));
    if (b == NULL) termina("Errore allocazione memoria!");

    int sommaA = 0;
    int sommaB = 0;
    int x = 0;
    int y = 0;

    for(int i=1;i<n+1;i++){
        if(i%3==0 && i%5!=0){
            a[x] = i;
            x++;
            sommaA += i;
        }
        if(i%5==0 && i%3!=0){
            b[y] = i;
            y++;
            sommaB +=i;
        }
    }


    printf("Lunghezza di a[]: %d, la somma di a[]: %d\n", x, sommaA);
    printf("Lunghezza di b[]: %d, la somma di b[]: %d\n", y, sommaB);

    free(a);
    free(b);
    
    return 0;
}
