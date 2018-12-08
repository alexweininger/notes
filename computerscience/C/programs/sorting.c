#include <stdio.h>
#include <stdlib.h>

void printList(int list[], int length);
void swap(int num[], int i, int j);
void selectionSort(int list[], int lo, int hi);
int getSmallest(int num[], int lo, int hi);
void insertionSort(int list[], int n);

int main(int argc, char const *argv[]) {
  int list[] = {1, 2, 5, 9, 4, 6, 3, 45, 2, 3, 67, 12, 11, 100};
  printList(list, 14);

  //selectionSort(list, 0, 13);
  insertionSort(list, 13);

  printList(list, 14);

  return 0;
}

void printList(int list[], int length) {
  int i;
  for (i = 0; i < length; i++) {
    printf("%d\n", list[i]);
  }
  printf("\n");
}

// selection sort  O(n^2)

void selectionSort(int list[], int lo, int hi) {
  for (int i = lo; i < hi; i++) {
    int s = getSmallest(list, i, hi);
    swap(list, i, s);
  }
}

int getSmallest(int num[], int lo, int hi) {
  int smallest = lo;
  for (int i = lo + 1; i <= hi; i++) {
    if (num[i] < num[smallest]) {
      smallest = i;
    }
  }
  return smallest;
}

void swap(int num[], int i, int j) {
  int hold = num[i];
  num[i] = num[j];
  num[j] = hold;
}

// insertion sort O(n^2)

void insertionSort(int list[], int n) {
  for (int h = 1; h < n; h++) {
    int key = list[h];
    int k = h - 1;
    while (k >= 0 && key < list[k]) {
      list[k + 1] = list[k];
      --k;
    }
    list[k + 1] = key;
  }
}
