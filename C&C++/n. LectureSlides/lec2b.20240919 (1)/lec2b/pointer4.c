
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

void getWholeFile(int fd, char **buffer, int *length) {
  *buffer = (char *) malloc(10000);
  int count = read(fd, *buffer, 10000);

  if (count <= 0) {
    printf("Error or EOF\n");
    free (*buffer);
    *buffer = 0;
    *length = 0;
    return;
  } else {
    *length = count;
    return;
  }

}

int main(int argc, char **argv) {
  char *filebuffer;
  int length;

  if (argc < 2) {
    printf("usage: pointer4 <filename>\n");
    exit(1);
  }
  int f2r = open(argv[1], O_RDONLY);
  if (f2r < 0)  {
    printf("Error opening file\n");
    exit(1);
  }  
  getWholeFile(f2r, &filebuffer, &length);
  printf("%d bytes read.\n", length);
  printf("The file: |%s|\n", filebuffer);

  close(f2r);
  exit(0);

}
