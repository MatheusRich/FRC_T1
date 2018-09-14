BINFOLDER := bin/
INCFOLDER := inc/
SRCFOLDER := src/
OBJFOLDER := obj/

CC := gcc
CFLAGS := -Wall
SERVERSRCFILES := $(wildcard src/base.c src/server.c)
CLIENTSRCFILES := $(wildcard src/base.c src/client.c)

server: $(SERVERSRCFILES:src/%.c=obj/%.o)
	$(CC) $(CFLAGS) obj/*.o -o bin/binary

client: $(CLIENTSRCFILES:src/%.c=obj/%.o)
	$(CC) $(CFLAGS) obj/*.o -o bin/binary

obj/%.o: src/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I./inc

.PHONY: clean
clean:
	rm -rf obj/*
	rm -rf bin/*
	rm -rf *.o

run:
	bin/binary
