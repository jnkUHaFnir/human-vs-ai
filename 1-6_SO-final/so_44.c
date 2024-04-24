    #define _GNU_SOURCE
    #include <stdio.h>
    int main (void) {
      char* ptrzone = NULL;
      asprintf(&ptrzone, "and here %s and one is %d", "ABC", 1);
      printf("%s\n", ptrzone);
      free (ptrzone), ptrzone = NULL;
    }