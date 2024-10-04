# Name: Semin Bae
# Email: semin.bae@stonybrook.edu

CC=gcc
CFLAGS=-ggdb -O0
LDFLAGS=-ggdb
LDLIBS=-lm
QFLAG=-L/usr/lib/x86_64-linux-gnu -lm

all: hw3_bits hw3_matmul hw3_struct_union_func

hw3_bits: hw3_bits.c
	$(CC) $(CFLAGS) -o hw3_bits hw3_bits.c

hw3_matmul: hw3_matmul.c
	$(CC) $(CFLAGS) -o hw3_matmul hw3_matmul.c

hw3_struct_union_func: hw3_struct_union_func.c
	$(CC) $(CFLAGS) -o hw3_struct_union_func hw3_struct_union_func.c

clean:
	rm -f hw3_bits.o hw3_matmul.o hw3_struct_union_func.o hw3_bits hw3_matmul hw3_struct_union_func