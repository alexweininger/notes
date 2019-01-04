#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
  struct Node *next;
  int data;
} Node;

typedef struct {
  Node *top;
} Stack;

Stack *createStack(void);
void push(Stack *, int);
int pop(Stack *);
int isEmpty(Stack *);
void print(Stack *s);

Stack *createStack() {
  Stack *s = (Stack *)malloc(sizeof(Stack));
  return s;
}

void push(Stack *s, int data) {
  Node *d = (Node *)malloc(sizeof(Node));
  d->data = data;
  d->next = NULL;
  if (NULL == s->top) {
    s->top = d;
  } else {
    d->next = s->top;
    s->top = d->next;
  }
}

int pop(Stack *s) {
	if (s->top == NULL) return NULL;
	else {
		Node * p = s->top;
		s->top = s->top->next;
		return p->data;
	}
}

int isEmpty(Stack * s) {
	return NULL == s->top;
}

void print(Stack *s) {
  Node *n = s->top;
  if (NULL == n) printf("Stack is empty.\n");
  while (NULL != n) {
    printf("%d\n", n->data);
    n = n->next;
  }
}

int main() {
  Stack *s = createStack();
  push(s, 7);
  print(s);
  pop(s);
  pop(s);
  pop(s);
  print(s);
}
