#include <stdio.h>
#include <stdlib.h>

#define SIZE 1000

struct mystruct
{
  int a;
  int b;
  char c;
};

struct mystruct* myarray = NULL;
int myarrayMaxSize = SIZE;

void extendArray(int newSize)
{
  myarray = realloc(myarray, newSize * sizeof(struct mystruct));
  
  if(myarray == NULL)
  {
    printf("Memory allocation failed\n");
    exit(1);
  }
  
  myarrayMaxSize = newSize;
}

int main()
{
  myarray = malloc(SIZE * sizeof(struct mystruct));
  
  if(myarray == NULL)
  {
    printf("Memory allocation failed\n");
    exit(1);
  }
  
  // Use the array
  
  // If more space is needed
  int i = 2000;
  if ( i > myarrayMaxSize )
  {
    extendArray(myarrayMaxSize + SIZE);
  }
  
  // Free the dynamically allocated memory
  free(myarray);
  
  return 0;
}
