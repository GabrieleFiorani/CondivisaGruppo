/**
 * *INDIPENDENZA DEI THREAD: se un thread-genitore cre un thread-figlio, quest'ultimo è slegato da dipendenze gerarchiche.
 * *Questo vuol dire che il thread-padre potrebbe morire prima che il figlio abbia finito
 */

#include <stdio.h>
#include <threads.h>

#define N 5 // numero di thread

//! se avessi dichiarato questa var dentro la func del thread-padre, avrei perso l'id con la terminazione del thread-padre stesso
thrd_t t_annidato;

//* funzione del thread creato nel thread
int thread_func_annidato(void *arg)
{
	printf("Entro nel Thread INTERNO\n");	
	thrd_sleep(&(struct timespec){.tv_sec=3}, NULL);	// dorme per 1 secondo mentre il suo thread-padre muore
	printf("Esco dal Thread INTERNO\n");	
	return thrd_success;		// ritorna il valore di successo
}


//* funzione passata al thread
int thread_func(void *arg)
{
	printf("Thread ESTERNO\n");			// stampa il nome del thread

	//* il thread crea un altro thread al suo interno
	thrd_create(		// crea un thread
		&t_annidato,		// id del thread
		thread_func_annidato,	// funzione del thread
		NULL			// argomento della funzione
	);

	// thrd_t ret = thrd_join(t_annidato, NULL);	
	// if (ret == thrd_success)				
	// 	printf("Thread con ID: %lu terminato correttamente.\n", t_annidato); 	
	// else
	// 	printf("Errore nel join del thread %lu\n", ret);

	printf("Esco dal Thread ESTERNO\n");
	return thrd_success;		// ritorna il valore di successo
}

int main()
{	
	thrd_t thread;		// array descrittori dei thread

	thrd_create(		// crea un thread
		&thread,		// id del thread
		thread_func,	// funzione del thread
		NULL			// argomento della funzione
	);
	
	//* fa join per aspettare conclusione del thread ESTERNO
	thrd_t ret = thrd_join(thread, NULL);	
	if (ret == thrd_success)				
		printf("Thread con ID: %lu terminato correttamente.\n", thread); 	
	else
		printf("Errore nel join del thread %lu\n", ret);
	

	//* vai in join per aspettare conclusione del thread INTERNO
	ret = thrd_join(t_annidato, NULL);	
	if (ret == thrd_success)				
		printf("Thread con ID: %lu terminato correttamente.\n", t_annidato); 	
	else
		printf("Errore nel join del thread %lu\n", ret);

	return 0;
}