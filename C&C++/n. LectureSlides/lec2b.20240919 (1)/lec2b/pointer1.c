
#include <stdio.h>
#include <stdlib.h>

void pointerArrays(void) {
  int myArray[] = {1, 2, 3, 4};

  for (int i = 0; i < sizeof(myArray)/sizeof(int); i++) {
    printf("%d ", myArray[i]);
  }
  
  printf("\n");

  printf("sizeof(myArray), sizeof(int): %ld, %ld\n", sizeof(myArray), sizeof(int));

  int arrayLength = sizeof(myArray)/sizeof(int);

  int *myPtr = myArray;   // myPtr has the address of myArray

  for (; myPtr < (myArray + arrayLength); myPtr++) {
    printf("%d ", *myPtr);
  }
  printf("\n");

  
}


int main(int argc, char **argv) {

  int *foo; // default is 0 or null ppointer

  // Test just setting foo to something
  // *foo = 15;

  int bar = 4;

  printf("Number pointer(not initialized): %p\n", foo);

  printf("foo before init: %d\n", *foo);

  // Options:
  // 1. set it to the address of a variable
  // 2. use malloc and then write values to it.
  foo = &bar;

  printf("Number pointer (pointing to bar): %p\n", foo);

  foo = (int *) malloc(sizeof(int));  

  printf("Number pointer (malloced): %p\n", foo);

  // Wrong!
  //  free(*foo);
  free (foo);

  pointerArrays();

}
