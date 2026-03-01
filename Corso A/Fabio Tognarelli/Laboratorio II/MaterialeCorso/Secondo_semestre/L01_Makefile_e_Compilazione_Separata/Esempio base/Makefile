#* Makefile per compilazione separata di un progetto C
#* Variabili
CC = gcc
CFLAGS = -Wall -pedantic
OBJECTS = main.o utils.o

#* Regole
all: main			#* Regola predefinita per compilare tutto

main: $(OBJECTS)	#* Regola per creare l'eseguibile main a partire dagli oggetti
	$(CC) $(CFLAGS) -o main $(OBJECTS)

main.o: main.c utils.h	#* Regola per compilare main.o a partire da main.c e utils.h
	$(CC) $(CFLAGS) -c $<

utils.o: utils.c utils.h	#* Regola per compilare utils.o a partire da utils.c e utils.h
	$(CC) $(CFLAGS) -c $<

#* Regola per pulire i file oggetto e l'eseguibile
clean:
	rm -f $(OBJECTS) main

#* Regola per eseguire il programma
run: main
	./main
