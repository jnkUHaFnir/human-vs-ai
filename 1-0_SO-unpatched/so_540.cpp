    char* dupchar(char c, int n)
    {
      int i;
      char* s;
      s = malloc(n + 1); /* need +1 for null character to terminate string */
      if (s != NULL) {
        for(i=0; i < n; i++) s[i] = c;
      }
      return s;
    }