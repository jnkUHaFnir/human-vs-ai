    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    
      int main(void)
    {
      srand(time(NULL));
      int size;
      int i;
      int *array; // You must declare a pointer to allocate space on the heap
    
      printf("\nSize of random array: ");
      scanf("%d", &size);
    
      array = (int *)malloc(sizeof(int) * size); // Set the size as your input size
    
      if(array == NULL) // Always check if your memory allocation was successful...
      {
      printf("malloc of size %d failed!\n", size);
      exit(1); // Probably better ways to handle errors
      }
    
      for (i = 0; i <  size; i++){
        array[i] = rand() % 100 + 1;;
      }
    
      for (i=0; i < size; i++){
           printf("%d ", array[i]);
          }
    
     int largest =0;
    
    for (i = 1; i < size; i++)
    {
          if (largest < array[i])
                  largest = array[i];
          }
    printf("\n largest element present in the given array is : %d\n", largest);
    
    free(array); // Always FREE your allocated memory
    
        return 0;
    }