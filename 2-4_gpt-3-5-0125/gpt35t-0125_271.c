#include <stdio.h>

int main() {
   unsigned char n[3] = {1, 2, 3};
   int base = 256;

   int result = 0;
   for(int i = 0; i < 3; i++) {
       result += n[i] * pow(base, i);
   }

   printf("%d\n", result);

   return 0;
}
