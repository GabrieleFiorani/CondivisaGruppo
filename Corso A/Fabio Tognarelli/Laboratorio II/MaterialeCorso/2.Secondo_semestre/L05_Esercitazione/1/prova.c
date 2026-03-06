#include <stdio.h>
#include <stdlib.h>
#include <threads.h>


typedef struct  {
    int id;
    int ms;
} thread_arg_t;



int thread_func(void *arg_){
    thread_arg_t *arg = (thread_arg_t *)arg_;
    struct timespec ts;
    ts.tv_sec = arg->ms / 1000;
    ts.tv_nsec = (arg->ms % 1000) * 1000000;

    printf("Thread[%d]: start\n", arg->id);

    thrd_sleep(&ts, NULL);
    
    printf("Thread[%d]: end\n", arg->id);
    return arg->id * 10;
}

int main(int argc, char *argv[]){
    int N;
    if (argc > 1){
        N = atoi(argv[1]);
    }
    else N = 4;

    thrd_t *threads = malloc((size_t)N * sizeof(thrd_t));
    thread_arg_t *args = malloc((size_t)N * sizeof(thread_arg_t));

    for(int i = 0; i < N; i++){
        args[i].id = i;
        args[i].ms = 100 + (i * 150);

        if(thrd_create(&threads[i],thread_func, &args[i]) != thrd_success){
            printf("Errore durante la creazione del thread %d\n", i);
            return 1;
        }
    }
        for(int i = 0; i < N; i++){
            int res;
            if(thrd_join(threads[i], &res) != thrd_success){
                printf("Errore del join per il thread %d\n", i);
            }else{
                printf("joined T[%d] -> rc=[%d]\n", args[i].id, res);
            }
        }
    
    printf("All joined\n");
    free(threads);
    free(args);

    return 0;
}