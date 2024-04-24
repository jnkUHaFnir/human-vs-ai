    int are_overlapping(const char *a, const char *b) 
    {
      while (a != b && *a != '\0')
        ++a;
      return a == b;
    }