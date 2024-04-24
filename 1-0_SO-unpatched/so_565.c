    #include <stdio.h>
    #include <string.h>
    
    int main ()
    {
      char str[] ="This/a/sample/string";
      char * pch;
      char * ans;
      printf ("Splitting string \"%s\" into tokens:\n",str);
      pch = strtok (str,"/");
      if(pch==NULL)
      ans = str;
      while (pch != NULL)
      {
        ans = pch;
        pch = strtok (NULL, "/");
      }
      return 0;
    }