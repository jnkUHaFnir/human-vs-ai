#include <stdio.h>

int main() {
   int N, i;
   char color[20];
   
   printf("Enter the number of strings: ");
   scanf("%d", &N);
   getchar(); // Consume the newline character

   printf("Enter the messages:\n");
   for(i = 0; i < N; i++) {
      fgets(color, sizeof(color), stdin);
      printf("%s", color);
   }

   return 0;
}
