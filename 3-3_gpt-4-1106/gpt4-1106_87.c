#include <stdio.h>

int main() {
   int N, i;
   printf("Get the num : ");
   scanf("%d", &N);
   while (getchar() != '\n'); // Clean up the rest of the line
   
   // Furthermore, the char array needs to be initialized after the value of N is known.
   char color[N][20];

   printf("Enter the messages:\n");
   for (i = 0; i < N; i++) {
      fgets(color[i], 20, stdin);
      // Strips the newline character. (optional)
      color[i][strcspn(color[i], "\n")] = 0;
   }

   printf("\nYou entered:\n");
   for(i = 0; i < N; i++) {
      printf("%s\n", color[i]);
   }

   return 0;
}
while (getchar() != '\n');
