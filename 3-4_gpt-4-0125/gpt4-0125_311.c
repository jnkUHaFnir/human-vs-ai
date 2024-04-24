#include <stdio.h>

// Change the function to work with integer types.
int fib(int n) {
  if (n == 0)
    return 0;
  else if (n == 1)
    return 1;
  else
    return fib(n - 2) + fib(n - 1);
}

int main() {
  int x;
  printf("x= ");
  // Read x as an integer.
  scanf("%d", &x);
  
  // Calculating Fibonacci for non-negative integers only.
  if (x >= 0) {
    int y = fib(x);
    printf("%d", y);
  } else {
    printf("Fibonacci sequence is defined for non-negative integers only.\n");
  }
  
  return 0;
}
