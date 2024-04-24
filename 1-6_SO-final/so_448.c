    #include<stdio.h>
    int my_scanf_to_uchar(unsigned char *puchar)
    {
      int retval;
      unsigned int val;
      retval = scanf("%u", &val);
      if (   retval == 1
          && val < 256;
         )
      {
        *puchar = val;
      }
      return retval;
    }