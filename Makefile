CC=gcc
CFLAGS=-I.
DEPS=tokenizer.h
OBJ=tokenizer.o tok.o 

tokenizer.c: tokenizer.re
	re2c -o $@ $<

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

tok: $(OBJ)
	gcc -o $@ $^ $(CFLAGS)

all: tok
