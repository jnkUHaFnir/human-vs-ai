    #include <stdlib.h>
    #include <stdio.h>
    int *** int_array_3d_allocate(size_t x, size_t y, size_t z);
    
    int main(void)
    {
      const size_t x = 2;
      const size_t y = 3;
      const size_t z = 5;
      int *** int_array_3d = int_array_3d_allocate(x, y, z);
      if (!int_array_3d)
      {
        perror("int_array_3d_allocate() failed");
      }
      else
      {
        for (size_t i = 0; i < x; ++i)
        {
          for (size_t j = 0; j < y; ++j)
          {
            for (size_t k = 0; k < z; ++k)
            {
              int_array_3d[i][j][k] = i*j*k;
            }
          }
        }
        /* do stuff with the continuous array of ints. 
           Just be aware that the 1st int only is located at address:
           (char* int_array_3d) +
             (x * sizeof *int_array_3d + x*y * sizeof **int_array_3d) 
        */
        free(int_array_3d);
      }
    }
      