      #include <stdalign.h>
      #define INTP_ALIGNMENT (alignof (int*))
      #define INT_ALIGNMENT (alignof (int))
      int *** int_array_3d_allocate(size_t x, size_t y, size_t z)
      {
        int *** result;
        size_t n = x;
        size_t s = n * sizeof *result; /* x vector or pointer to int** */
        size_t y_off = s % INTP_ALIGNMENT 
          ?INTP_ALIGNMENT - s % INTP_ALIGNMENT :0;
        n *= y;
        s += n * sizeof **result; /* x*y vectors of pointer to int* */
        size_t z_off = s % INT_ALIGNMENT 
          ?INT_ALIGNMENT - s % INT_ALIGNMENT :0;
        n *= z;
        s += n * sizeof ***result; /* x*y*z int */
        /* allocate it */
        result = malloc(s);
        if (result)
        {
           /* make the int** vector point to the int* vectors: */
           for (size_t i = 0; i < x; ++i)
           {
             result[i] = (int**) ((char*) result) + y_off +
               (x * sizeof *result +
                 i * y * sizeof **result);
           }
           /* make the int* vectors point to the int vectors: */
           for (size_t i = 0; i < x*y; ++i)
           {
             ((int**) ((char*) result + x * sizeof *result + y_off))[i] = (int*) ((char*) result) + y_off +
               (x * sizeof *result + x*y * sizeof **result + z_off +
                 + i * sizeof ***result);
           }
         }
         return result;
      }