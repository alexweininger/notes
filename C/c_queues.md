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

### Enqueue and dequeue for a Queue implemented with an Array

Since tail cannot be greater than `MaxQ - 1`, and we may have extra room at the head of the queue made by dequeueing, we can _wrap_ tail around by setting tail to 0.

```c
void enqueue(Queue Q, int n) {
	if(Q -> tail == MaxQ - 1) Q -> tail = 0; // wrap tail
	else ++(Q -> tail);
	if(Q -> head == Q -> tail) { // if the wrapped tail has reached head
 		printf("Error: queue is full");
		return -1;
	}
	Q -> QA[Q -> tail] = n;
}
```

After dequeuing all items from a queue, `head` would have reached `tail` and the queue would be empty.
In this case, we want to set `head` to _make room_ for more items.

```c
int dequeue(Queue Q) {
	if(empty(Q)) {
		printf("Error: queue empty");
		return -1;
	}
	if(Q -> head == MaxQ - 1) Q -> head = 0;
	else ++(Q -> head);
	return Q -> QA[Q -> head];
}
```

[http://cslibrary.stanford.edu/105/LinkedListProblems.pdf](http://cslibrary.stanford.edu/105/LinkedListProblems.pdf)