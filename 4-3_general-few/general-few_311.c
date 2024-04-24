#include <stdio.h>

unsigned int fib(unsigned int x) {
  if(x == 0)
    return 0;
  else if(x == 1)
    return 1;
  else
    return fib(x - 2) + fib(x - 1);
}

int main() {
  unsigned int x, y;
  printf("x= ");
  scanf("%u", &x);
  y = fib(x);
  printf("%u\n", y);
  return 0;
}
