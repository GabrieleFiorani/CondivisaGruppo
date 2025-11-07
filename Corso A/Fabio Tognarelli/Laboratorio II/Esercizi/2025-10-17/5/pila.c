//*ese 4 dell'esercitazione: IMPL.NE PILA CON FUNZIONI ASSOCIATE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

//*struttura nodo
typedef struct Node{
    int val;
    struct Node *next;
} Node;


//* push - inserisce un elemento nella pila 
void push(int x, Node **head){
    Node *new;
    new = (Node*)malloc(sizeof(Node));
    if(new == NULL){
        printf("Memoria non allocata");
        return;
    }
    new->val = x;       //* aggancia nodo prima della testa e riassegna la testa
    new->next = *head;
    *head = new;
    
    return;
}

//* -pop - rimuove il primo elemento dalla pila e lo ritorna. Deve tornare il valore 0 se la pila è vuota. 
int pop(Node **head){
    if(*head == NULL){
        return 0;
    }
    int ris = (*head)->val;

    Node* att = *head;      //*assegnazione della nuova testa e libero in mem 1 el
    *head = (*head)->next;
    free(att);
    

    return ris;
}

//* -peek - restituisce il valore del primo elemento della pila senza rimuoverlo. Deve tornare il valore 0 se la pila è vuota.
int peek(Node *head){
    if(head == NULL)
        return 0;
    else
        return head->val;
}

//* -length - calcola la lunghezza della pila in modo ricorsivo
int length(Node **head){
    if(*head == NULL){
        return 0;
    }
    return 1 + length(&(*head)->next);
}

//* -print - stampa gli elementi della pila , iniziando con l'elemento in testa (vedi esempio), in modo ricorsivo
void print(Node **head){
    if(*head == NULL){
        return;
    }
    
    printf("%d\n", (*head)->val);
    print(&(*head)->next);
}

int main(){

    int countZero = 0, val;
    Node *lis = NULL;
    

    while(true){
        printf("Inserisci valore: ");
        scanf("%d", &val);

        if(val != 0){       //* se non e' zero
            countZero = 0;
            if((val % 3) == 0){     //* se multiplo di 3
                val /= 3;
                push(val, &lis);
            }
            else{
                push(val, &lis);
            }
        }
        else{       //* se e' zero
            countZero++;
            if(countZero == 3){     //*se si leggono 3 zei si ferma il progr
                break;
            }
            int cont = peek(lis);
            int l = length(&lis);

            //* se ci sono 4 elementi o il primo valore e' divisibile
            if((cont % 2 != 0) || l > 3){
                pop(&lis);
            }
        }
        
    }
    printf("Valori in lista:\n");
    print(&lis);
    printf("\nLunghezza lista: %d\n",length(&lis));
    return 0;
}