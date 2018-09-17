# C examples

Examples showing the implementation of common C features in the form of small programs.

<!-- TOC depthFrom:2 depthTo:2 -->

- [Allocating and filling a 2d Array dynamically](#allocating-and-filling-a-2d-array-dynamically)

<!-- /TOC -->

## Allocating and filling a 2d Array dynamically

### Code

```c
#include <stdio.h>
#include <stdlib.h>

int createTable(int * table, int r, int c);
void printTable(int * table, int, int);

int main(int argc, char * argv[]) {
  int r, c;
  r = 12;
  c = 12;


  int * table;
  table  = (int *) calloc(r*c, sizeof(int));
  createTable(table, r, c);

  printTable(table, r, c);
}

int createTable(int * table, int r, int c) {
  int i;
  for (i = 0; i < r; i++) {
    int j;
    for (j = 0; j < c; j++) {
      *(table + i*c + j) = (i + 1) * (j + 1);
    }
  }
  return 1;
}

void printTable(int * table, int r, int c) {
  printf("\n");
  int i;
  for (i = 0; i < r; i++) {
    int j;
    for (j = 0; j < c; j++) {
      printf("%d\t", *(table + i * c + j));
    }
  printf("\n\n");
  }
}
```

### Explanation

This code allocates memory for a multi-dimentional array and then fills the array with r*c, to make a multiplication table.

Notice the use of pointers and pointer arithmetic to access and fill the array.