/*
Name: Semin Bae
Email: semin.bae@stonybrook.edu
*/

/* Include guard */
#ifndef MATH_OPERATIONS
#define MATH_OPERATIONS

/* Define Macro Functions */
#define SQUARE(a) (a * a)
#define CUBE(a) (a * a * a)

/* Define header function to use typedef */
typedef int (*myFunction) (int, int);

/* Define Functions that implemented in math_operations.c */
int addition(int a, int b);
int subtraction(int a, int b);
int multiplication(int a, int b);
int square(int a);
int cube(int a);

#endif
