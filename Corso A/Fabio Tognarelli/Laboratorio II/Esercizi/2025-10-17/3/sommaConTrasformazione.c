//*viene sommato un array, ma prima viene modificato in base ad una funzione arbitrariamente scelta
#include <stdio.h>
#include <stdlib.h>

//* puntatore ad una funzione che prende un int e restituisce un int
typedef int (*trasforma_fn)(int);


//*funzioni di trasformazione
int valore_assoluto(int x){
    if(x < 0)
        x = -x;
    return x;
}
int quadrato(int x){
    return x * x;
}

//*funzione di somma con la trasformazione arbitraria
int somma_con_trasformazione (int* a, int dim, trasforma_fn trasforma){
    int i, ris = 0;

    for(i = 0; i < dim; i++){
        ris += trasforma(a[i]);
    }

    return ris;
}


int main(){
    int n;
    int i, val;
  
    //*creazione array dinamico
    printf("Inserire grandezza array: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n*sizeof(int));
    printf("Inserire elementi nell'array:\n");
    for(i = 0; i < n; i++){
        scanf("%d", &val);
        arr[i] = val;
    } 
    
    //*stampa somma con val assoluto
    printf("%d ", somma_con_trasformazione(arr, n, valore_assoluto));
    printf("%d\n", somma_con_trasformazione(arr, n, quadrato));

    free(arr);
    return 0;
}