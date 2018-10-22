#include <stdio.h>
#include <stdlib.h>

int sumDigits(int);

int main(int argc, char const *argv[]) {
  printf("10: %d\n", sumDigits(10));
  printf("15: %d\n", sumDigits(15));
  return 0;
}

int sumDigits(int n) {
  if (n == 0)
    return 0;
  else
    return sumDigits(n - 1) + n;
}
