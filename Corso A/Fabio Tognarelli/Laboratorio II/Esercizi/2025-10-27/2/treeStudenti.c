//* albero binario di studenti
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Studente{
    int mat;
    int eta;
    struct Studente* sx;
    struct Studente* dx;
}Studente;

//* CREA un nuovo nodo studente
Studente* creaStudente(int mat, int eta){
    Studente *nuovo = (Studente*)malloc(sizeof(Studente));
    nuovo->mat = mat;
    nuovo->eta = eta;
    nuovo->sx = NULL;
    nuovo->dx = NULL;
    return nuovo;
}

//* INSERISCE un nuovo studente nell'albero
void insertStudente(int matricola, int eta, Studente** root){
    if(*root == NULL){
        *root = creaStudente(matricola, eta);
        return;
    }

    if(eta >= (*root)->eta)
        insertStudente(matricola, eta, (&(*root)->dx));
    else
        insertStudente(matricola, eta, &((*root)->sx));
}

//* STAMPA TREE CON ETA' CRESCENTE
void printTree(Studente *root){
    if(root == NULL)
        return;
    printTree(root->sx);
    printf("%d\n", root->eta);
    printTree(root->dx);
}

//*STAMPA studenti di una certa eta' dell'albero
void stampaStudenti(int eta, Studente *root){
    if(root == NULL){
        return;
    }
    stampaStudenti(eta, root->sx);
    if(root->eta == eta)
        printf("Matricola: %d; Eta': %d\n", root->mat, root->eta);
    stampaStudenti(eta, root->dx);
    
}

//* SVUOTA LA MEMORIA
void liberaTree(Studente** root){
    if(*root == NULL)
        return;
    liberaTree((&(*root)->sx));
    liberaTree((&(*root)->dx));
    free(*root);
}


int main(){
    int matricola = 1, eta, val;
    Studente *root = NULL;

    while(true){
        printf("Inserie Matricola: ");
        scanf("%d", &matricola);
        if(matricola == 0)
            break;
        printf("Inserie eta': ");
        scanf("%d", &eta);

        insertStudente(matricola, eta, &root);
    }

    //*stampa tree in modo crescente
    printTree(root);

    //*stampa studenti selezionati
    printf("Inserire eta' studenti da stampare dall'albero: ");
    scanf("%d", &val);
    stampaStudenti(root, val);

    //*Libera memoria
    liberaTree(&root);
    
    return 0;
}
