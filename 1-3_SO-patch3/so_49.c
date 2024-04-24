       size_t myarray_size = 1000;
       mystruct* myarray = malloc(myarray_size * sizeof(mystruct));
       myarray_size += 1000;
       myarray = realloc(myarray, myarray_size);