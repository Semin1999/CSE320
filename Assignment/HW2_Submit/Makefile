# Name: Semin Bae
# Email: semin.bae@stonybrook.edu

# target: dependencies
#    command

# same settings with lecture class
CC=gcc

CFLAGS=-ggdb -O0
# LDFLAGS=-ggdb -lm --verbose
LDFLAGS=-ggdb
LDLIBS=-lm
QFLAG=-L/usr/lib/x86_64-linux-gnu -lm

# the file build that all I need is assignment2
all: assignment2

# assignment 2 needs assignment2.o calculator.o math_operations.o
assignment2: assignment2.o calculator.o math_operations.o

# clean assignment2 files and following .o programs
clean:
	rm -f assignment2.o calculator.o math_operations.o assignment2
