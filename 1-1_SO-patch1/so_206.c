    int are_overlapping(const char *a, const char *b) 
    {
      assert(a != NULL && b != NULL);
      if (a > b) /* or `(uintptr_t) a > (uintptr_t) b`, see note below! */
      {
        const char *t = a; 
        a = b; 
        b = t;
      }
      assert(a <= b); /* or `(uintptr_t) a <= (uintptr_t) b` */
      while (a != b && *a != '\0')
        ++a;
      return a == b;
    }