
#include <stdio.h>
#include <stdlib.h>

void buildDataStructure() {
  char *data1 = (char *) 0;
  char *data2 = (char *) 0;
  char *data3 = (char *) 0;
  char *data4 = (char *) 0;
  long size1 = 100;
  long size2 = 15;
  long size3 = 99999999999;
  long size4 = 100;

  do {
    data1 = (char *) malloc(size1);
    if (data1 == 0) break;
    data2 = (char *) malloc(size2);
    if (data2 == 0) break;
    data3 = (char *) malloc(size3);
    if (data3 == 0) break;
    data4 = (char *) malloc(size4);
    if (data4 == 0) break;
  } while (0);
  printf("Freeing memory.\n");
  printf("printers: %p %p %p %p\n", data1, data2, data3, data4);
  
  if (data1 != 0) {
    printf("Freeing data1\n");
    free(data1);
  }
  if (data2 != 0) {
    printf("Freeing data2\n");
    free(data2);
  }
  if (data3 != 0) {
    printf("Freeing data3\n");
    free(data3);
  }
  if (data4 != 0) {
    printf("Freeing data4\n");
    free(data4);
  }

}


int main(int argc, char **argv) {
  buildDataStructure();
  printf("Done.");
}
