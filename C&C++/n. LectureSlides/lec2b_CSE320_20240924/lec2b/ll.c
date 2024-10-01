#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#include "ll.h"

// Define head of linked list
Node *head = 0; // Head node of ll

Node *ll_new() {
  head = (Node *) 0;
  return head;
}




void ll_add_head(Node *newNode) {
  if (head == 0) {
    head = newNode;
  } else {
    newNode->next = head;
    head = newNode;
  }

  /*
  if (head != 0) {
    newNode->next = head;
  } else {
    newNode->next = 0;
  }
  head = newNode;
  */
}

void ll_add_tail(Node *newNode) {
  if (head == 0) {
    head = newNode;
    newNode->next = 0;
  } else {
    Node *curr;
    for (curr = head; curr->next != 0; curr = curr->next);
    curr->next = newNode;
    curr->next->next = 0;    // newNode->next = 0;
  }
}

Node *ll_del(char *dataValue) {
  Node *curr = head;
  Node *retval = 0;
  int isHead = 1;
  Node *prev = 0;
  while (curr != 0) {
    if (strcmp(curr->data, dataValue) == 0) {
      if (isHead) {
	retval = head;
	head = curr->next;
      } else {
	retval = curr;
	prev->next = curr->next;
      }
      break;
    } else {
      // Not equal - keep going
      prev = curr;         // need this for deleting in middle of list.
      curr = curr->next;
      isHead = 0;          // no longer looking at head
    }
  }
  return retval;
}


void ll_print() {
  Node *curr = head;
  while (curr != 0) {
    printf(" %s", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

void ll_free() {
  Node *curr = head;
  Node *prev = 0;
  while (curr != 0) {
    free(curr->data);
    prev = curr;
    curr = curr->next;
    free(prev);
  }
  head = 0;
}
