/**
 * *FUNZIONAMENTO DELLE VAR ATOMICS:
 * *	garantiscono che l'accesso e la modicìfica della var in questione non sia 
 * *	divisibile, ma venga eseguito in modo atomico.
 * *	In questo modo si evita la "Condition race", evitando che la modifica della var 
 * *	sia fatta contemporaneamente da piu' thread e creare quindi un errore 
 * *	nall'aggiornamento del dato.	
 * *	Gli ERRORI, come si vede runnando il codice, possono comportare PERDITA DI INFORMAZIONI 
 */

#include <stdio.h>
#include <threads.h>
#include <stdatomic.h>

atomic_int atomic_value = 0;
int value = 0;

//* funzione che incrementa con n thread una var atomica e una non atomica 
int thread_func(void *arg)
{
	for (int i = 0; i < 1000000; i++)
	{
		atomic_value++;
		value++;
	}

	return 0;
}

int main()
{
	//creazione array di thread 
	const int N = 5;
	thrd_t threads[N];
	int thread_ids[] =	{0, 1, 2, 3, 4}; //val delle funzioni assegnate ai thread

	for (int i = 0; i < N; i++)
	{
		thrd_create(
			&threads[i],
			thread_func,
			&thread_ids[i]
		);
	}

	//tentativo di join sui thread
	for (int i = 0; i < N; i++)
	{
		int ret = thrd_join(threads[i], NULL);
		if (ret == thrd_success)
		{
			printf("Thread %d terminato correttamente.\n", i);
		}
		else
		{
			printf("Errore nel join del thread %d\n", i);
		}
	}

	//* DIFFERENZA di valore tra VAR ATOMICA e VAR NON ATOMICA
	printf("Valore finale variabile non atomica: %d\n", value);
	printf("Valore finale variabile atomica: %d\n", atomic_value);

	printf("Termine.\n");
	return 0;
}