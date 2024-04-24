#include <stdio.h>

int main() {
   int num, status;

   printf("Enter an Integer: ");
   status = scanf("%d", &num);

   if (status != 1) {
       printf("Invalid input. Not a number.");
   } else {
       printf("Valid input. The number is %d", num);
   }

   return 0;
}
