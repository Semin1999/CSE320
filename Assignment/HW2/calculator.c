/*
Name: Semin Bae
Email: semin.bae@stonybrook.edu
*/

#include <stdio.h>
#include "math_operations.h"

int main() {
    printf("Name: Semin Bae \nEmail: semin.bae@stonybrook.edu\n");

    int selectNubmer = 0;
    int num1 = 0;
    int num2 = 0;
    int result = 0;

    printf("**--Choose the number what you want to calculate--**\n1. Additional\n2. Substraction \n3. Multiplication\n4. Square\n5. Cube\n");

    do{
        printf("Put the number here 1~5: ");
        scanf("%d", &selectNubmer);
    }while(selectNubmer > 5 || selectNubmer < 1);

    if(selectNubmer == 4){
        printf("Put a number: ");
        scanf("%d", &num1);   
    }
    else{
        printf("Put the two numbers: ");
        scanf("%d %d", &num1, &num2);   
    }

    switch (selectNubmer)
    {
    case 1:
        result = addition(num1, num2);
        printf("The addition of %d and %d is %d\n", num1, num2, result);
        break;
    case 2:
        result = subtraction(num1, num2);
        printf("The subtraction of %d and %d is %d\n", num1, num2, result);
        break;
    case 3:
        result = multiplication(num1, num2);
        printf("The multiplication of %d and %d is %d\n", num1, num2, result);
        break;
    case 4:
        result = square(num1);
        printf("The square of %d is %d\n", num1, result);
        break;
    case 5:
        cube(num1, num2);
        printf("The cube of %d of %d is %d\n", num1, num2, result);
        break;
    default:
        break;
    }

}
