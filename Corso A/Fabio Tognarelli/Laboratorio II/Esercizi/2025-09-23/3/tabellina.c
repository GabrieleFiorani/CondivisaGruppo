
//* calcola la tabellina di un dato numero intero n
#include <stdio.h>

int main(){
    int n;
    int i = 0;

    printf("Inserisci il numero per la sua tabellina: ");
    scanf("%d", &n);

    for(i = 0; i <= 10; i++){
        int parz = n * i;
        printf("%d * %d: %d\n", n, i, parz);
    } 
    return 0;
}