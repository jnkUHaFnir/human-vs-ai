#include <stdio.h>

int main() {
   int num, sum = 0, count = 0;
   float avg;

   printf("Enter numbers (non-numeric value to stop): ");

   while (scanf("%d", &num) == 1) {
      sum += num;
      count++;
   }

   if (count > 0) {
      avg = (float) sum / count;
      printf("Average: %.2f\n", avg);
   } else {
      printf("No numbers entered\n");
   }

   return 0;
}
