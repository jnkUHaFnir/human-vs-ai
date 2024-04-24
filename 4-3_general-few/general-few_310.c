#include <stdio.h>

int fib(int x) {
  if (x == 0)
    return 0;
  else if (x == 1)
    return 1;
  else
    return fib(x - 2) + fib(x - 1);
}

int main() {
  int x, y;
  printf("x= ");
  scanf("%d", &x);
  y = fib(x);
  printf("%d\n", y);
  return 0;
}
