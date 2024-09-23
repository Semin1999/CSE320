/*
Name: Semin Bae
Email: semin.bae@stonybrook.edu
*/

/* include header */
#include "math_operations.h"

/* Make typedef function which takes two int and return single int */
typedef int (*myFunction) (int, int);

/* Make simple Function for addition, subtraction, multiplication, square, cube */
int addition (int a, int b){
    return a + b;
}

int subtraction (int a, int b){
    return a - b;
}

int multiplication (int a, int b){
    return a * b;
}

int square (int a){
    return a*a;
}

int cube (int a){
    return a*a*a;
}