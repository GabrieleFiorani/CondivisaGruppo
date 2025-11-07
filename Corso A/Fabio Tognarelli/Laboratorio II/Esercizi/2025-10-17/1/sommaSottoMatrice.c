//*alloca matrice in heap, riempi di elementi, poi dentro funzia calcola la somma della sottomatrice
//* la mat NxN parte da A[0][0] per capirsi
//*input: M, N, valori mat MxM, 
//* output: somma(NxN)

#include <stdio.h>
#include <stdlib.h>

int sum_submatrix( int **matrix, int n){
    int i = 0, j = 0;
    int subTot = 0;

    if(n == 0)
        return 0;
    
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            subTot += matrix[i][j];
        }
    }
    return subTot;
}



int main(){
    //*grandezza matrici
    int m, n;

    int i = 0, j = 0;

    printf("Inserire grandezza Matrice A: ");
    scanf("%d", &m);

    printf("Inserire grandezza Sotto-matrice B: ");
    scanf("%d", &n);

    //*se mat B > mat A => n = m
    if (n > m){
        n = m;
    }

    //*creazione matrice A
    int** A = (int**)malloc(m*sizeof(int*));  
    
    for(i = 0; i < m; i++){
        A[i] = (int*)malloc(m*sizeof(int));
    }

    //*inerimento in input dei valori della matrice A
    for (i = 0; i < m; i++){
        int x = 0;
        for(j = 0; j < m; j++){
            printf("Inserisci valore in posizione %d - %d: ", i, j);
            scanf("%d", &x);
            A[i][j] = x;
        }
    }

    //  STAMPA MATRICE SU TERMINALE
    for(i = 0; i < m; i++){
        for(j = 0; j < m; j++){
            printf("%d ", A[i][j]);  // stampa l'elemento e uno spazio
        }   
    printf("\n");  // vai a capo dopo ogni riga
    }
    

    int ris = sum_submatrix(A, n);
    printf("Somma sottomatrice: %d\n", ris);
    
    //*liberazione memoria
    for(i = 0; i < m; i++){
        free(A[i]);
    }
    free(A);
    
    return 0;
}