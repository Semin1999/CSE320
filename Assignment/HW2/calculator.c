/*
Name: Semin Bae
Email: semin.bae@stonybrook.edu
*/

#include <stdio.h>
/* include header what I made */
#include "math_operations.h"

int main() {
    printf("Name: Semin Bae \nEmail: semin.bae@stonybrook.edu\n");

    /* Initalize variables */
    int selectNubmer = 0;
    int num1 = 0;
    int num2 = 0;
    int result = 0;

    printf("**--Choose the number what you want to calculate--**\n1. Additional\n2. Substraction \n3. Multiplication\n4. Square\n5. Cube\n6. Square(Macro Function)\n7. Cube(Macro Function)\n");

    /* scan the select number until it between 1 ~ 7 */
    do{
        printf("Put the number here 1~7: ");
        scanf("%d", &selectNubmer);
    }while(selectNubmer > 7 || selectNubmer < 1);

    /* from selectnumber 4, it only needs 1 number variable */
    if(selectNubmer > 3){
        printf("Put a number: ");
        scanf("%d", &num1);   
    }
    else{
        printf("Put the two numbers: ");
        scanf("%d %d", &num1, &num2);   
    }

    /* use function to use switch and print it */
    switch (selectNubmer)
    {
    case 1:
        result = addition(num1, num2);
        printf("You get: %d + %d = %d\n", num1, num2, result);
        break;
    case 2:
        result = subtraction(num1, num2);
        printf("You get: %d - %d = %d\n", num1, num2, result);
        break;
    case 3:
        result = multiplication(num1, num2);
        printf("You get: %d x %d = %d\n", num1, num2, result);
        break;
    case 4:
        result = square(num1);
        printf("You get: %d^2 = %d\n", num1, result);
        break;
    case 5:
        result = cube(num1);
        printf("You get: %d^3 = %d\n", num1, result);
        break;
    case 6:
        result = SQUARE(num1);
        printf("You get: %d^2 = %d\n", num1, result);
        break;
    case 7:
        result = CUBE(num1);
        printf("You get: %d^3 = %d\n", num1, result);
        break;
    default:
        break;
    }

    return 0;
}
