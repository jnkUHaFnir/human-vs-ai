    #include<stdio.h>
    #include<stdlib.h>
    #include<string.h>
    
    #define MAX_STRING_LENGTH 100
    
    int main()
    {
        char *str[] = {"This is the first", "And this is the second sentence"};
        const size_t NUM_STRING = sizeof(str)/sizeof(char*);
        /*%z used to print size_t variables*/
        printf("%zd strings found\n", NUM_STRING);
        int length[2];
        int i;
        for (i=0; i<NUM_STRING; i++)
        {
            length[i] = strlen(str[i]);
        }
        printf("length initialized %d %d\n", length[0], length[1]);
    
        // Traverse string from end
        int j = 0;
        char temp[MAX_STRING_LENGTH];
        printf("\n\n");
        for (j=0; j<NUM_STRING; j++)
        {
          /*Make sure the string respect the MAX_STRING_LENGTH limit*/
          if (strlen(str[j])>MAX_STRING_LENGTH)
          {
            printf("ERROR: string %d exceding max string length %d. Exiting from program.\n", j, MAX_STRING_LENGTH);
            exit(1);
          }
          //reset temporary string
          memset(temp, '\0', sizeof(temp));
          //printf("temp variable reinitialized\n");
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