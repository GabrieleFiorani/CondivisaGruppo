/**
 * * DETATCH: quando un thread muore non scompare del tutto, ma viene "zombieficato":
 * * viene tenuto in memoria il suo stack ed il valore di ritorno, occupando spazio in 
 * * attesa che un altro thread (spesso il main thread) chiami la join su di lui per
 * * leggere il risultato e farlo scomparire del tutto. 
 * * ------------------------------------------------------------------------------
 * * thrd_detach(thread_id):
 * * 	Stai dicendo al Sistema Operativo: "questo thread deve fare un lavoro in
 * *	background. Non mi interessa sapere quando finirà e nemmeno del valore che 
 * * 	ritornerà. Appena ha finito, distruggi tutto in automatico e libera memoria 
 * * 	senza aspettare nessuno".
 * * ------------------------------------------
 * ? TIPS: 
 * ? 	- La detach su un thread è irreversibile
 * ? 	- La detach può essere fatta anche da un thread per conto suo: 
 * ? 		thrd_detach(thrd_current())
*/

#include <stdio.h>
#include <threads.h>
#include <stdbool.h>
#include <stdlib.h>

#define N 5 // numero di thread

int thread_func(void *arg)
{
	thrd_t id = thrd_current();					// recupera l'id del thread
	int tempo_rnd = 1 + (rand() % 4);			// genera un tempo casuale tra 1 e 4 secondi
	printf("Inizio Thread: %lu, resterà attivo " // stampa l'inizio del thread
			"per %d sec\n", id, tempo_rnd);			
	struct timespec ts = 						// imposta il tempo di attesa
		{ .tv_sec = tempo_rnd, .tv_nsec = 0 };	
	thrd_sleep(&ts, NULL);						// attende il tempo impostato
	printf("Fine Thread: %lu\n", id);			// stampa la fine del thread
	return thrd_success;						// ritorna il valore di successo
}

int main()
{
	thrd_t threads[N];		// array di thread

	for (int i = 0; i < N; i++)	
	{
		thrd_create(		// crea un thread
			&threads[i],	// id del thread
			thread_func,	// funzione del thread
			NULL			// argomento della funzione
		);

		printf("Thread %lu creato.\n", threads[i]);
		//? funzione per svuotare il buffer di output e scrivere sul dispositivo di output
		fflush(stdout);
		// imposta il thread come detached; il thread non deve essere esplicitamente terminato; il sistema operativo si occupa di liberare le risorse allocate
		thrd_detach(threads[i]);	
	}

	for (int i = 0; i < N; i++)
	{
		int ret = thrd_join(threads[i], NULL);	// attende la terminazione del thread i
		if (ret == thrd_success)				//! join che falliranno poichè detached
			printf("Thread %lu terminato correttamente.\n", threads[i]); 	
		else
			printf("Errore nel join del thread %lu\n", threads[i]);
	}
	
	printf("Termine Programma.\n");
	return 0;
}