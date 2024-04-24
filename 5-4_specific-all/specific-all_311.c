#include <stdio.h>

unsigned long long int fib(unsigned long long int x) {
  if (x == 0)
    return 0;
  else if (x == 1)
    return 1;
  else
    return fib(x - 2) + fib(x - 1);
}

int main() {
  unsigned long long int x, y;
  printf("x= ");
  scanf("%llu", &x);
  y = fib(x);
  printf("%llu", y);
  return 0;
}
