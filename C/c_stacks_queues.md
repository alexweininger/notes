# Stacks and Queues

An abstract data type is one that allows a user to manipulate the data without knowledge of how the data structure is implemented.

## Stacks

A **stack** is a linear list in which items are added at one end and deleted from the same end.

This idea can be illustrated by a stack of plates, when a plate is needed it is taken from the top of the stack. When a plate is washed it is added at the top of the stack. Exhibiting a **last in, first out** property.

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