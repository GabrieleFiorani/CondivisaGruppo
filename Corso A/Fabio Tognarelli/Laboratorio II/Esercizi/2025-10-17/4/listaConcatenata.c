
#include <stdio.h>
#include <stdlib.h>

//*struttura della lista
typedef struct Node{
    int data;
    struct Node* next;
} Node;


//*FUNZIONI PER MODIFICARE LA LISTA
//*STAMPA tutti gli elementi della lista L, uno per riga, RICORSIVAMENTE
void print(Node* head){
    if(head == NULL){
        return;
    }
    printf("%d\n", head->data);
    print(head->next);
    return;
}

//*INSERISCE l’elemento x in coda alla lista L ( nota: NON RICORSIVA )
Node *insert(int x, Node* L){

    Node *att, *new;
    att = L;

    new = (Node*)malloc(sizeof(Node));

    new->data = x;
    new->next = NULL;

    if(L == NULL){
        L = new;
        return L;
    }

    while(att->next != NULL){
        att = att->next;
    }

    att->next = new;
    
    return L;
}


//*INSERISCE x in coda RICORSIVAMENTE   
void insertRic(int x, Node **head){
    //*caso b
    if(*head == NULL){
        //*crezione nuovo nodo
        Node *new = (Node*)malloc(sizeof(Node));
        
        if(new == NULL){      //*se mem heap piena e non ha allocato nulla
            exit(1);
        }

        new->data = x;         //*assegnazione valori
        new->next = *head;
        *head = new;
        return;
    }
    
    insertRic(x, &((*head)->next));
}


//*ELIMINA dalla lista L l'ultimo elemento NON RICORSIVAMENTE
void deleteNode(Node **head){
   
    //*se lista vuota
    if(*head == NULL){
        return;
    }

    //*nodi che puntano a pos precedente ed attuale per avere ancora nella lista
    Node* att = *head;
    
    //*lista con un elemento
   if((*head)->next == NULL){
        free(*head);
        *head = NULL;
        return;
   }

    //*scorrimento indirizzi memoria per arrivare in fondo alla lista
    while(att->next->next != NULL){
        att = att->next;
    }

    //*stacco ultimo nodo liberando la mem allocata ad esso
    free(att->next);
    att->next = NULL;
    
}


int main(){
    int val;
    int i = 0;
    Node* lis = NULL;


    printf("Inserire gli elementi:\n");
    do{
        scanf("%d", &val);

        if (i % 2){
            insertRic(val, &lis);
        }
        else{
            insert(val, lis);
        }
    } while (val >= 0);

    print(lis);
    
    while(lis != NULL){
        deleteNode(&lis);
    }
}