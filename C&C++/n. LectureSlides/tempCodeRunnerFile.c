#include <stdio.h>

double average(double a, double b);

int main()
{
    double a, b;
    printf("Enter the Two int number: ");
    scanf("%lf %lf", &a, &b);
    double mean = average(a, b);

    prinf("\n the Mean value for %.2f and %.2f is %.2f\n", a, b, mean);

    return 0;
}


double average(double a, double b)
{
    return (a + b) / 2;
}