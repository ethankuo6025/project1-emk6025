# Part II: complete this Makefile.
# Requirements are given in the handout.

CC = gcc
CFLAGS = -Wall -Wextra -g

# TODO: default target 'stats'
stats: main.o stats.o
	$(CC) $(CFLAGS) main.o stats.o -o stats

# TODO: rules for main.o and stats.o with correct header dependencies

stats.o: stats.c stats.h
	$(CC) $(CFLAGS) -c stats.c

main.o: main.c stats.h
	$(CC) $(CFLAGS) -c main.c

# TODO: clean target

clean:
	rm -f stats stats.o main.o

.PHONY: clean
