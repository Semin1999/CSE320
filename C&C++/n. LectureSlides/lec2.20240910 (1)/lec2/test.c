
#include <stdio.h>
int main (int argc, char ** argv) {
  int a = 5;
  int b = 10;

  //  int c = a--b;   // Nope
  int c = a- -b;

  printf("c: %d\n", c);

}
