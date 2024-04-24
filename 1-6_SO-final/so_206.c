    int are_overlapping(const char *a, const char *b) 
    {
      const char *a_end = a + strlen(a), *b_end = b + strlen(b);
      return a < b_end && b < a_end;
    }