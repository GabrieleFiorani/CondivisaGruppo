CC = gcc
CFLAGS = -Wall -pedantic -std=c11
NAME = main
LIBS = -lpthread
OBJS = $(NAME).o lista.o spinlock.o

.PHONY: default clean

default: $(NAME)


run: $(NAME)
	./$(NAME)

clean:
	rm -f $(NAME) $(OBJS)
