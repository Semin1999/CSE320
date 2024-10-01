
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void collectData(char *buffer, int maxlength) {
  char *longString = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
  strncpy(buffer, longString, maxlength);
  return;
}

void collectDataWithAllocate(char **buffer, int maxlength) {
  char *longString = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyz";
  *buffer = (char *) malloc(maxlength);
  strncpy(*buffer, longString, maxlength);
  return;
}

int countmatches(char **envp, char *search) {
  char **ep = envp;
  int slen = strlen(search);
  int cnt = 0;
  while ((*ep != 0) && (**ep != 0)) {
    if (strncmp(*ep, search, slen) == 0) {
      cnt++;
    }
    ep++;
  }
  return cnt;
}

int find(char **envp, char *search, char ***matching) {

  char **ep = envp;
  int slen = strlen(search);
  int cnt = 0;

  // figure out how many things match
  cnt = countmatches(envp, search);

  // Allocate memory
  *matching = (char **) malloc((cnt+1) * sizeof(char *));
  char **eptr = *matching;
  int ecnt = 0;

  // do search
  while ((*ep != 0) && (**ep != 0)) {
    if (strncmp(*ep, search, slen) == 0) {
      *eptr = (char *) malloc(strlen(*ep));
      strncpy(*eptr, *ep, strlen(*ep));
      ecnt++;
      eptr++;
    }
    ep++;
  }

  return ecnt;

}

int main(int argc, char **argv, char **envp) {
  // Collect data where caller gives the return buffer

  char Mybuffer[80];
  char *ptr2mybuffer = Mybuffer;

  collectData(ptr2mybuffer, 79);

  Mybuffer[79] = 0;
  printf("Mybuffer: %s\n", Mybuffer);
  
  // Collect data where callee allocates the return buffer
  char *myAllocBuf;
  collectDataWithAllocate(&myAllocBuf, 79);
  *(myAllocBuf + 79) = 0;

  printf("myAllocBuf: %s\n", myAllocBuf);

  //
  // Search environment variables
  //
  char **env_strings;

  printf("Num SSH strings: %d\n", countmatches(envp, "SSH"));

  int foundcount = find(envp, "SSH", &env_strings);

  char **next = env_strings;
  char *ep = *next++;

  printf("Matching env entries:\n");
  if (foundcount > 0) {
    while (ep != 0) {
      printf("   %s\n", ep);
      ep = *next++;
    }
  }
  printf("Done.\n");
}
