# Linked Lists

<!-- TOC -->

- [Defining Link Lists](#defining-link-lists)
- [Basic Operations on a Linked List](#basic-operations-on-a-linked-list)
	- [Counting the Nodes in a Linked List](#counting-the-nodes-in-a-linked-list)
	- [Searching a Linked List](#searching-a-linked-list)
	- [Finding the Last Node in a Linked List](#finding-the-last-node-in-a-linked-list)
- [Dynamic Storage Allocation: malloc, calloc, sizeof, free](#dynamic-storage-allocation-malloc-calloc-sizeof-free)
- [Building a Linked List: Adding New Item at the Tail](#building-a-linked-list-adding-new-item-at-the-tail)
	- [Program 1: Linked List Adding at Tail](#program-1-linked-list-adding-at-tail)
- [Insertion into a Linked List](#insertion-into-a-linked-list)
- [Building a Linked List: Adding a New Item at the head](#building-a-linked-list-adding-a-new-item-at-the-head)
	- [Program 2: Linked List Adding at the Head](#program-2-linked-list-adding-at-the-head)
	- [Important Terminology](#important-terminology)
- [Deletion from a Linked List](#deletion-from-a-linked-list)
- [Building a Sorted Linked List](#building-a-sorted-linked-list)
	- [Program 3: Linked List Sorted](#program-3-linked-list-sorted)
- [Example: Palindrome Program](#example-palindrome-program)
	- [Program 4: Palindrome](#program-4-palindrome)
- [Saving a Linked List](#saving-a-linked-list)
- [Arrays vs. Linked Lists](#arrays-vs-linked-lists)
	- [Table 1: Arrays and Linked Lists Pros and Cons](#table-1-arrays-and-linked-lists-pros-and-cons)
- [Merging Two Sorted Linked Lists](#merging-two-sorted-linked-lists)
	- [Program 5: Merging Two Sorted Linked Lists](#program-5-merging-two-sorted-linked-lists)

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

Sometimes we need to find the last node in a list. Here is a function that returns a pointer to the last node in a linked list. If the list is empty, the function returns `NULL`.

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

Allocating storage _as needed_ is usually referred to as **dynamic storage allocation**. As opposed to arrays which are considered **static storage**.

## Building a Linked List: Adding New Item at the Tail

Consider again the problem of building a linked list of positive integers in the order they are given. Consider the following numbers:

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

### Program 1: Linked List Adding at Tail

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
     }

     NodePtr makeNode(int n) {
        NodePtr np = (NodePtr) malloc(sizeof (Node));
        np -> num = n;
        np -> next = NULL;
        return np;
     }

     void printList(NodePtr np) {
        while (np != NULL) {  // as long as there's a node
           printf("%d\n", np -> num);
           np = np -> next;  // go on to the next node
        }
     }
```

**Note**, this statement deserves some explanation:

`if (scanf("%d", &n) != 1) n = 0;`

Normally you would have written this:

`scanf("%d", &n)`

Instead we take use the value returned to us by `scanf` to do some error checking. When `scanf` is called, it stores data in the requested variables and returns the number of values successfully stored. So, in our case it should return 1 unless some error occurred.

## Insertion into a Linked List

A list with one pointer in each node is called a _one way_ or _singly linked_, list. An important feature of singly linked lists is that access to the nodes is done through the 'top of the list' pointer, since we can't access the _kth_ node directly. A great advantage of a linked list is that it allows for easy insertions and deletions anywhere in the list.

Suppose we need to insert a new node between the second and third nodes (insertion after the second node). We can insert the new node by setting it's `next` field to the third node, and the `next` field of the second node to the new node. **Note that the second node is all we need to preform the insertion.** It's `next` field will give us the third node. The insertion can be done as follows:

```c
np -> next = prev -> next;	// set the new node's next to whatever the previous node points to
prev -> next = np;		// set the previous node's next to the new node
```

This code even works if `prev` were pointing to the last node in a linked list.

To insert a node at the head of a list, we must use `top` like so:

```c
np -> next = top
top = np;
```

## Building a Linked List: Adding a New Item at the head

Consider the problem of reading integers and putting them into a linked list, except this time we insert each new number at the head rather than at the end. Considering the data (0 terminates the data):

`36 15 52 23 0`

The program to build the link list in reverse order is actually simpler than the previous one. The only changes are in the `while` loop. As each new number is read, we set it to point to the first node, and we set `top` to point to the new node (the new first node).

### Program 2: Linked List Adding at the Head

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
        NodePtr top, np;
        top = NULL;
        if (scanf("%d", &n) != 1) n = 0;
        while (n != 0) {
           np = makeNode(n);   //create a new node containing n
           np -> next = top;   //set link of new node to first node
           top = np;   //set top to point to new node
           if (scanf("%d", &n) != 1) n = 0;
        }
        printList(top);
     }

     NodePtr makeNode(int n) {
        NodePtr np = (NodePtr) malloc(sizeof (Node));
        np -> num = n;
        np -> next = NULL;
        return np;
     }

     void printList(NodePtr np) {
        while (np != NULL) {  // as long as there's a node
           printf("%d\n", np -> num);
           np = np -> next;  // go on to the next node
        }
     }
```

### Important Terminology

Program 1 inserts numbers at the tail of the list. This is an example of adding an item to a queue. A **queue** is a linear list in which insertions occur at one end and deletions occur at the other end.

Program 2 inserts incoming numbers at the head of the list. This is an example of adding an item to a stack. A **stack** is a linear list in which insertions and deletions occur at the same end. In the context of a stack, items are **pushed** (added) onto and **popped** (deleted) from the stack.

## Deletion from a Linked List

Deleted a node from the top of a linked list can be simply done like so:

`top = top -> next;`

This makes `top` point to whatever the first node was pointing at (aka the second node). Since `top` is now pointing to the second node, the first node is essentially deleted from the list.

Although this is simple, we need to do more checks before blindly removing the first node from a list. First we need to check that `top != NULL`. If there is only one node in the list, deleting it will result in an empty list and `top` will become `NULL`.

Suppose `curr` (current node) points to the node to be deleted. To delete the node, we must change the previous node's `next` field. This means we need to have a pointer to the previous node `prev`. With this, we can delete the `curr` node with the following statement:

`prev -> next = curr -> next;`

So far _deletion_ has meant _logical deletion_. Meaning although the node is no longer logically in the list, the nodes are still in memory.

If we had a large list in which many deletions occur, we may need to physically free their memory. Here is how we can accomplish this:

```c
prev -> next = curr -> next;	// logical deletion
free(curr);			// free the space occupied by the deleted node
```

## Building a Sorted Linked List

We might also want to build the list of numbers so that it is always sorted in ascending order. Consider the same data we've been using:

`36 15 52 23 0`

To keep the list sorted, when we read a new number we need to insert it into the correct spot within the list. To do this, we check if the `num` of `curr` is greater than the new node's `num` or if we've reached the end of the list.

The following code processes a new number:

```c
prev = NULL;
curr = top;
while (curr != NULL && n > curr -> num) {
	prev = curr;
	curr = curr -> next;
}
```

Since we need to insert our new number _before_ the node smaller than it, we need to keep a pointer `prev` the previous node.

A fully implemented sorted link list program can be seen here:

### Program 3: Linked List Sorted

This program is also available to download / view [here](./programs/sortedlikedlist.c).

```c
     #include <stdio.h>
     #include <stdlib.h>

     typedef struct node {
        int num;
        struct node *next;
     } Node, *NodePtr;

     int main() {
        void printList(NodePtr);
        NodePtr addInPlace(NodePtr, int);
        int n;
        NodePtr top = NULL;
        if (scanf("%d", &n) != 1) n = 0;
        while (n != 0) {
           top = addInPlace(top, n);
           if (scanf("%d", &n) != 1) n = 0;
        }
        printList(top);
     }

     NodePtr addInPlace(NodePtr top, int n) {
     // This functions inserts n in its ordered position in a (possibly empty)
     // list pointed to by top, and returns a pointer to the new list
        NodePtr np, curr, prev, makeNode(int);

        np = makeNode(n);
        prev = NULL;
        curr = top;
        while (curr != NULL && n > curr -> num) {
           prev = curr;
           curr = curr -> next;
        }
        if (prev == NULL) { //new number must be added at the top
           np -> next = top;
           return np; //the top of the list has changed to the new node
        }
        np -> next = curr;
        prev -> next = np;
        return top; //the top of the list has not changed
     }

     NodePtr makeNode(int n) {
        NodePtr np = (NodePtr) malloc(sizeof (Node));
        np -> num = n;
        np -> next = NULL;
        return np;
     }

     void printList(NodePtr np) {
        while (np != NULL) {  // as long as there's a node
           printf("%d\n", np -> num);
           np = np -> next;  // go on to the next node
        }
     }
```

## Example: Palindrome Program

Consider the problem of determining whether a given string is a _palindrome_ (the same read backwards and forwards). Some examples of palindromes are:

`racecar`
`civic`
`Madam, I'm Adam`
`A man, a plan, a canal, Panama.`

You may be able to solve this problem using an array, but solving it with a linked list is a little different since we cannot directly access any node inside the linear list as we can with an array.

The steps of our program will be as follows:

1. Store the original string in a linked list, one character in each node.

2. Create another list containing only the letters of the string, converted to lowercase and stored in reverse order. We'll call this `list1`.

3. Reverse `list1` and store it in a new list, `list2`.

4. Compare `list1` with `list2`, one character at a time until a mismatch is found (the string is not a palindrome) or when we reach the end of the lists (the string is a palindrome).

### Program 4: Palindrome

This program can also be downloaded / viewed [here](./programs/linkedlists_palindrome.c).

The function `getPhrase` reads the data and stores the characters in a linked list. The next function, `reverseLetters` takes a list and returns a new list which is reversed. All it does is insert each node at the `top` or head of the linked list. Then, `compare` compares two lists one node (or character) at a time.

```c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node {
  char ch;
  struct node *next;
} Node, *NodePtr;

int main() {
  NodePtr getPhrase();
  NodePtr reverseLetters(NodePtr);
  int compare(NodePtr, NodePtr);
  NodePtr phrase, s1, s2;

  printf("Type a phrase. (To stop, press 'Enter' only): ");
  phrase = getPhrase();
  while (phrase != NULL) {
    s1 = reverseLetters(phrase);
    s2 = reverseLetters(s1);
    if (compare(s1, s2) == 0)
      printf("is a palindrome\n");
    else
      printf("is not a palindrome\n");
    printf("Type a word. (To stop, press 'Enter' only): ");
    phrase = getPhrase();
  }
} // end main

NodePtr getPhrase() {
  NodePtr top = NULL, last, np;
  char c = getchar();
  while (c != '\n') {
    np = (NodePtr)malloc(sizeof(Node));
    np->ch = c;
    np->next = NULL;
    if (top == NULL)
      top = np;
    else
      last->next = np;
    last = np;
    c = getchar();
  }
  return top;
} // end getPhrase

NodePtr reverseLetters(NodePtr top) {
  NodePtr rev = NULL, np;
  char c;
  while (top != NULL) {
    c = top->ch;
    if (isalpha(c)) { // add to new list
      np = (NodePtr)malloc(sizeof(Node));
      np->ch = tolower(c);
      np->next = rev;
      rev = np;
    }
    top = top->next; // go to next character of phrase
  }
  return rev;
} // end reverseLetter

int compare(NodePtr s1, NodePtr s2) {
  // return -1 if s1 < s2, +1 if s1 > s2 and 0 if s1 = s2
  while (s1 != NULL) {
    if (s1->ch < s2->ch)
      return -1;
    else if (s1->ch > s2->ch)
      return 1;
    s1 = s1->next;
    s2 = s2->next;
  }
  return 0;
}
```

**Note: the palindrome problem can be solved more efficiently using arrays, and was used to show how to further implement linked lists.**

## Saving a Linked List

So far in our programs, each time the program is stopped we no longer have access to our lists. We need to implement a way to save our lists for later use.

We can't save the pointer values since they aren't constant between executions, so we must save the contents of the nodes. The easiest way to do this is to use a file to store the data, and then read from the file when we need the data again.

It is useful to convert a linked list to an array when we need to search the data in the list. Since we can use binary search with arrays.

Suppose we have a linked list with at most 50 integers. Converting a linked list to an array can be done like so:

```c
int saveLL[50], n = 0;
while (top != NULL && n < 50) {
  saveLL[n++] = top->num;
  top = top->next;
}
```

## Arrays vs. Linked Lists

Arrays and linked lists are the two most common ways to store a linear list, and each has its own pros and cons.

This largest difference is we have direct access to any element in an array, where a nodes of a linked list must be traversed to from the top.

If the list is unsorted we have to use sequential search for both an array and a linked list. If the list is sorted we can search an array using binary search. **The only way to search a linked list is sequential.**

Assuming there is room, inserting an element at the tail of an array is easy, but inserting at the head or somewhere in the middle is not. Inserting nodes into a linked list is easy regardless of location.

In the same manner, deleting a node from a linked list is easy. And deleting an element from an array is not easy unless it is at the tail.

Keeping an array sorted while adding items is cumbersome, while linked lists handle this task with ease.

Here is a table to summarize the pros and cons of arrays and linked lists.

### Table 1: Arrays and Linked Lists Pros and Cons

Array | Linked List
---------|---------
 Direct access to any item | Must traverse list to get to item
 If unsorted, sequential search | If unsorted, sequential search
 If sorted, binary search | If sorted, sequential search
 Easy to insert items at the tail of the list | Easy to insert item anywhere in the list
 Must move items to insert anywhere but the tail | Easy to insert item anywhere in the list
 Deletion (except the last one) requires items to be moved | Deletion of items is easy
 Need to move items when adding new new item to a sorted list | Adding a new item to a sorted linked list is easy
 Can use binary search on a sorted list to find the position at which to insert new item | Must use sequential search to find the position at which to insert new item in a sorted linked list

## Merging Two Sorted Linked Lists

Suppose we had the two sorted linked lists, A and B:

A. `21 -> 28 -> 35 -> 40 -> 61 -> 75`

B. `16 -> 25 -> 47 -> 54`

We want to create a linked list with all numbers in ascending order, list C:

C. `16 -> 21 -> 25 -> 28 -> 35 -> 40 -> 47 -> 54 -> 61 -> 75`

We can do this without creating any new nodes. Instead, we simply adjust pointers the create the merged list. At the end A and B will no longer exist.

We will use the following algorithm:

```c
while (at least one number remains in the lists A and B) {
  if (smallest in A < smallest in B) {
    add smallest in A to C
    move on to next number in A
  } else {
    add smallest in B to C
    move on to the next number in B
  }
}
if (A has ended) add remaining numbers in B to C
else add remaining numbers in A to C
```

Assuming the nodes of the lists are defined as such:

```c
typedef struct node {
  int num;
  struct node * next;
} Node, *NodePtr;
```

and `A, B, C = NULL;`

For simplicity this code assumes both A and B are nonempty:

```c
NodePtr C = NULL, last = NULL;
while (A != NULL && B != NULL) {
  if (A -> num < B -> num) {
    if (C == NULL) C = A;
    else last -> next = A;
    last = A;
    A = A -> next;
  } else {
    if (C == NULL) C = B;
    else last -> next = B;
    last = B;
    B = B -> next;
  }
}
if (A == NULL) last -> next = B;
else last -> next = A;
```

Here is a program that demonstrates this in the `merge` function:

### Program 5: Merging Two Sorted Linked Lists

```c
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
  int num;
  struct node *next;
} Node, *NodePtr;

int main() {
  void printList(NodePtr);
  NodePtr makeList(void);
  NodePtr merge(NodePtr, NodePtr);
  NodePtr A, B;

  printf("Enter sorted numbers for the first list (0 to end)\n");
  A = makeList();
  printf("Enter sorted numbers for the second list (0 to end)\n");
  B = makeList();
  printf("\nThe merged list is\n");
  printList(merge(A, B));
} //end main

NodePtr makeList() {
  NodePtr makeNode(int), np, top, last;
  int n;
  top = NULL;
  if (scanf("%d", &n) != 1) n = 0;
  while (n != 0) {
      np = makeNode(n);   //create a new node containing n
      if (top == NULL) top = np;   //set top if first node
      else last -> next = np;   //set last -> next for other nodes
      last = np;   //update last to  new node
      if (scanf("%d", &n) != 1) n = 0;
  }
  return top;
} //end makeList

NodePtr makeNode(int n) {
  NodePtr np = (NodePtr) malloc(sizeof (Node));
  np -> num = n;
  np -> next = NULL;
  return np;
} //end makeNode

void printList(NodePtr np) {
  while (np != NULL) {  // as long as there's a node
      printf("%d ", np -> num);
      np = np -> next;  // go on to the next node
  }
  printf("\n\n");
} //end printList

NodePtr merge(NodePtr A, NodePtr B) {
  NodePtr C = NULL, last = NULL;
  // check if either A or B is empty
  if (A == NULL) return B;
  if (B == NULL) return A;
  //both lists are non-empty
  while (A != NULL && B != NULL) {
      if (A -> num < B -> num) {
        if (C == NULL) C = A; else last -> next = A;
        last = A;
        A = A -> next ;
      }
      else {
        if (C == NULL) C = B; else last -> next = B;
        last = B;
        B = B -> next ;
      }
  } //end while
  if (A == NULL) last -> next = B;
  else last -> next = A;
  return C;
} //end merge
```