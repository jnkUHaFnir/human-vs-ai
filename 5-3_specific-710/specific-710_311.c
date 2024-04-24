#include <stdio.h>

float fib(float x) {
  float a = 0, b = 1, next;
  if (x == 0) return a;
  
  for (int i = 2; i <= x; i++) {
    next = a + b;
    a = b;
    b = next;
  }
  
  return b;
}

int main() {
  float x, y;
  printf("x= ");
  scanf("%f", &x); // Corrected input format specifier
  
  y = fib(x);
  printf("%7.2f", y);
  
  return 0;
}
