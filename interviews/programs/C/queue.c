#include "queue.h"

Queue *makeQueue() {
  Queue * q = (Queue *) malloc(sizeof(struct Queue));
  q->head = NULL;
  return q;
}
int dequeue(Queue *q) {
  if (q->head == NULL) {
    printf("error, queue is empty\n");
    return -1;
  } else {
    return q->head->data;
  }
}
void enqueue(Queue *q, int data) {
}
int peek(Queue q) {
}
