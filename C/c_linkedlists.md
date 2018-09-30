# Linked Lists

<!-- TOC -->

- [Defining Link Lists](#defining-link-lists)
- [Basic Operations on a Linked List](#basic-operations-on-a-linked-list)
	- [Counting the Nodes in a Linked List](#counting-the-nodes-in-a-linked-list)
	- [Searching a Linked List](#searching-a-linked-list)
	- [Finding the Last Node in a Linked List](#finding-the-last-node-in-a-linked-list)
- [Dynamic Storage Allocation: malloc, calloc, sizeof, free](#dynamic-storage-allocation-malloc-calloc-sizeof-free)
- [Building a Linked List: Adding New Item at the Tail](#building-a-linked-list-adding-new-item-at-the-tail)
- [Insertion into a Linked List](#insertion-into-a-linked-list)

<!-- /TOC -->

## Defining Link Lists

A one-dimensional array can be considered to be a _linear list_. Each item in the list is a **node**. Given a node, the next node is assumed to be in the next location in the array. The order of the nodes is the order in which they appear in the array.

Consider the problem of inserting a new node in between two existing nodes. You must copy all of the nodes back one slot to make room for the new node.

We can represent a linear list in which each node explicitly **points** to the next node. This organization called a **linked list**.

In a singly linked list, each node contains a pointer that points to the next node in the list. The last node points to NULL.  

Diagram of a linked list

![linked list](./assets/linkedlist.gif)

To implement a link list in C we will need to use a `struct` because each node has at least two fields (data, and a pointer). We can define the node as follows:

```c
struct node {
	int num;
	struct node *next;
} Node, *NodePtr; // we also declare a name for "struct node *"
```

You also may define it using `typedef`:

```c
typedef struct node {
	int num;
	struct node *next;
} Node, *NodePtr; // we also declare a name for "struct node *"
```

The variable `top` can now be defined as a pointer to a node, like this:

`Node *top;` or `NodePtr top;`

## Basic Operations on a Linked List

Assume we have a linked list of integers.

### Counting the Nodes in a Linked List

```c
Node curr = top;
while (curr != NULL) curr = curr -> next;
```

This simple loop follows the pointers in each node until it reaches the last node in the linked list, which is identified by having a NULL pointer as `next`.

Taking this, we can easily implement a length function for linked lists.

```c
int length (NodePtr top) {
	int n = 0;
	NodePtr curr = top;
	while (curr != NULL) {
		n++;
		curr = curr -> next;
	}
	return n;
}
```

**Note** that if the list is empty, curr will be `NULL` the first time, and the while loop will not be executed. The function will return 0, as expected.

### Searching a Linked List

Searching a linked list is similar to the length we implemented above. Except now, we have one extra condition to check each node for. We can write a loop so that the search ends if we find a match **or** if we reach the end of the linked list. This can be implemeted as follows:

```c
while (curr != NULL && key != curr -> num) curr = curr -> next;
```

C guarantees that the `&&` operator is evaluated from left to right and evaluation stops as soon as the truth value is known. **In our case evaluation stops as soon as one operand is evaluated as false or the entire expression has been evaluated.**

We take advantage of this by evaluated `curr != NULL` before evaluating `key != curr -> name`. Consider if we switched the order of evaluation:

```c
while ( key != curr -> num && curr != NULL) curr = curr -> next;
```

If we wrote this, and `curr` happens to be `NULL`, our program will **crash** when it tries to retrieve `curr -> num`. We are trying to dereference a `NULL` pointer, and that is an error.

Here is a search function that given a pointer to the list and a key, returns the node containing key or `NULL` if not found.

```c
NodePtr search (NodePtr top, int key) {
	while (top != NULL && key != top -> num)
		top = top -> next;
	return top;
}
```

### Finding the Last Node in a Linked List

Sometimes we need to find the last node in a list. Here is a function that returns a pointer to the last node in a linked list.  If the list is empty, the function returns `NULL`.

```c
NodePtr getLast(NodePtr top) {
	if (top == NULL) return NULL;
	while (top -> next != NULL)
		top = top -> next;
	return top;
}
```

This function operates by checking `top -> next` before assigning it to top. This is done so that we can return top when `top -> next` is `NULL`.

## Dynamic Storage Allocation: malloc, calloc, sizeof, free

**The specifics of dynamic storage allocation are not covered in this section.**

Consider the problem of reading positive integers the building a linked list containing the values in the order in which they are read. For example, consider the following data:



How do we know how many nodes will be in the linked list? This depends on how many numbers we are given. A disadvantage of using an array for storing a linear list is that the size of the array must be specified beforehand, and can't be changed easily on demand.

With a linked list, whenever we need to add a node, storage is allocated for the node and the corresponding pointers are set. This results just the right storage allocation for the list. Although linked lists use extra space for the pointers, this is easily compensated by the storage efficiency, and easy insertions and deletions.

Allocating storage _as needed_ is usually referred to as **dynamic storage allocation**.  As opposed to arrays which are considered **static storage**.

## Building a Linked List: Adding New Item at the Tail

Consider again the problem of building a linked list of positive integers in the order they are given.  Consider the following numbers:

`36 15 52 23 0`

To being, define an empty list. This can be done like so: `top = NULL`.

When we read a new number, we need to:

1. Allocate storage for a node.

2. Put the number in the new node.

3. Make the new node the last one in the list.

Assume the following declaration for defining a node:

```c
typedef struct node {
	int num;
	struct node *next;
} Node, *NodePtr;
```

Now let's create a function called `makeNode` that, given an integer, does steps one through three listed above and returns a pointer to the new node. Additionally, our function sets the `next` field to `NULL`. Here is the function `makeNode`.

```c
NodePtr makeNode (int n) {
	NodePtr np = (NodePtr) malloc(sizeof (Node));
	np -> num = n;
	np -> next = NULL;
	return np;
}
```

Considering the call `makeNode(36)`. Assuming an `int` is 4 bytes and a pointer is 4 bytes, the size of `Node` is 8 bytes. Thus, 8 bytes are allocated and then 36 (`n`) is stored in the `num` field, and `NULL` in the `next` field. The node is then returned.

When we read the first number, we need to create a node for it and set `top` to point to the new node. This could be done with the following statement:

```c
if (top == NULL) top = makeNode(n);
```

For each new number after the first, we need to set the `next` field of the current last node to point to the new node and the new node becomes the last node. We already know how to find the last node of a linked list, but it is too time consuming to start from `top` and find the last node every time we add a node to the list. A better approach is to keep a pointer `last` which is just like `top`, but points to the last node.

This could be implemented like so:

```
np = makeNode(n);		// create a new node
if (top == NULL) top = np;	// set top if first node
else last -> next = np;		// set last -> next for future new nodes
last = np;			// update last node to the new node
```

Here's a fully built example program which reads the numbers and creates a linked list containing them.

```c
#include <stdio.h>
     #include <stdlib.h>
     typedef struct node {
        int num;
        struct node *next;
     } Node, *NodePtr;

     int main() {
        void printList(NodePtr);
        NodePtr makeNode(int);
        int n;
        NodePtr top, np, last;

        top = NULL;
        if (scanf("%d", &n) != 1) n = 0;
        while (n != 0) {
           np = makeNode(n);   //create a new node containing n
           if (top == NULL) top = np;   //set top if first node
           else last -> next = np;   //set last -> next for other nodes
           last = np;   //update last to  new node
           if (scanf("%d", &n) != 1) n = 0;
        }
        printList(top);
     } //end main

     NodePtr makeNode(int n) {
        NodePtr np = (NodePtr) malloc(sizeof (Node));
        np -> num = n;
        np -> next = NULL;
        return np;
     } //end makeNode

     void printList(NodePtr np) {
        while (np != NULL) {  // as long as there's a node
           printf("%d\n", np -> num);
           np = np -> next;  // go on to the next node
        }
     } //end printList
```

**Note**, this statement deserves some explanation:

`if (scanf("%d", &n) != 1) n = 0;`

Normally you would have written this:

`scanf("%d", &n)`

Instead we take use the value returned to us by `scanf` to do some error checking. When `scanf` is called, it stores data in the requested variables and returns the number of values successfully stored. So, in our case it should return 1 unless some error occurred.

## Insertion into a Linked List

A list with one pointer in each node is called a _one way_ or _singly linked_, list. An important feature of singly linked lists is that access to the nodes is done through the 'top of the list' pointer, since we can't access the _kth_ node directly. 