#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
}

int isPalRec(char str[], int s, int e) {
  // If there is only one character
  if (s == e)
    return 1;

  // If first and last
  // characters do not match
  if (str[s] != str[e])
    return 0;
  // If there are more than
  // two characters, check if
  // middle substring is also
  // palindrome or not.
  if (s < e + 1)
    return isPalRec(str, s + 1, e - 1);
  return 1;
}

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
}

NodePtr reverseLetters(NodePtr top) {
  NodePtr rev = NULL, np;
  char c;
  while (top != NULL) {
    c = top->ch;
    if (isalpha(c)) {
      np = (NodePtr)malloc(sizeof(Node));
      np->ch = c;
      np->next = rev;
      rev = np;
    }
    top = top->next;
  }
  return rev;
}

int compare(NodePtr s1, NodePtr s2) {
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

NodePtr createNode(char c) {
  NodePtr np = (NodePtr)malloc(sizeof(Node));
  np->ch = c;
  np->next = NULL;
  return np;
}
