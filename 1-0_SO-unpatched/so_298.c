    #include <stdio.h>
    #include <stdlib.h>
    #include "storage.h"
    /* Initialise an empty array */
    void Array_Init(Array *array) 
    {
      array->array = (int *)malloc(sizeof(int)); 
      array->size = 0;
    }
    /* Dynamically add to end of an array */
    void Array_Add(Array *array, int item) 
    {
        array->size += 1;
        array->array = (int *)realloc(array->array, array->size * sizeof(int));
        array->array[array->size-1] = item;
    }
    /* Delete from a dynamic array */
    void Array_Delete(Array *array, int index) 
    {
        int i;
        Array temp;
    
        Array_Init(&temp);
    
        for(i=index; i<array->size; i++)
        {
            array->array[i] = array->array[i + 1];
        }
    
        array->size -= 1;
        
        for (i = 0; i < array->size; i++)
        {
            Array_Add(&temp, array->array[i]);
        }
    
        array->array = (int *)realloc(temp.array, temp.size * sizeof(int)); 
    }
    /* Free an array */
    void Array_Free(Array *array) 
    {
      free(array->array);
      array->array = NULL;
      array->size = 0;  
    }