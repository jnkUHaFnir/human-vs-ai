    // "String1::String2:String3:String4::String5" with delimiter "::" will produce
    // "String1\0\0String2:String3:String4\0\0String5"
    // And words should contain a pointer to the first S, the second S and the last S.
    char **strToWordArray(char *str, const char *delimiter)
    {
      char **words;
      int nwords = countWords(str, delimiter); //I let you decide how you want to do this
      words = malloc(sizeof(*words) * (nwords + 1));
      int w = 0;
      int len = strlen(delimiter);
      words[w++] = str;
      while (*str != NULL)
      {
        if (strcmp(str, delimiter) == 0)
        {
          for (int i = 0; i < len; i++)
          {
            *(str++) = 0;
          }
          if (*str != 0)
            words[w++] = str;
        }
        str++;
      }
      words[w] = NULL;
      return words;
    }