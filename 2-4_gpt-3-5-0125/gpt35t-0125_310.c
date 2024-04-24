#include <stdio.h>

int fib(int x) {
  if (x <= 1)
    return x;
  else
    return fib(x - 1) + fib(x - 2);
}

int main() {
  int x, y;
  printf("x= ");
  scanf("%d", &x);
  y = fib(x);
  printf("%d\n", y);
  return 0;
}
