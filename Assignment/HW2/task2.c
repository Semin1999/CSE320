/*
Name: Semin Bae
Email: semin.bae@stonybrook.edu
*/

#include <stdio.h>
#include <stdlib.h>

void sumAndAverage(int* pnt, int cnt, double** dst){

    /* Initalizes sum and average variables */
    double sum = 0.0;
    double average = 0.0;

    /* Add up the every pnt int values in to sum variables */ 
    for(int i = 0; i < cnt; i++){
        int pntValue = *(pnt + i);
        sum += pntValue;
    }

    /* Get average from sum and count */
    if(cnt > 0)average = sum/cnt;
    else average = 0;
    
    /* Use malloc to get dynamic memory allocate for two double return value */
    *dst = malloc(2 * sizeof(double));

    /* Store to the first element */
    **dst = sum;
    *(*dst+1) = average;

    /* Print sum and average from the memory address */
    printf("\nPrint in sumAndAverage function from memory address not the variables");
    printf("\nThe Sum in List Elements: %.2f \n", **dst);
    printf("\nthe Average in List Elements: %.2f \n", *(*dst+1));
}

void testMyFunction(){
    
    printf("Name: Semin Bae \nEmail: semin.bae@stonybrook.edu\n");

    /* Initialize count variable */
    int count = 0;

    /* scan the count variables until it positive number */
    do{
        printf("Enter the Positive Integer Count : ");
        scanf("%d", &count);
    }while(count <= 0);

    /* make dynamic allocated memory for the pointer */
    int* pointer = malloc(count * sizeof(int));

    /* scan the array elements to use for loops */
    printf("Enter %d number of Integers: ", count);
    for(int i = 0; i < count; i++){
        scanf("%d", &pointer[i]);
    }

    /* make dynamic allocated memory for the destination */
    double** destination = malloc(2 * sizeof(double));

    /* Function call */
    sumAndAverage(pointer, count, destination);

    /* Print sum and Average from testFunction */
    printf("Print sum and Average from testFunction");
    printf("The Sum in List Elements: %.2f \n", **destination);
    printf("the Average in List Elements: %.2f \n", destination+1);
}

int main(int argc, char** argv) {
    testMyFunction();
}