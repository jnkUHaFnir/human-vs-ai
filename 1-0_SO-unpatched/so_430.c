    int *** int_array_3d_allocate(size_t x, size_t y, size_t z)
    {
      int *** result;
      size_t n = x;
      size_t s = n * sizeof *result; /* x vector or pointer to int** */
   
      n *= y;
      s += n * sizeof **result; /* x*y vectors of pointer to int* */
      n *= z;
      s += n * sizeof ***result; /* x*y*z int */
      /* allocate it */
      result = malloc(s);
      if (result)
      {
         /* make the int** vector point to the int* vectors: */
         for (size_t i = 0; i < x; ++i)
         {
           result[i] = (int**) ((char*) result) + 
             (x * sizeof *result +
               i * y * sizeof **result);
         }
         /* make the int* vectors point to the int vectors: */
         for (size_t i = 0; i < x*y; ++i)
         {
           ((int**) ((char*) result + x * sizeof *result))[i] = (int*) ((char*) result) +
             (x * sizeof *result + x*y * sizeof **result 
               + i * sizeof ***result);
         }
       }
       return result;
    }