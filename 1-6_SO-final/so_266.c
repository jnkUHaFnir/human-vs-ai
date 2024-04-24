    #include <stdio.h>
    #include <errno.h>
    #include <stdlib.h>
    #include <string.h>
   
    int main()
       {
       int rCode=0;
       int i;
       char **t=NULL;
       /* Allocate a dynamic array of string pointers. */
       t = malloc(100 * sizeof(*t));
       if(NULL == t)
          {
          errno=ENOMEM;
          fprintf(stderr, "malloc() failed.\n");
          goto CLEANUP;
          }
       memset(t, 0, 100 * sizeof(*t));
       /* Initialize each pointer with a dynamically allocated string. */
       for(i=0; i<100 ;i++)
          {
          t[i]=strdup("A string");
          if(NULL == t[1])
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
          for(i=0; i<100 ;i++)
             if(t[i])
                free(t[i]);
          free(t);
          }
       return(0);
       }