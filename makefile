#Henrique e Leon

CFLAGS = -Wall -lm -lmatheval

objects = funcoes.o utils.o gauss.o

all: ep02

ep02: ep02.c $(objects)
	gcc ep02.c -o ep02 $(objects) $(CFLAGS)

gauss.p: gauss.c gauss.h
	gcc -c gauss.c $(CFLAGS)

funcoes.o: funcoes.c funcoes.h
	gcc -c funcoes.c $(CFLAGS)

utils.o: utils.c utils.h
	gcc -c utils.c

debug: CFLAGS += -g
debug: all

purge: clean
	-rm -f ep02
clean:
	-rm -f $(objects)
