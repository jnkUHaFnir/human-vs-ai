    #include <stdio.h>
    
    int main()
    {
      int i,j;
      char str[1000];
      char out = ' '; // space represents unset value, could also use null character
    
      scanf("%s",str);// input the string
      for (i = 0; str[i] != '\0'; i++)
      {
        for (j = i + 1; str[j] != '\0'; j++)
        {
          if (str[i]==str[j] && out == ' ') // compare
          {
            out = str[i];
          }
        }
      }
      printf("%c", out);
    }