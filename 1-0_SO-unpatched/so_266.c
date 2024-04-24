    #include <stdio.h>
    #include <errno.h>
    #include <stdlib.h>
    #include <string.h>
    int main(int I__argC, char *I__argV[])
       {
       int rCode=0;
       int i;
       char **t=NULL;
       size_t arraySize;
       /* Parse command line args. */
       if(2 != I__argC)
          {
          rCode=EINVAL;
          printf("USAGE: %s {dynamic array size}\n", I__argV[0]);
          goto CLEANUP;
          }
       arraySize=strtoul(I__argV[1], NULL, 0);
       if(0 == arraySize)
          {
          rCode=EINVAL;
          fprintf(stderr, "Cannot allocate a dynamic array of size zero.\n");
          goto CLEANUP;
          }
       /* Allocate a dynamic array of string pointers. */
       t = malloc(arraySize * sizeof(*t));
       if(NULL == t)
          {
          rCode=ENOMEM;
          fprintf(stderr, "malloc() failed.\n");
          goto CLEANUP;
          }
       memset(t, 0, arraySize * sizeof(*t));
       /* Initialize each pointer with a dynamically allocated string. */
       for(i=0; i<arraySize; i++)
          {
          t[i]=strdup("A string");
          if(NULL == t[i])
             {
             rCode=ENOMEM;
             fprintf(stderr, "strdup() failed.\n");
             goto CLEANUP;
             }
          }
    CLEANUP:
       /* Free the array of pointers, and all dynamically allocated strings. */
       if(t)
          {
          for(i=0; i<arraySize; i++)
             {
             if(t[i])
                free(t[i]);
             }
          free(t);
          }
       return(rCode);
       }