CC = gcc
CFLAGS = -g -Wall

program: trie.c texteditor.c main.c main.o
	$(CC) $(CFLAGS) trie.c texteditor.c main.c -o textEdi

clean: rm*.o program
