
#include <stdio.h>

int main(int argc, char **argv) {
  int a;
  int b;

  printf("Enter 2 integers: " );
  scanf("%d %d\n", &a, &b);
  printf("a,b: %d, %d\n", a, b);

  a = a ^ b;
  b = b ^ a;
  a = a ^ b;

  printf("a,b: %d, %d\n", a, b);

  


}
