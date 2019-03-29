CFLAGS = -Wall -g
CC     = gcc
LIB    =
SRC    = bitlib.c tester.c
OBJ    = bitlib.o tester.o
HDR    = bitlib.h
SRC    = arithm.c bitlib.c tester.c
OBJ    = arithm.o bitlib.o tester.o
HDR    = arithm.h
EXE    = tester

all: $(EXE)

%.o: %.c $(HDR)
	$(CC) -c $(CFLAGS) $<
tester: $(OBJ)
	$(CC) -o $@ $(LFLAGS) $(OBJ) $(LIB)

clean:
	/bin/rm -f core *.o $(EXE) *~

