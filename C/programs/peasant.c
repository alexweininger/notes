#include <stdio.h>
int main() {
	printf("%d\n", peasant(5, 10));
}

int peasant(int a, int b) {
  if (b == 1)
    return a;
  if(b % 2 == 0)
    return peasant(a*2, b/2);
  else
    return peasant(a*2, b/2) + a;
}
