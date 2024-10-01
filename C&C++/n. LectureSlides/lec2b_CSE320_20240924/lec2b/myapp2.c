
#include <stdio.h>
#include "ll.h"
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  char *temp;

  Node *workingNode;
  
  Node *head = ll_new();
  temp = (char *) malloc(80);
  int i;
  int wc = 0;
  printf("Enter word count: ");
  scanf("%d", &wc);

  for (i = 0;i < wc; i++) {
    int location;

    printf("head[0] or tail[1]? ");
    scanf("%d", &location);
    printf("Enter a word: ");
    scanf("%79s", temp);
    workingNode = (Node *) malloc(sizeof(Node));
    workingNode->data = strdup(temp);
    if (location == 0) {
      ll_add_head(workingNode);
    } else {
      ll_add_tail(workingNode);
    }
    printf("Currentlist:\n");
    ll_print();
  }

  ll_print();
  printf("Deleting three\n");
  Node *deleted = ll_del("three");
  if (deleted != 0) {
    printf("Deleted: %s\n", deleted->data);
    free (deleted->data);
    free (deleted);
  }
  printf("New list:\n");
  ll_print();

  ll_free();
  printf("Done\n");
}
