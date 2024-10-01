
#include <stdio.h>
#include "util.h"

/*
  lots more include thingies
  *
  *

  */
#include "util.h"

int main(int argc, char **argv) {
  int count;
  int myarray[] = {20, 4, 17, 101, 41, -3, 19};

  count = sizeof(myarray) / sizeof(int);
  printf("Count: %d\n", count);
  printf("Largest: %d\n", maxval(myarray, count));
  printf("Index of Largest: %d\n", maxidx(myarray, count));
  printf("Smallest: %d\n", minval(myarray, count));

  
}
