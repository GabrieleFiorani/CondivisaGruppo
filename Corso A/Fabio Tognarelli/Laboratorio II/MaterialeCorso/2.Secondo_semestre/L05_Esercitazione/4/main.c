//rifai l'esercizio di prima solo con var atomiche
#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <stdatomic.h>

atomic_int *ris;


int thread_func(void *arg){
    int idx = (int)(size_t)arg;

    while(idx > 0){
        if(ris[idx - 1] != 0) break;
    }

    if( idx == 0){
        atomic_store(&ris[idx], 1);
    }

    if(idx > 0){
        
        atomic_store(&ris[idx], ((idx+1) * (idx+1)) + atomic_load(&ris[idx - 1]));
    }

    return 0;
}



int main(int argc, char *argv[]){
    int N = argc > 1 ? atoi(argv[1]) : 6;

    thrd_t *threads = malloc((size_t)N * sizeof(thrd_t));
    ris = calloc((size_t)N, sizeof(atomic_int));

    for(int i = 0; i < N; i++){
        thrd_create(&threads[i], thread_func, (void*)(size_t)i);
    }

    for(int i = 0; i< N; i++){
        if(thrd_join(threads[i], NULL) != thrd_success){
            printf("errore nel join\n");
            return 1;
        }
    }
    for(int i = 0; i < N; i++){
        printf("Risultato in posizione %d: %d\n", i+1, atomic_load(&ris[i]));
    }

    free(threads);
    free(ris);
    return 0;

}
