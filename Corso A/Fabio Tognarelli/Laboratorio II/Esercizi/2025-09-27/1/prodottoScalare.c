
//*Calcola il prodotto scalare dei numeri contenuti in 2 vettori di lunghezza 10
#include <stdio.h>


int length = 10;    //*lunghezza array

int main(){

    int arr1[length];
    int arr2[length];
    int ris = 0, i = 0;
    
    //*ciclo per riempire gli array e calcolare il risultato del prodotto
    for(i = 0; i < length; i++){
        printf("Inserisci valori nel primo array all'indice %d: ", i);
        scanf ("%d", &arr1[i]);   
        printf("Inserisci valori nel secondo array all'indice %d: ", i);
        scanf ("%d", &arr2[i]); 
        ris += arr1[i] * arr2[i]; 
    }
    
    //*stampa a schermo il valore del prodotto
    printf("Il valore del prodotto scalare dei 2 array e': %d\n ", ris);
    return 0;
}