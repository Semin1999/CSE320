/*
Name: Semin Bae
Email: semin.bae@stonybrook.edu
*/

#include "math_operations.h"

typedef int (*myFunction) (int, int);

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

int cube (int a, int b){
    int returnValue = 1;
    for(int i = 0; i < b; i++){
        returnValue = returnValue * a;
    }
    return returnValue;
}