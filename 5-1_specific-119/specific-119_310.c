#include <stdio.h>

float fib(float x) {
  if (x == 0)
    return 0;
  else if (x == 1)
    return 1;

  float a = 0;
  float b = 1;
  float result;
  
  for (int i = 2; i <= x; i++) {
    result = a + b;
    a = b;
    b = result;
  }

  return result;
}

int main() {
  float x, y;
  printf("x= ");
  scanf("%f", &x);
  y = fib(x);
  printf("%.2f\n", y);
  return 0;
}
