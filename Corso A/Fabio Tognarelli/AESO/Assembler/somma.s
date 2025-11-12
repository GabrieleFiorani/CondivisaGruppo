	.text				@ questo e' il segmento che contiente il programma (TEXT)
	.global main			@ main deve essere un identificatore disponibile anche al chiamante
	.type main, %function		@ main e' una funzione

main:	                		@ questo e' il nostro main, chiamato con r0 = argc, e r1 = &argv[0]
	ldr r0, =v 			@ indirizzo del vettore v in memoria
	mov r1, #0 			@ sum = 0
	mov r2, #0 			@ i = 0
	push {lr}			@ siccome "sporco" LR per chiamare la printf lo devo salvare sullo stack
					@ (LR ora contiene l'indirizzo di ritorno del main ....)
forloop:				@ e' la traduzione di: for(i=0; i<4; i++) sum += v[i]; 
	cmp r2, #4			@ i<4 ?
	beq finefor			@ se i=4 vuol dire che non e' minore di 4, dunque ho finito 
	ldr r3,[r0,r2,lsl #2]		@ carica v[i]: mem indirizzata a byte, indice = i*4 (sizeof(int)=4!)
	add r1,r1,r3			@ sum = sum + v[i]
	add r2,r2,#1			@ i++
	b forloop			@ prossima iterazione del for
finefor:				@ la somma e' in r1, la stampoi, e' gia' nel reg secondo param (r1)
	ldr r0, =fmt			@ carico in r0 l'indirizzo della stringa di formato
	bl printf			@ invoca la printf(r0,r1) dunque printf("risultato %d\n",123)
	        			@ quando il controllo ritorna, devo fare una return 
					@ dovrebbe essere una mov pc,lr se faccio una pop{pc} scrivo in PC
	pop {pc}			@ il valore di ritorno (LR) precedentemente salvato
	

	.data				@ sezione dati: non istruzioni assembler ma dati definiti con pseudo istr
fmt:	.string "Risultato %d\n"	@ .string : area di memoria che contiene la stringa ASCII che segue
v:	.word 1,2,3,4			@ .word : area di parole di memoria con i valori che seguono, separati da virg


