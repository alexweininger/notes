/* code for in-class activity for
 * complexity
 * CS 305
 * Tammy VanDeGrift, Martin Cenek
 */
#include <stdio.h>
#include <stdlib.h>

void func1(int n) {
  int i;
  for (i = 0; i < 2 * n; i++) {
    printf("Hello\n");
  }
}

void func2(int n) {
  int i, j, c;
  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      printf("I love complexity. i=%d j=%d total executions=%d\n", i, j, ++c);
    }
  }
}

void func3(int n) {
  int i;
  for (i = 0; i * i <= n; i++) {
    printf("Howdy\n");
  }
}

void func4(int n) {
  int i, j;
  for (i = 0; i < n; i++) {
    for (j = 0; j < i; j++) {
      printf("****\n");
    }
  }
}

int main(void) {
  func1(10);
  func2(10);
  func3(100);
  func4(10);
  return EXIT_SUCCESS;
}
