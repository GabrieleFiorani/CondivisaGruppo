//* dato r e pi, stampa circonferenza ed area del cerchio
#include <stdio.h>

int main(){
    double pi = 3.1415;
    float r;

    printf("Inserire raggio del cerchio: ");
    scanf("%f", &r);

    printf("Circonferenza: %f\n", 2*pi*r);
    printf("Area: %f\n", r*r*pi);   //*volendo con libreria ci può essere anche la funzione di potenza

    return 0;
}