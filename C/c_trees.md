# Trees

## Terms

The **degree** of a node is the number of subtrees of the node.

We use **parent**, **child**, and **sibling** when referring to nodes of a tree.

A **terminal** node is a node of degree 0.

A **branch** node is a nonterminal node.

The **movement** of a tree is the number of nodes in the tree.

The **weight** of a tree is the number of leaves in the tree.

The **level** or **depth** of a node is the number of branches that must be traversed to get to the node from the root.

The **height** of a tree is the number of levels in the tree. The height of the tree is one more than the highest level.

If the order of the subtrees is important, the tree is an **ordered** tree. Otherwise, the tree is **oriented**.

A **forest** is a set of zero or more disjoint trees.

## Binary Trees

nonlinear data structure

A binary tree is best defined using a recursive definition:

A **binary tree**

1. is empty

    **OR**

2. consists of a root and two subtrees, a left and a right, with each subtree being a binary tree

Meaning, a node always has two subtrees, which can be empty. And if a node has one empty subtree it is important to know if it is on the left or the right.

### Traversing a Binary Tree

For a tree with `n` nodes, there are `n!` ways to traverse every node. Not all of these ways are useful.

Three useful orders of traversal, **pre-order**, **in-order**, and **post-order**.

#### Pre-order traversal

1. visit the root
2. traverse the left subtree in pre-order
3. traverse the right subtree in pre-order

_Note: this is a recursive definition._

Pre-order traversal visits all left subtrees of a node before it visits a single right subtree.

#### In-order traversal

1. traverse the left subtree in in-order
2. visit the root
3. traverse the right subtree in in-order

#### Post-order traversal

1. traverse the left subtree in post-order
2. traverse the right subtree in post-order
3. visit the root

In post-order traversal the root node is always visited last.

### Representing a Binary Tree

```c
typedef struct treenode {
	NodeData data;
	struct treenode *left, *right;
} TreeNode, *TreeNodePtr;
```

We must provide our own definition of NodeData:

```c
typedef struct treenode {
	int num;
} NodeData;
```

A binary tree is then represented by its root.

```c
typedef struct {
	TreeNodePtr root;
} BinaryTree;
```

### Building a Binary Tree


### Binary Tree Deletion

The three cases to consider when deleting a node from a binary tree are as follows.

1. The node is a leaf (has no children).
2. The node has no left child.
3. The node has no right child.
4. The node has two children.

Case 1 is simple since all we need to do is set its parent link to null.

Case 2 is pretty simple as well since we can just replace the node with its only child.

Case 3 is more tricky. We must deal with both children. How we do this is replace the node with the lowest node we can find and then re-arrange that nodes children just like we are re-arranging the current nodes children.

Here is the pseudo code.

```c
deleteNode (TreeNode t) {
  if (T == NULL) return NULL;

  if (right(T) == NULL) return left(T)

  R = right(T)

  if (left(T) == NULL) return R

  if (left(R) == NULL) {
    left(R) == left(T)
    return R
  }
}
```
