
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

int sumarray(int count, ...) {
  va_list valist;
  int sum = 0;

  printf("Provided args: ");
  va_start(valist, count);
  for (int i = 0; i < count; i++) {
    printf("%d ", va_arg(valist, int));
  }
  printf("\n");
  va_end(valist);

  va_start(valist, count);
  for (int i = 0; i < count; i++) {
    sum += va_arg(valist, int);
  }
  va_end(valist);

  return sum;
}

int main(int argc, char **argv) {

  int result = sumarray(15, 5, 10, 15, 20, -2, -4, -6, -3, 11, 101, -12, 13, 14, 99, 78);
  printf("sum of 15 arguments: %d\n" , result);

  printf("Degenerate cases\n");
  printf("  Lower count:\n");
  result = sumarray(12, 5, 10, 15, 20, -2, -4, -6, -3, 11, 101, -12, 13, 14, 99, 78);
  printf("sum of 12 arguments: %d\n" , result);
  printf("  Higher count:\n");
  result = sumarray(20, 5, 10, 15, 20, -2, -4, -6, -3, 11, 101, -12, 13, 14, 99, 78);
  printf("sum of 20 arguments: %d\n" , result);


}
