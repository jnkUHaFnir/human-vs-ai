#include <stdio.h>

float fib(float x) {
  if (x == 0)
    return 0;
  else if (x == 1)
    return 1;

  float first = 0, second = 1, result = 0;
  for (int i = 2; i <= x; i++) {
    result = first + second;
    first = second;
    second = result;
  }
  return result;
}

int main() {
  float x, y;
  printf("x= ");
  scanf("%f", &x);
  y = fib(x);
  printf("%.2f", y);
  return 0;
}
