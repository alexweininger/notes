#include <stdio.h>
#include <stdlib.h>
#include "node.h"

Node **makeList() {
  Node *head = NULL;
  Node **listPtr = &head;
  return listPtr;
}

Node *makeNode(int data) {
  Node *node = (Node *)malloc(sizeof(Node));
  node->data = data;
  node->next = NULL;
  return node;
}

void insertHead(Node **list, int data) {
  if (NULL == *list) {
    *list = makeNode(data);
  } else {
    Node *node = makeNode(data);
    node->next = *list;
    *list = node;
  }
}

void insertTail(Node **list, int data) {
  if (NULL == list)
    return;

  if (NULL == *list) {
    *list = makeNode(data);
  }

  Node *curr = *list;
  while (NULL != curr->next) {
    curr = curr->next;
  }
  curr = makeNode(data);
}
