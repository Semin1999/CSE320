
/* quad => quadratic roots */

#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void quads(int a, int b, int c, double **roots) {
  *roots = (double *) malloc(sizeof(double) * 2);

  // math library gives us sqrt()
  double radical = sqrt((b*b) - (4 * a * c));
  double denom = 2 * a;
  **roots = (-b + radical) / denom;
  *(*roots + 1) = (-b - radical) / denom;
}


int main(int argc, char **argv) {
  // ax^2+bx+c

  double *roots;
  
  if (argc < 3) {
    printf("Usage: quad a-coeff, b-coeff, c\n");
    exit(1);
  }

  int a = atoi(argv[1]);
  int b = atoi(argv[2]);
  int c = atoi(argv[3]);

  quads(a, b, c, &roots);
  printf("root 1: %10.2f, root 2: %10.2f\n", *roots, *(roots + 1));

}
