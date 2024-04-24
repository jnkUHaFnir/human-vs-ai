    char* dupchar(char c, int n)
    {
      char* s = malloc(n + 1); /* need +1 for null character to terminate string */
      for(int i=0; i < n; i++) s[i] = c;
      return s;
    }