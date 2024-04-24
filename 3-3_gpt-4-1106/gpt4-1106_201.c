#include<stdio.h>
#include<stdlib.h>

int main()
{
   int *p = malloc(10 * sizeof(int)); // Changed to use sizeof(int) for clarity
   if (!p) {
       perror("malloc failed");
       return EXIT_FAILURE;
   }

   int i, a;
   printf("Input :\n");
   for(i = 0; ; i++) // Infinite loop, handling the end condition inside
   {
     if (scanf("%d", &a) != 1) { // Check scanf return value for errors
         free(p);
         fprintf(stderr, "Failed to read an integer.\n");
         return EXIT_FAILURE;
     }

     p[i] = a; // Store the read value

     if(a == 22) { // Check if user entered 22
         break;
     }

     if(i % 10 == 9) { // Check if we've filled up current allocation
         // Need to increase size by 10 more ints
         int *new_p = realloc(p, (i + 11) * sizeof(int)); // +11 to make room for next 10 plus one just entered
         if (!new_p) {
             perror("realloc failed");
             free(p);
             return EXIT_FAILURE;
         }
         p = new_p;
     }
   }

   printf("\nOutput :\n");
   for(int j = 0; j < i; j++){ // Print all values up to (but not including) 22
       printf("%d\n", p[j]);
   }

   free(p); // Free allocated memory
   return 0;
}
