/*
Scrivere un programma che legga un numero positivo 
e calcoli la somma dei numeri da 1 a n.
*/

#include <stdio.h>

int main(){
    int n, ris = 0;

    printf("Inserisci il numero da calcolare: ");
    scanf("%d", &n);
    if (n == 1){
        printf("Risultato: 1\n");
        return 0;
    }

    if (n < 1){
        printf("Input non valido.\n");
        return 0;
    }


    while(n > 0){
        ris += n;
        n--;
    }
    
    printf("Risultato: %d\n", ris);
    return 0;
}