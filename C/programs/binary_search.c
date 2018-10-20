/*****************************************************************
 * Program: bin_search.c
 * CS 305
 * Lecture: recursion
 * Purpose: implements recursive binary search
 *****************************************************************/
#include <stdio.h>
#include <stdlib.h>

/*****************************************************************
 * binary_search - finds position of an element in (portion of a)
 * sorted array
 *
 * usage:
 *    pos = binarySearch(key, array, first_index, last_index)
 *
 * parameters -
 *    key - the integer that we're searching for
 *    array - the array we're searching
 *    first_index - index of the first element of the sorted array
 *    last_index - index of the last element of the sorted array
 *
 * result -
 *    If the element is in the array, the position in the array where
 *    the element was found.  Otherwise, -1 returned.
 *
 * precondition -
 *    The array must contain at least one element, and must be sorted
 *    in increasing order for this function to work.
 *    first_index and last_index must be in bounds on the array
 *****************************************************************/
int binary_search(int key, int arr[], int first_index, int last_index) {

  printf("binary_search(%d, arr, %d, %d)\n", key, first_index, last_index);
  // base case: first_index has reached or crossed last_index
  if (first_index >= last_index) {
    if (arr[first_index] == key) { // check for key
      return first_index;          // found key at first_index
    } else {
      return -1; // key was not found in arr
    }

  }

  // recursive case: need to look to the left or right of arr
  else {
    int mid = (first_index + last_index) / 2;
    printf("mid: %d\n", mid);
    if (key > arr[mid]) {
      // look to the right of mid
      return binary_search(key, arr, mid + 1, last_index);
    } else {
      // look to the left of mid
      return binary_search(key, arr, first_index, mid);
    }
  }
}

/****************************************************************
 * linear_search - finds position of an element in an array
 *
 * usage -
 * linear_search(key, array, len)
 *
 * parameters -
 * key - the integer we're searching for
 * array - the array we're searching
 * len - the length of the array we're searching
 *
 * result -
 * if the key is found, returns the position in the array of
 * that key. Otherwise, -1 is returned
 *
 * note: works on sorted and unsorted arrays
 **************************************************************/
int linear_search(int key, int arr[], int len) {
  int i;
  if (len <= 0) { // check len, if invalid return -1
    return -1;
  }
  // search for key in arr
  for (i = 0; i < len; i++) {
    if (arr[i] == key) {
      return i;
    }
  }
  return -1;
}

/*****************************************************************
 * main - main program to exercise 'binary_search'
 *
 * This program prompts the user for a number to search for, and then
 * invokes 'binary_search' on a predefined (sorted) array.
 *
 *****************************************************************/
int main(void) {
  // the array we're searching
  int test_array[] = {3, 5, 8, 12, 25, 34, 57, 58, 59, 67, 87};
  int test_array2[] = {3,  6,  14, 15, 18, 20, 22, 35,
                       37, 39, 40, 41, 45, 57, 60, 62};

  // prompt user and read number
  int to_search = 0;
  printf("Please type number to search for: ");
  if (1 != scanf("%d", &to_search)) {
    fprintf(stderr, "Error reading number. Exiting program.\n");
    return EXIT_FAILURE;
  }

  int len = sizeof(test_array2) / sizeof(*test_array2);

  // search for the number using binary search
  int result = binary_search(to_search, test_array2, 0, len - 1);

  // report result to console
  if (result == -1) {
    printf("Element not found using binary search\n");
  } else {
    printf("Element is in position %d using binary search\n", result);
  }

  // search for the number using linear search
  int result2 = linear_search(to_search, test_array, len);
  if (result2 == -1) {
    printf("Element not found using linear search\n");
  } else {
    printf("Element is in position %d using linear search\n", result2);
  }
  return EXIT_SUCCESS;
}
