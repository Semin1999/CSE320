#!/bin/bash

make

echo ""
echo "Name: Semin Bae (114730530)"
echo "Email: semin.bae@stonybrook.edu"

echo ""
echo "-- Task1: hw3_bits.c --"
./hw3_bits

echo ""
echo "-- Task2: hw3_matmul.c --"
./hw3_matmul

echo ""
echo "-- Task3: hw3_struct_union_func.c --"
./hw3_struct_union_func

make clean # run once