# Part II: complete this Makefile.
# Requirements are given in the handout.

# After obtaining a successful build, run make a second time without modifying any files. Explain
# why nothing should be recompiled. Then modify only stats.c and run make; identify what is
# rebuilt. Finally, touch or modify stats.h and explain what should be rebuilt and why.
# You should understand the distinction between compiling a source file and linking object files
# into an executable. You do not need to use advanced Make features.

# After a successful build, the make would go through and see that nothing has changed. therefore no need to recompile.
# changing stats.c and recompiling would only touch stats.o and stats, keeping main.o the same as nothing needs to change there.

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
