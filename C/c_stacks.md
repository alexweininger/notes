# Stacks

An abstract data type is one that allows a user to manipulate the data without knowledge of how the data structure is implemented. For more information look up the definition of abstract in programming.

A **stack** is a linear list in which items are added at one end and deleted from the same end.

This idea can be illustrated by a stack of plates, when a plate is needed it is taken from the top of the stack. When a plate is washed it is added at the top of the stack. Exhibiting a **last in, first out** property.

## Terminology

When adding an item to a stack it is called **pushing** an item to the stack.

When retrieving an item from a stack we call is **popping** an item from the stack.

Another handy operation is checking if the stack is **empty**. This will need to be done before popping items from the stack.

## Implementing a Stack Using an Array

For the array implementation of a stack of integers, we have an `int ST[MaxStack]` for storing the integer.
And we have `int top` for storing the index of the element at the top of the stack. 
We need `int top` because when items are added to the stack they will be added to the first open space in the array.

```c
typedef struct {
	int top;
	int ST[MaxStack];
} StackType, *Stack;
```

`Stack s;`

The first operation is to create an empty stack, which can be done like so:

```c
Stack initStack () {
	Stack sp = (stack) malloc(sizeof(StackType));
	sp -> top = -1;
	return sp;
}
```

In `main` we could write the following

`Stack s = initStack();`

It's simple to check if a stack is empty.

```c
int empty(Stack s) {
	return (S -> top == -1);
}
```

### Push

```c
void push(Stack s, int n) {
	if (s->top == MaxStack - 1) {
		printf("Error: max overflow");
		exit(1);
	}
	++(s->top);
	s->ST[s->top] = n
}
```

### Pop

```c
int pop (Stack s) {
	if(empty(s)) {
		printf("Error: empty");
		return -1;
	}
	int hold = s->ST[s->top];
	--(s->top);
	return hold;
}
```

## Implementing a Stack Using a Linked List

An array implementation is simple and efficient, however it needs a static size. Linked lists can be used since storage for an element is used only when needed.

Here are the declarations:

```c
typedef struct node {
	int top;
	int ST[MaxStack];
} Node, *NodePtr;

typedef struct {
	NodePtr top;
	int ST[MaxStack];
} StackType, *Stack;
```

Stack can be pictured as a pointer to top, and top is a pointer to the linked list of stack elements.

Here is how to create an empty stack.

```c
Stack initStack() {
	Stack sp = (Stack) malloc(sizeof(StackType));
	sp -> top = NULL;
	return sp;
}
```

In main we can use `Stack s = initStack();`

Testing for an empty stack is done like so:

```c
int empty(Stack s) {
	return (s->top == NULL);
}
```

### Push Implemented with Linked Lists

```c
void push(Stack s, int n) {
	NodePtr np = (NodePtr) malloc(sizeof(Node));
	np -> num = n;
	np -> next = s -> top;
	s -> next = np;
}
```

### Pop Implemented with Linked Lists

```c
int pop(Stack s) {
	if(empty(s)){
		return -1;
	} else {
		int hold = s -> top -> num;
		NodePtr temp = s -> top;
		s -> top = s -> top -> next;
		free(temp);
		return hold;
	}
}
```

## A General Stack Type

So far we have worked with stacks of integers. Let's implement a stack that would work for any data type.



## Notes from lecture

Stack and queue inherit can inherit only certain methods or functions from a link list class or library. Stacks need `insertHead` and `deleteHead` `peak`. Queues need `insertHead` and `deleteTail`. Leaving out some, but you get the general idea.

Can be implemented in both arrays and linked lists, as well as a hybrid between the two.

A problem we that can be solved with a stack, is trying to validate the parenthesis, brackets, etc. of a string of code. E.g. given `(5 + 7) - x + [x * (10 / y)]`, are all the parenthesis and brackets closed?

Here is the pseudo code for this program.

While still have input, examine next symbol and:

1. If symbol is not a delimiter, discard it.
2. If symbol is a left delimiter, push it to stack
3. If symbol is a right delimiter, pop stack (call it top)
	1. If top does not exist, return false
	2. If top is not the left delimiter of symbol, return false
	3. If top is the left delimiter of symbol, discard symbol and keep going
	4. If stack is empty, return true

Other ways in which stacks are used in programming are function calls. Local variables are put onto the stack and then popped when the function ends.

Consider the following function calls withing main.

```text
main -> f -> g -> h
			 g -> k
```

So, the information for main is on the stack, then the info for f is pushed to the stack, then info for g is pushed to the stack, then info for h is pushed to the stack.
When h returns, the info for h is popped, then g calls k so info for k is pushed. When k returns, info for k is popped. When g returns, info for g is popped. When f returns, info for f is popped.
When main returns, info for main is popped.