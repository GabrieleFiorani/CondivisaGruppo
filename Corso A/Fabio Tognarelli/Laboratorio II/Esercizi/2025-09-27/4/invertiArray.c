/* Scrivere un programma che dato un array di interi A, la cui dimensione deve essere chiesta in input
all’utente. Il programma deve invertire l'array senza utilizzare un array di appoggio, ossia scambiare il contenuto della prima e
dell'ultima cella, della seconda e della penultima, ecc… ed infine stampare a video ogni singolo elemento dell’array modificato.*/

#include <stdio.h>
int main(){

    int n;
    int i = 0, tmp;

    printf("DImensione dell'array: ");
    scanf("%d", &n);
    int A[n];

    //*riempi array
    for(i = 0; i < n; i++){
        scanf("%d", &tmp);
        A[i] = tmp;
    }

    //*inverti array
    for(i = 0; i < n / 2; i++){
        tmp = A[n - 1 - i];
        A[n - 1 - i] = A[i];
        A[i] = tmp;
    }

    //*stampa risultato
    printf("Array ribaltato: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", A[i]);
    }
    return 0;
}