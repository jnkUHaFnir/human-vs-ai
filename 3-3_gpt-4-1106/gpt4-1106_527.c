#include <stdio.h>

void fun1(int a[]) {
  a[0] = 1;
}

int main() {
   int a[2] = {0, 2};
   fun1(a);
   printf("%d", a[0]); // Output should be 1
   return 0;
}
