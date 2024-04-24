    #include<stdio.h>
    #include<string.h>
    void rearrange(char *str)
    {
        int len=strlen(str),n=0,i;
        char *word=malloc((len+(int)(len/2)));
          
        if(word==NULL)
        {
           printf("Memory Error");
           exit(1);
        }
  
        for(i=0;i<len;i++)
        {
            if( i % 2 == 0 && i != 0)
            {
                word[n]=' ';
                n++;
                word[n]=str[i];
                n++;
            }
            else
            {
                word[n]=str[i];
                n++;
            }
        }
        
        word[n]='\0';
        strcpy(str,word);
        free(word);
        return;
    }
    int main()
    {
         char word[40];
    
         printf("Enter word:");
         scanf("%s",word);
         rearrange(word);
         printf("\n%s",word);
    
         return 0;
     }