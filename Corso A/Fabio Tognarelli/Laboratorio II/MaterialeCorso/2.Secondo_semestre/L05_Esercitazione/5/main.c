#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <stdatomic.h>

#define N_THREADS 4
int biglietti = 50;
atomic_flag lock = ATOMIC_FLAG_INIT;

void spinlock(atomic_flag *lock){
    atomic_flag_test_and_set(lock);
}

void spinunlock(atomic_flag *lock){
    atomic_flag_clear(lock);
}

int thread_func(void *arg){

    
    thrd_t *id = (thrd_t*)arg;
    spinlock(&lock);
    printf("Sono il thread %lu e sto acquistano il biglietto: %d", &id, biglietti);
    biglietti--;
    spinunlock(&lock);

    return 0;

}


int main(){

    thrd_t *threads = malloc((size_t)N_THREADS * sizeof(thrd_t));

    for ( int i = 0; i < N_THREADS; i++ ){
        thrd_create(&threads[i], thread_func, &threads[i]);
    }

    for(int i = 0; i < N_THREADS; i++){
        if(thrd_join(threads[i], NULL) != thrd_success){
            printf("errore nel join\n");
            return 1;
        }
    }

    free(threads);
    return 0;
}