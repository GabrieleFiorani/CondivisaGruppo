// * programma che data una matrice inverte il segno della sua diagonale principale
#include <stdio.h>
#include <stdlib.h>

//*funzione per invertire segno della diagonale principale
int** invertiDiag(int** a, int size){
    int i = 0, j = 0;
    for(i = 0; i < size; i++){
        for(j = 0; j < size; j++){
            if (i == j){
                a[i][j] = -a[i][j];
                break;
            }
        }
    }
    return a;
}

//*stampa mat invertita
void print_subMat(int** matrix, int M){
    int i, j;
    for(i = 0; i < M; i++){
        for(j = 0; j < M; j++){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    return;
}


int main(){

    int M;
    int i = 0, j = 0;
    int val;

    printf("Inserire grandezza matrice: ");
    scanf("%d", &M);

    int** mat = (int**)malloc(M* sizeof(int*));
    for(i = 0; i < M; i++){
        mat[i] = (int*)malloc(M* sizeof(int)); 
    }

    for(i = 0; i < M; i++){
        for(j = 0; j < M; j++){
            printf("Inserire val in posizione %d %d: ", i, j);
            scanf("%d", &val);
            mat[i][j] = val;
        }
    }


    int** ris = invertiDiag(mat, M);
    
    print_subMat(ris, M);

    //*libera memoria
    for(i = 0; i < M; i++){
        free(mat[i]);  
    }
    free(mat);

    return 0;
}
