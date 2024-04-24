    int are_overlapping(const char *a, const char *b) 
    {
      if (a > b) /* or `(uintptr_t) a > (uintptr_t) b`, see note below! */
      {
        const char *t = a; 
        a = b; 
        b = t;
      }
      while (a != b && *a != '\0')
        ++a;
      return a == b;
    }