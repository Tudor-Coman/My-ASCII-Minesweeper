CC=gcc
CFLAGS=-Wall -g
LDFLAGS=-lcurses

.PHONY: build run

build:
	$(CC) $(CFLAGS) src/*.c -o bin/Minesweeper $(LDFLAGS) 

run: build
	./bin/Minesweeper
