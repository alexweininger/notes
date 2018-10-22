#include <stdio.h>
#include <stdlib.h>

/**
 * print, length, insert top, insert tail, insert sorted, reverse, copy, find,
 * delete
 */

typedef struct nodeTag Node;

/* similar to the textbook -- a Node represents one node in the linked list */
struct nodeTag {
  int num;    // value stored in node
  Node *next; // pointer to next node in list
};

Node *makeNode(int n, Node *nextNode);
void insertTail(int n, Node **listPtr);
int delete (Node *toDelete, Node **listPtr);
void reverse(Node **top);
Node *find(int n, Node *);
void print(Node *);
int length(Node *);
Node *copy(Node *);
Node *doubleCopy(Node *);
int count(Node *, int);
Node * getNthNode(Node *, int);

int main(int argc, char const *argv[]) {
  Node *top = NULL;
  top = makeNode(6, top);
  top = makeNode(10, top);
  top = makeNode(-3, top);
  top = makeNode(2, top);
  printf("length: %d\n", length(top));
  print(top);
  insertTail(12, &top);
  print(top);
  printf("reversed:\n");
  reverse(&top);
  print(top);
  Node *list2 = NULL;
  list2 = copy(top);
  printf("copy:\n");
  print(list2);
  printf("doubled copy\n");
  Node *list3 = NULL;
  list3 = doubleCopy(top);
  print(list3);
  printf("count 10s: %d\n", count(top, 10));
  printf("get nth: 2 = %d\n", (getNthNode(top, 2)->num));
  return 0;
}

Node *makeNode(int n, Node *nextNode) {
  Node *np = (Node *)malloc(sizeof(Node));
  np->num = n;
  np->next = nextNode;
  return np;
}
// recusrively print the linked list
void print(Node *top) {
  if (NULL != top) {
    printf("%d\n", top->num);
    print(top->next);
  }
}

// returns the length of the linked list - resursion
int length(Node *top) {
  if (NULL != top) {
    return length(top->next) + 1;
  }
}

void insertTail(int n, Node **listPtr) {
  Node *list = *listPtr;
  if (NULL == list) {
    *listPtr = makeNode(n, NULL);
    return;
  }
  while (NULL != list) {
    if (NULL == list) {
      printf("wtf\n");
    }
    if (NULL == list->next) {
      list->next = makeNode(n, NULL);
      return;
    }
    list = list->next;
  }
}

int delete (Node *toDelete, Node **listPtr) {
  // NULL checks
  if (toDelete == NULL || *listPtr == NULL) {
    return 0;
  }

  Node *curr = *listPtr;

  // if deleting first node
  if (toDelete == curr) {
    *listPtr = curr->next;
    free(curr);
    return 1;
  }

  Node *prev = curr;
  curr = curr->next;
  while (curr != NULL) {
    if (toDelete == curr) {
      prev->next = curr->next;
      free(curr);
      return 1;
    }
    // advance nodes
    prev = curr;
    curr = curr->next;
  }
  return 0; // node not found
}

Node *find(int n, Node *top) {
  while (NULL != top) {
    if (top->num == n)
      return top;    // return found node
    top = top->next; // advance node
  }
  return NULL; // node not found
}

void reverse(Node **listPtr) {

  Node *prev = NULL;
  Node *curr = *listPtr;
  Node *temp = curr;

  // go through list nodes
  while (curr != NULL) {
    temp = curr;       // make temp = curr
    curr = curr->next; // advance curr
    temp->next = prev; // node->next = prev
    prev = temp;       // advance prev
  }
  *listPtr = prev; // return prev as the new top
}

// create a new list which is a copy of the list "top"
// returns top of new list
Node *copy(Node *top) {
  Node *newList = NULL;             // make new list "head"
  while (top != NULL) {             // go through list to copy
    insertTail(top->num, &newList); // insert each node at the tail of new list
    top = top->next;                // advance node of new list
  }
  return newList; // retrun top of new list
}

// makes a copy of top but each number is put in twice
Node *doubleCopy(Node *top) {
  Node *list = NULL;
  while (NULL != top) {
    insertTail(top->num, &list);
    insertTail(top->num, &list);
    top = top->next;
  }
  return list;
}

void printAndFree(Node *top) {
  while (NULL != top) {       // iterate through list
    printf("%d\n", top->num); // print num
    Node *temp = top;         // make temp of top
    top = top->next;          // advance top
    free(temp);               // free top (temp)
  }
}

// returns how many times n occurs in linked list
int count(Node *top, int n) {
  int count = 0;
  while (top != NULL) {
    if (top->num == n)
      count++;
    top = top->next;
  }
  return count;
}

Node *getNthNode(Node *top, int n) {
  int i = 0;
  while(NULL != top && i < n) {
    top = top->next;
    i++;
  }
  return top;
}
