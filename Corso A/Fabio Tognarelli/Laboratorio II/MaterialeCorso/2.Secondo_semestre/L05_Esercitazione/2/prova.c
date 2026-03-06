#include <stdio.h>
#include <stdlib.h>
#include <threads.h>

void sleep_ms(long ms){
    struct timespec ts;
    ts.tv_sec = ms / 1000;
    ts.tv_nsec = (ms % 1000) * 1000000;

    thrd_sleep(&ts, NULL);
}

int logger(void *arg){
    //cast
    int id = *(int *)arg;
    for ( int i = 0; i < 15; i++){
        printf("T[%d]: tick.\n", id);
        sleep_ms(200);
    }
    return 0;
}

int main(){
    thrd_t id;
    if(thrd_create(&id, logger, &id) != thrd_success){
        fprintf(stderr, "errore nella creazione del thread\n");
        return -1;
    }

    if(thrd_detach(id) != thrd_success){
        fprintf(stderr, "errore nella detach.");
    }

    if(thrd_join(id, NULL) != thrd_success){
        printf("Errore nel join del thread: %lu", id);
    }else{printf("join eseguito sul thread: %lu", id);}
    return 0;
}