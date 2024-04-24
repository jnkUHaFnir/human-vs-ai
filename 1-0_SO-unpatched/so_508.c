    char *toUpper(char *str) {
      char *s = str;
      size_t len = strlen(s);
      size_t i;
    
      for (i = 0; i < len; i++) {
        if (s[i] >= 'a' && s[i] <= 'z') {
          s[i] = s[i] - 32;
        }
      }
      return str;
    }