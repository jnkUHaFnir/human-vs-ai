    #include<stdio.h>
    #include<string.h>
    
    #define NUM_STRING 2
    
    int main() {
    
        char *str[] = {"This is the first sentence", "And this is the second"};
        int length[2];
        length[0] = strlen(str[0]);
        length[1] = strlen(str[1]);
        //printf("%d%d\n", length[0], length[1]);
    
        // Traverse string from end
        int i;
        int j=0;
        char temp[100];
        memset(temp, '\0', sizeof(temp));
        for (j=0; j<NUM_STRING; j++)
        {
          for (i = length[j] - 1; i >= 0; i--)
          {
            temp[i] = str[j][i];
            if (str[j][i] == ' ')
            {
    
              // putting the NULL character at the position of space characters for  next iteration.
              temp[i] = '\0';
    
              // Start from next character
              printf("%s ", &(temp[i]) + 1);
            }
          }
    
          // printing the last word
          printf("%s ", temp);
        }
        printf("\n");
    
    
        return 0;
    }