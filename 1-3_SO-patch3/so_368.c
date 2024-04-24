    #include <stdio.h>
    #include <stdlib.h>
    
     int main()
     {
     double decpart;
     printf("Enter a floating number num: ");
     char buf[100];
     char *endptr;
    
     while (1)
     {
     fgets(buf,99,stdin);
    
     double floatnum = strtod(buf,&endptr);
    
     if (endptr[0]!='\n')
     {
       printf("Invalid floating point number, enter again: ");
     }
     else
     {
     int intpart = (int)floatnum;
     double decpart = floatnum - intpart;
     if (decpart == 0.000000){
        printf("Invalid floating point number, enter again: ");
     }
     else
     {
        printf("Number entered = %.2f\n", floatnum);
        break;
     } 
     }
    }
    return 0;
    }