//* prodotto scalare tra matrici

#include <stdio.h>

int main(){
    int n;
    int i = 0;
    int j = 0;
    int plc, ris = 0;

    printf("Inserisci grandezza matrici: ");
    scanf("%d", &n);
    int mat1 [n][n];
    int mat2 [n][n];

    printf("Inserisci i valori della prima matrice:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("Riga %d Colonna %d: ", i, j);
            scanf("%d", &plc);
            mat1[i][j] = plc;
        }
    }
    
    printf("Inserisci i valori della seconda matrice:\n");
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf("Riga %d Colonna %d: ", i, j);
            scanf("%d", &plc);
            mat2[i][j] = plc;
        }
    }

    for (i = 0; i < n; i++){
        for (j = 0; j < n; j++){
            ris += mat1[i][j] * mat2[i][j];
        }
    }
    printf("Il prodotto scalare è: %d\n", ris);
    return 0;
}