    #include <stdio.h>
    #include <stdlib.h>
    
    #define FAIL 0
    int main() {
      int *pSet = (int*) malloc(sizeof(int));
      int c;
      int i=0;
      printf("Please enter a stream of numbers to make a set out of them: ");
      while(scanf("%d", &c) == 1) {
        pSet[i] = c;
        pSet = (int*) realloc(pSet, sizeof(int)*(i+1));
        if(pSet == NULL) {
          return FAIL;        
        }
        printf("%d ", c);
        i++;
      }
    
      free(pSet);
    }