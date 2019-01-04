/* CS 305 Lab Starter
 * program to test tree code
 * Tammy VanDeGrift, Martin Cenek
 * main.c
 */

#include <stdio.h>
#include <stdlib.h>
#include "tree.h"

/* prototypes */
void test1(void);

/* main function to test lab code */
int main(void) {
  test1();
  return EXIT_SUCCESS;
}

/* test1 -- builds BST */
void test1(void) {
  // create array of ints to insert into tree
  // int arr[] = {3, 6, 2, 1, 4, 8};
  // int arr[] = {5, 2, 7, 1, 3, 6, 8};
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

  // int arr[] = {3, 6, 2};
  TreeNode *tree = createTree(arr, sizeof(arr) / sizeof(*arr));
  printf("Inorder: ");
  inorder(tree);
  printf("\nPreorder: ");
  preorder(tree);
  printf("\nPostorder: ");
  postorder(tree);
  printf("\n");

  printf("Inorder: ");
  inorder(tree);
  printf("\nPreorder: ");
  preorder(tree);
  printf("\nPostorder: ");
  postorder(tree);
  printf("\n");

  printf("\n");
  printf("Size: %d\n", size(tree));
  printf("Height: %d\n", height(tree));
  printf("Num leaves: %d\n", countLeaves(tree));
  printf("Num interior: %d\n", countInterior(tree));
  printf("Num greater than 3: %d\n", countGreater(tree, 3));

  TreeNode *d = find(3, tree);
  TreeNode *e = find(0, tree);
  if (d != NULL) {
    printf("contains 3\n");
  }
  if (e != NULL) {
    printf("contains 0\n");
  }

  int max = findMax(tree);
  printf("max: %d\n", max);

  printf("is balanced=%d\n", isBalanced(tree));

  int arr2[] = {2, 1, 3};
  TreeNode *bt = createTree(arr2, sizeof(arr2) / sizeof(*arr2));
  printf("is balanced=%d\n", isBalanced(bt));

  freeTree(&tree);
  return;
}
