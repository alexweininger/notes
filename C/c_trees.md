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
