# Queues

A **queue** is a linked list in which items are added at one end and deleted from the other end. Examples would be the lines you stand in at the supermarket or sporting event.

## Basic queue operations

Add an item to the queue, we say **enqueue**.

Take an item off the queue, we say **dequeue**.

Check if queue is **empty**.

Take a **peak** at the item at the head of the queue.

## Implementing a Queue using an Array

```c
Queue struct {
	int head, tail; // indices
	int QA[MaxQ]; // array of data
} QType, *Queue;
```

We can declare a queue with `Queue Q;`

The code to initialize a queue is written like so:

```c
Queue initQueue() {
	Queue qp = (Queue) malloc(sizeof(QType));
	qp -> head = qp -> tail = 0;
	return qp;
}
```

`Queue Q = initQueue();`

```c
int empty(Queue Q) {
	return (Q -> head == Q -> tail);
}
```

