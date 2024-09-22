# Name: Semin Bae
# Email: semin.bae@stonybrook.edu


# target: dependencies
#    command


# WRITE MAKEFILE ACCORDING WITH Professor's FILE(so can be very similar with the make file what we made in class).
CC=gcc
CFLAGS=-ggdb -O0
LDFLAGS=-ggdb
LDLIBS=-lm
QFLAG=-L/usr/lib/x86_64-linux-gnu -lm

all: assignment2 calculator

assignment2: assignment2.o math_operations.o
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)

calculator: calculator.o math_operations.o
	$(CC) $(LDFLAGS) $^ -o $@ $(LDLIBS)


assignment2.o: assignment2.c math_operations.h
calculator.o: calculator.c math_operations.h
math_operations.o: math_operations.c math_operations.h


clean:
	rm -f assignment2 calculator *.o
