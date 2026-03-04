#include <stdio.h>
#include <stdlib.h>
#include <threads.h>


//var globali
static long counter = 0;
mtx_t m;

typedef struct {
    int tid;            //id del thread
    int iters;          //numero di iterazioni da eseguire
    int use_mutex;      //flag per uso del mutex
} arg_t;

int inc_worker(void* arg_){

    arg_t *arg = (arg_t*)arg_;
    for(long i = 0; i < arg->iters; i++){
        if(arg->use_mutex == 1){
            mtx_lock(&m);
            counter++;
            mtx_unlock(&m);
        }
        else counter++;
    }
    return 0;
}

int main(int argc, char *argv[]){
    
    int T = argc > 1 ? atoi(argv[1]) : 4;
    long K = argc > 2 ? atol(argv[2]) : 1000000;
    int use_mutex = argc > 3 ? atoi(argv[3]) : 1;

    if(use_mutex){
        if(mtx_init(&m, mtx_plain) != thrd_success){
            printf("Errore di inizializzazione del mutex\n");
            return 1;
        }
    }

    thrd_t *threads = malloc((size_t)T * sizeof(thrd_t));
    arg_t  *args = malloc((size_t)T * sizeof(arg_t));
    if (!threads || !args) return 2;

    for(int i = 0; i < T; i++){
        args[i].tid = i;
        args[i].iters = K;
        args[i].use_mutex = use_mutex;
        if(thrd_create(&threads[i], inc_worker, &args[i]) != thrd_success){
            fprintf(stderr, "Errore nella creazione del thread\n");
        }
    }

    for(int i = 0; i < T; i++){
        if(thrd_join(threads[i], NULL) != thrd_success){
            printf("Errore nel join del thread %d\n", args[i].tid);
        }
    }

    long ris = T * K;
    printf("T=[%d] K=[%ld] expected=[%ld] got=[%ld] (mutex=[%d]\n", T, K, ris, counter, use_mutex);
    
    if(use_mutex) mtx_destroy(&m);
    free(threads);
    free(args);
    return 0;
}