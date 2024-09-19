
#include <stdio.h>
int main(int argc, char **argv) {
  // **argv => Double pointer
  // argv => arg 0 pointer => 'program name'
  //         arg 1 pointer => 'arg 1'
  //         ...
  //         arg n pointer
  //         0
  // argc = n

  for (int i = 0; i < argc; i++) {
    // argv[x], * to string for argument x.
    printf("%d: %s\n", i, argv[i]);
  }

  int foo = 15;
  double bar = 3.14159;
  char *mySentence = "This is a sentence to test printf.";

  printf("Here is the data: \n  %d\n   %10.2f\n  %s\n", foo, bar, mySentence);

  int inputFromUser = 0;
  printf("Enter an integer: ");
  // Bad  will try to write to addr 0
  //  scanf("%d", intputFromUser);

  scanf("%d", &inputFromUser);

  printf("Entered value: %d\n", inputFromUser);

  char buffer[256];
  char buffer2[256];

  printf("Enter some words: " );
  scanf("\n%[^\n]", buffer2);

  printf("String 2: %s\n", buffer2);
  
}
