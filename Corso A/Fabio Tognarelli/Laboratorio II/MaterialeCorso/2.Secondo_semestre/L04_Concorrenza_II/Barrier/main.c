/* 	
	Questo programma mostra come realizzare una barrier utilizzando
	le variabili di condizione di C11.
	SOLDONI: la barriera stoppa i thread arrivati ad un certo punto, finchè non sono
	tutti arrivati proprio a quel punto
*/

#include <stdio.h>
#include <stdlib.h>
#include <threads.h>
#include <stdatomic.h>
#include <time.h>

#define N 5

int count = 0;
mtx_t mtx;		//*VARIABILE DI MUTEX: chiave per accedere a sezione critica
cnd_t cnd;		//*CONDITION VARIABLE PER IL MUTEX: addormenta i thread

int barrier() {
	mtx_lock(&mtx); // <-- acquisisco il mutex per modificare la variabile count
	count++;
	if (count == N) { //* <-- se il thread e' l'ultimo ad arrivare
		count = 0;
		cnd_broadcast(&cnd);		//manda segnale di sveglia a tutti gli altri thread
		mtx_unlock(&mtx);			//sblocca il mutex
		return 1;
	} else {
		//*se thread NON e' l'ULTIMO che arriva, fa un wait
		cnd_wait(&cnd, &mtx);		//wait sul thread e rilascia mutex
		mtx_unlock(&mtx);			//sblocca il mutex
		return 0;
	}
}

//* funzione che mette in wait con la barrier per mettere ogni thread allo stesso
int calcetto(void *arg) {
	int id = *(int *)arg;
	int tempo_attesa = rand()%5;

	printf("Thread %d: inizio, aspetterò per %d secondi\n", id, (tempo_attesa+1));
	thrd_sleep(&(struct timespec){.tv_sec=(tempo_attesa+1)}, NULL);
	printf("Thread %d: sono arrivato alla barrier\n", id);
	barrier();
	printf("Thread %d: fine\n", id);
	return 0;
}

int main() {
	thrd_t threads[N];
	mtx_init(&mtx, mtx_plain);
	cnd_init(&cnd);

	int ids[N];

	for (int i = 0; i < N; i++) {
		ids[i] = i;
		thrd_create(&threads[i], calcetto, (int *)&ids[i]);
	}
	//join per il main thread
	for (int i = 0; i < N; i++) {
		thrd_join(threads[i], NULL);
	}
	cnd_destroy(&cnd);
	mtx_destroy(&mtx);
	return 0;
}