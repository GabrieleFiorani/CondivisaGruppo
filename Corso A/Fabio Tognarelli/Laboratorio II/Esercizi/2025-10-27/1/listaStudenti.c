#include <stdio.h>
#include <stdlib.h>

typedef struct Studente{
    int mat;
    int eta;
    Studente* next;
} Studente;


//*STAMPA Studente
void print_list(Studente *head){
    if(head == NULL){
        return;
    }
    printf("Matricola:  %d; Eta': %d\n", head->mat, head->eta);
    print_list(head->next);
}

//*ADD STUDENTE IN CODA 
void insert(int matricola, int eta, Studente **head){
    Studente *nuovo, *att;

    att = *head;   //*inizializzazione nuovo nodo per scorrere la lista
    nuovo = (Studente*)malloc(sizeof(Studente));
    if(nuovo == NULL)   //*controllo corretta allocazione heap
        exit(1);

    nuovo->mat = matricola;
    nuovo->eta = eta;

    if(*head == NULL){     //*Studente vuota
        *head = nuovo;
        nuovo->next = NULL;
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
void ordina(Studente **head){
    Studente *primo, *secondo;

    primo = NULL;
    secondo = *head;

    
    if(secondo == NULL){    //*Lista vuota
        return;
    }

    //*sort 
    int scambiato;
    do{                 //*finche' ho uno scambio nel ciclo riparto da capo
        scambiato = 0;
        primo = *head;
        while(primo->next != NULL){     //*ciclo di confronti via viA
            secondo = primo->next;    //*scorro secondo e lo comparo con il primo
            if(primo->eta > secondo->eta){      //*scambio nodi
                int tmpMat = primo->mat;
                int tmpEta = primo->eta;
                primo->mat = secondo->mat;
                primo->eta = secondo->eta;
                secondo->mat = tmpMat;
                secondo->eta = tmpEta;
                scambiato = 1;
            }
            primo = primo->next;    
        }
    }while(scambiato)  
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

//*LIBERA MEMORIA
void liberaMem(Studente **head){
    Studente *tmp;
    while((*head) != NULL){
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}

int main(){
    return 0;
}