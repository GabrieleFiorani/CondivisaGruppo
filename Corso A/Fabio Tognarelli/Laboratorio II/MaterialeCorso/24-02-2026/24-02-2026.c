//? 24feb
//? UTILIZZO DEL TEMPO IN PROG. CONCORRENZIALE


/* 
Nella sincronizzazione il concetto di tempo e' molto importante.
Per alcune implementazioni specifiche (asincrone) il tempo è fondamentale.
*/

/* 
esempio del bagno per la spinlock: 
    la mutex/cond variable mettevano in sleep i thread in attesa di entrare in bagno

vogliamo provare a sfruttare i tempi morti per fare altro
*/


//qualche lezione fa: SPINLOCK -> operazioni atomiche per gestire flussi di esecuzione distinti un po' più complessi, ma perdeva un sacco di tempo
//mutex: lock per mutua esclusione di una variabile, per fare in modo di avere la garanzia di riservare le sezioni critiche, lasciando pero' a girarsi i pollici gli altri thread
//arriviamo alla try-lock

//? esempio 1: TRY-LOCK con fette di pizza

//lock: blocca a prescindere
//trylock: controlla se zona critica ccedibile: SI: accede; NO: fa altro


//* Lezione imparata: la trylock permette di gestire altri processi se una zona critica è temporaneamente occupata

//! Svantaggio: ci si riavvicina pesantemente alla spinlock quando i thread rifanno tentativi per provare ad accedere


// come risolvo questo problema?
//? ESEMPIO 2: MUTEX-TIMEWAITED
 
//provo ad ottenere la mutex per un deltaT, se non ottengo il mutex ritento
//* VANTAGGI:
//! SVANTAGGI: