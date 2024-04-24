    #include<stdio.h>
    #include<string.h>
    void rearrange(char *str)
    {
        int len=strlen(str),n=0,i;
        char word[(len+(int)(len/2))];
  
        for(i=0;i<len;i++)
        {
            if(i%2==0&&i!=0)
            {
                sprintf(word+n," %c",str[i]);
                n+=2;
            }
            else
            {
                sprintf(word+n,"%c",str[i]);
                n++;
            }
        }
   
        strcpy(str,word);
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