#include <stdlib.h>
#include <stdio.h>
#include "node.h"

typedef struct {
	Node ** head;
} Queue, Queue;

Queue * makeQueue(void);
int dequeue(Queue *);
void enqueue(Queue *, int data);
int peek(Queue);
