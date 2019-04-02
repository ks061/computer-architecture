# Kartikeya Sharma
# February 5, 2019 @ 1 PM
# lab 04 - Makefile
# notes: This Makefile contains
#        make instructions for
#        C files related to
#        Lab 04.

# Definition of variable names
CC=gcc
CFLAGS=-Wall -g
ALL = head2 head3 string_token

# Directive to build all files if no
# arguments given with make
all: $(ALL)

# Instructions on generating head2 executable
head2: head2.o fileio.o
	$(CC) head2.o fileio.o -o $@

# Instructions on generating head2 object file
head2.o: head2.c fileio.h
	$(CC) $(CFLAGS) -c $<

# Instructions on generating head3 executable
head3: head3.o fileio.o
	$(CC) head3.o fileio.o -o $@

# Instructions on generating head3 object file
head3.o: head3.c fileio.h
	$(CC) $(CFLAGS) -c $<

# Instructions on generating fileio object file
fileio.o: fileio.c fileio.h
	$(CC) $(CFLAGS) -c $<

# Instructions on generating string_token executable
string_token: string_token.o fileio.o
	$(CC) string_token.o -o $@

# Instructions on generating string_token object file
string_token.o: string_token.c fileio.h
	$(CC) $(CFLAGS) -c $<

# Instructions on generating clean executable
clean:
	/bin/rm -f *~ *.o $(ALL)
