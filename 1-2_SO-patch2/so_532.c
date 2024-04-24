    #include<stdio.h>
    #include <stdlib.h>
    #include<string.h>
    
    int main()
    {
      int i,j;
      char str[1000];
      int strLength = strlen(str);
      char out = ' '; // space represents unset value, could also use null character
    
      scanf("%s",str);// input the string
      for (i = 0; i < strLength; i++)
      {
        for (j = i + 1; j < strLength; j++)
        {
          if (str[i]==str[j] && out == ' ') // compare
          {
            out = str[i];
          }
        }
      }
      printf("%c", out);
    }