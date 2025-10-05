/*
Scrivere un programma che legga un carattere (+, -, *, /) e due numeri interi, e calcoli
l’operazione corrispondente ( usare switch )
*/
#include <stdio.h>

int main(){
    int a, b, ris;
    char op;

    printf("Inserisci simbolo operazionale: ");
    scanf("%c", &op);
    
    printf("Inserisci primo operando: ");
    scanf("%d", &a);
    
    printf("Inserisci secondo operando: ");
    scanf("%d", &b);

    switch(op){
        case '+':
            ris = a + b;
            printf("Il risultato e': %d\n", ris);
            break;

        case '-':
            ris = a - b;
            printf("Il risultato e': %d\n", ris);
            break;

        case '*':
            ris = a * b;
            printf("Il risultato e': %d\n", ris);
            break;

        case '/':
            ris = a / b;
            printf("Il risultato e': %d\n", ris);
            break;

        default:
            printf("Operando non valido!\n");
    }
    return 0;
}