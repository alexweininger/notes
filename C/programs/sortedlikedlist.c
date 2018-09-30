#include <stdlib.h>
#include <stdio.h>

typedef struct node {
  int num;
  struct node *next;
} Node, *NodePtr;

int main() {
  void printList(NodePtr);
  NodePtr addInPlace(NodePtr, int);
  int n;
  NodePtr top = NULL;
  if (scanf("%d", &n) != 1)
    n = 0;
  while (n != 0) {
    top = addInPlace(top, n);
    if (scanf("%d", &n) != 1)
      n = 0;
  }
  printList(top);
}

NodePtr addInPlace(NodePtr top, int n) {
  NodePtr np, curr, prev, createNode(int);

  np = createNode(n);
  prev = NULL;
  curr = top;
  while (curr != NULL && n > curr->num) {
    prev = curr;
    curr = curr->next;
  }
  if (prev == NULL) {
    np->next = curr;
    return np;
  }
  np->next = curr;
  prev->next = np;
  return top;
}

NodePtr createNode(int n) {
  NodePtr np = (NodePtr)malloc(sizeof(Node));
  np->num = n;
  np->next = NULL;
  return np;
}

void printList(NodePtr np) {
  while (np != NULL) {
    printf("%d\n", np->num);
    np = np->next;
  }
}
