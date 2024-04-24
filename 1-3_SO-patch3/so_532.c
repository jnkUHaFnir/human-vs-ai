    #include<stdio.h>
    #include <stdlib.h>
    #include<string.h>
    
    int main()
    {
      int i,j;
      char str[1000];
      char out = ' '; // space represents unset value, could also use null character
    
      scanf("%s",str);// input the string
      for(i=0; i < strlen(str); i++)
      {
        for(j=i+1;j<strlen(str);j++)
        {
          if(str[i]==str[j] && out == ' ') // compare
          {
            out = str[i];
          }
        }
      }
      printf("%c", out);
    }