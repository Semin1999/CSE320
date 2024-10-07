#include <stdio.h>
#include <stdlib.h>


int maxval(int theArray[], int count) {
  int max;
  int i;

  if (theArray == 0) {
    printf("Bad argument!\n");
    exit(1);
  }
  max = theArray[0];  
  for (i = 1; i < count; i++) {
    if (max < theArray[i]) {
      max = theArray[i];
    }
  }
  return max;
}

int minval(int theArray[], int count) {
  int min;
  int i;

  if (theArray == 0) {
    printf("Bad argument!\n");
    exit(1);
  }
  min = theArray[0];  
  for (i = 1; i < count; i++) {
    if (min > theArray[i]) {
      min = theArray[i];
    }
  }
  return min;
}

int maxidx(int theArray[], int count) {
  int max;
  int i;
  int midx;

  if (theArray == 0) {
    printf("Bad argument!\n");
    exit(1);
  }
  max = theArray[0];  
  midx = 0;
  for (i = 1; i < count; i++) {
    if (max < theArray[i]) {
      max = theArray[i];
      midx = i;
    }
  }
  return midx;
}
