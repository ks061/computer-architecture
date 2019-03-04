# Kartikeya Sharma
# February 19, 2019 @ 1 PM
# lab 06 - Makefile
# notes: This Makefile contains
#        make instructions for
#        C files related to
#        Lab 06.

# Definition of variable names
CC=gcc
CFLAGS=-Wall
ALL = collatz

# Directive to build all files if no
# arguments given with make
all: $(ALL)

# Instructions on generating collatz executable
collatz: collatz.o
	$(CC) $< -o $@

# Instructions on generating collatz object file
collatz.o: collatz.c
	$(CC) $(CFLAGS) -c $<

# Instructions on generating clean executable
clean:
	/bin/rm -f *~ *.o $(ALL)
