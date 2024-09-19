
# target: dependencies
#    command

CC=gcc

CFLAGS=-ggdb -O0
# LDFLAGS=-ggdb -lm --verbose
LDFLAGS=-ggdb
LDLIBS=-lm

QFLAG=-L/usr/lib/x86_64-linux-gnu -lm

all: myapp arglist quad test

myapp: myapp.o util.o

arglist: arglist.o

quad: quad.o
	$(CC) $(LDFLAGS) quad.o -o quad $(LDLIBS)

test: test.o

myapp.o: myapp.c util.h

util.o: util.c

test.o: test.c

arglist.o: arglist.c

clean:
	rm myapp arglist quad test *.o
