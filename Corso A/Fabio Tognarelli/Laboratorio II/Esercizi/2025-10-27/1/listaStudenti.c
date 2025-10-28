#include <stdio.h>
#include <stdlib.h>

typedef struct Studente{
    int mat;
    int eta;
    Studente* next;
} Studente;


//*STAMPA Studente
void print_list(Studente **head){
    if(*head == NULL){
        return;
    }
    printf("Matricola:  %d; Eta': %d\n", *head->mat, *head->eta);
    print_list(*head->next);
}

//*ADD STUDENTE IN CODA 
void insert(int matricola, int eta, Studente **head){
    Studente *nuovo, *att;

    att = *head;   //*inizializzazione nuovo nodo e nodi per scorrere la lista
    nuovo = (Studente*)malloc(sizeof(Studente));
    if(nuovo == NULL)   //*controllo corretta allocazione heap
        exit(1);

    nuovo->mat = matricola;
    nuovo->eta = eta;

    if(*head == NULL){     //*Studente vuota
        *head = nuovo;
    }else{
        while(att->next != NULL){ //*scorrere la Studente
            att = att->next;
        }
        nuovo->next = att->next;  //*attacco il nuovo nodo
        att->next = nuovo;
    }
    return;
}

//*ORDINA IN MODO CRESCENTE PER ETA'  
void ordina(Lista *head){
    Studente *primo, *secondo;

    primo = NULL;
    secondo = *head;

    
    if(secondo == NULL){    //*Lista vuota
        return;
    }

    do{         //*sort 
        primo = secondo;
        do{
            secondo = secondo->next;
            if(secondo->eta < primo->eta){
                int tmpMat = primo->mat; 
                int tmpEta = primo->eta;
                primo->mat = secondo->mat;
                primo->eta = secondo->eta;
                secondo->mat = tmpMat;
                secondo->eta = tmpEta;
            }
        } while(secondo != NULL);
    } while(primo != NULL);
}


//*FILTRA LA LISTA PER ETA'
Studente *estrai(int e, Studente *head){
    Studente *tmp = head;
    Studente *nuovaLista = NULL;
    
    while(tmp != NULL){
        if(tmp->eta == e){
            insert(tmp->mat, tmp->eta, &nuovaLista);
        }
        tmp = tmp->next;
    }

    return nuovaLista;
}

void liberaMem(Studente **head){
    Studente *tmp;
    while((*head)->next != NULL){
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}

int main(){*}