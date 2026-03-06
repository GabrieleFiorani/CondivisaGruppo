#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

mtx_t m;
cnd_t cnd;
int *ris;

int thread_func(void *arg_){
    int idx = (int)(size_t)arg_;
    int valore_locale; // Variabile per la stampa sicura

    mtx_lock(&m);

    if(idx > 0){
        // Attesa condizionale: rilascia il mutex e aspetta il segnale
        while (ris[idx - 1] == 0){
            cnd_wait(&cnd, &m);
        }
    }
    
    // Calcolo della sequenza
    if (idx == 0) {
        ris[idx] = 1;
    } else {
        ris[idx] = (idx * idx) + ris[idx - 1];
    }

    valore_locale = ris[idx]; // Salvo il valore prima di rilasciare il lock

    cnd_broadcast(&cnd);
    mtx_unlock(&m);

    // Stampa sicura e non bloccante
    printf("Ris in posizione %d: %d\n", idx, valore_locale);
    
    return 0;
}

int main(int argc, char *argv[]){
    int N = argc > 1 ? atoi(argv[1]) : 6;
    
    if(mtx_init(&m, mtx_plain) != thrd_success || cnd_init(&cnd) != thrd_success){
        fprintf(stderr, "Errore nella dichiarazione del mutex / cnd\n");
        return -1;
    }

    thrd_t *threads = malloc((size_t)N * sizeof(thrd_t));
    ris = calloc((size_t)N, sizeof(int));

    if (!threads || !ris) return -1;

    for(int i = 0; i < N; i++){
        thrd_create(&threads[i], thread_func, (void *)(size_t)i);
    }

    for(int i = 0; i < N; i++){
        thrd_join(threads[i], NULL);
    }

    // Pulizia totale
    mtx_destroy(&m);
    cnd_destroy(&cnd);
    free(threads); // Aggiunto!
    free(ris);

    return 0;
}