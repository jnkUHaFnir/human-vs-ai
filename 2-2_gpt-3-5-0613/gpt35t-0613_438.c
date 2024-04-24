#include <stdio.h>
#include <stdlib.h>

int main() {
   int return_value = system("which Rscript");

   if (return_value == 0) {
       printf("Rscript is installed\n");
   } else {
       printf("Rscript is not installed\n");
   }

   return 0;
}
