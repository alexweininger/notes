#include <stdio.h>
void printNumInBase(int base, int num);

void main(int argc, char argv[]) {
  int i;
  /* prompt user and read number */
  int val;
  printf("Please type a number: ");
  scanf("%d", &val); // note: does not do error-checking

  /* print the number in all bases from 2 through 36 */
  for (i = 2; i <= 36; i++) {
    printf("The number base %d is ", i);
    printNumInBase(i, val);
    printf("\n");
  }
}

void printNumInBase(int base, int num) {
  char digits[] = "0123456789ABCDEFGHIJKLMOPQRSTUVWXYZ";
  // if negative print "-" and call printNUm again, but with positive num
  if (num < 0) {
    printf("-");
    printNumInBase(base, -1 * num);
  } else if (base > num) { // base case
    printf("%c", digits[num]);
  } else { // recursive case
    printNumInBase(base, (num / base));
    printNumInBase(base, (num % base));
  }
}
