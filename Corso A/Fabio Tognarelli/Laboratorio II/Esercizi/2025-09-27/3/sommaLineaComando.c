//*somma valori in linea di comando
#include <stdio.h>
#include <stdlib.h>

int main( int argc, char *argv[]){
    int ris = 0;
    int i;
    for(i = 0; i < argc; i++){  //*cicla sulla length degli argomenti
        ris += atoi(argv[i]);   //*casta la stringa in intero e somma il parametro al risultato
    }
    printf("Risultato: %d\n", ris);
    return 0;
}