#include <stdio.h>
#include <math.h>
#include <stdlib.h>


/*
make file 을 이용하여 header 와 o 파일등을 관리하고 빌드 할수 있다.
*/

void quads(int a, int b, int c, double **roots){
    *roots = (double *) malloc(sizeof(double) * 2);
    
    //  math lib
    double readical = sqrt((b*b) - (4*a*c));
    double denom = 2 * a;
    **roots = (-b + readical) / denom;
    *(*roots + 1) = (-b - readical)/denom;

}


int main(int argc, char **argv)
{
    //formular: ax^2 + bx + c

    double *roots;

    if(argc < 3)
    {    
        printf("Usage: quad a-coeff, b-coeff, c\n");
        exit(1);       
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int c = atoi(argv[3]);

    quads(a, b, c, &roots);

    printf("root 1: %10.2f, root 2: %100.2f\n", *roots);

    return 0;
}