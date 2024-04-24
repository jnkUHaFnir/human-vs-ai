#include <stdio.h>

int main(){
   int N,i;
   char color[N][20];
   
   printf("Enter the num of colors : ");
   scanf("%d",&N);
    
   // Clearing the input buffer
   while(getchar() != '\n');

   printf("Enter the colors\n");
   for(i=0;i<N;i++){
      fgets(color[i],20,stdin);
   }

   for(i=0;i<N;i++){
      printf("%s",color[i]);
  }
  
  return 0;
}
