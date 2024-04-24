    #include<stdio.h>
    int my_scanf_to_uchar(unsigned char *puchar)
    {
      int retval;
      unsigned int uiTemp;
      retval = scanf("%u", &uiTemp);
      if (   retval == 1
          && uiTemp < 256;
         )
      {
        *puchar = uiTemp;
      }
      return retval;
    }