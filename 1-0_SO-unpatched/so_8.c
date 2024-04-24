    #include <stdio.h>
    #include <stdlib.h>
    #include <time.h>
    
    int main(void) {
    
    srand(time(NULL));
    int size = 0;
    int i;
    int largest;
    // You must declare a pointer to allocate space on the heap
    int *array; 
    
    // Loop until user enters a valid size
    while (size <= 0) {
    
    	printf("\nPlease enter the size of random array: ");
    	scanf("%d", &size);
    
    	if (size <= 0) 
    	  printf("Please enter a number above 0.");
    
    }
    
    // Set the size as your input size  
    array = (int *)malloc(sizeof(int) * size); 
    
    // Always check if your memory allocation was successful...
    // Probably better ways to handle than to simply exit out
    if(array == NULL) {
    
    printf("malloc of size %d failed!\n", size);
    exit(1); 
    
    }
    
    for (i = 0; i <  size; i++) {
    
      array[i] = rand() % 100 + 1;;
    
    }
    
    for (i = 0; i < size; i++) {
    
      printf("%d ", array[i]);
    
    }
    
    // Set the largest value as the first element in the arr
    largest = array[0]; 
    
    for (i = 1; i < size; i++) {
    
      if (largest < array[i]) {
            largest = array[i];
      }
    }
    
    printf("\nLargest element present in the given array is : %d\n", largest);
    
    // Always FREE your allocated memory
    free(array); 
    
    return 0;
    
    }