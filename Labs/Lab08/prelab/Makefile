# Kartikeya Sharma
# March 5, 2019 @ 1 PM
# lab 08 - Makefile
# notes: This Makefile contains
#        make instructions for
#        C files related to
#        Lab 08.

# Definition of variable names
CC=gcc
CFLAGS=-Wall
ALL = snode_test

# Directive to build all files if no
# arguments given with make
 all: $(ALL)

# Instructions on generating snode object file
snode.o: snode.c snode.h
	$(CC) $(CFLAGS) -c $<

# Instructions on generating snode_test executable
snode_test: snode_test.o snode.o
	$(CC) $(CFLAGS) snode_test.o snode.o -o $@

# Instructions on generating snode_test object file
snode_test.o: snode_test.c snode.h
	$(CC) $(CFLAGS) -c $<

# Instructions on generating clean executable
clean:
	/bin/rm -f *~ *.o $(ALL)
