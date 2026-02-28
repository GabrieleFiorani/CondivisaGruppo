//Creare un numero N di Thread con una funzione, gli passa un ID e TempoAttesa


#include <threads.h>
#include <stdio.h>
#include <stdlib.h> 
#include <time.h>



int worker(void *arg){ 
    int id = (int *)arg;
    printf("T %d: start", id);

    printf("T %d: end", id);
}

int main(){

    for(int i = 0; i < N; i++){
        thrd_create(, worker, )
    }
}
