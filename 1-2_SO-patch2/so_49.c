       size_t myarray_size = 1000;
       mystruct* myarray = malloc(myarray_size * sizeof(mystruct));
       myarray_size += 1000;
       mystruct* myrealloced_array = realloc(myarray, myarray_size);
       if (myrealloced_array) {
         myarray = myrealloced_array)
       } else {
         // deal with realloc failing because memory could not be allocated.
       }