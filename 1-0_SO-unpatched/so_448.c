    #include<stdio.h>
    int my_scanf_to_uchar(unsigned char *puchar)
    {
      int retval;
      unsigned int uiTemp;
      retval = scanf("%u", &uiTemp);
      if (retval == 1)   
      {
        if (uiTemp < 256) {
          *puchar = uiTemp;
        }
        else {
          retval = 0; //maybe better something like EINVAL
        }
      }
      return retval; 
    }