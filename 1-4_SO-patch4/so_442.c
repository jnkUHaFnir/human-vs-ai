    char* DestStrings[MAX_STRINGS];
    int j = 0;
    int length; 
    for(int i = 0;i<MAX_STRINGS;i++) 
    {
         length = strlen(&srcbuffer[j]); 
         if(length == 0)                          
         { 
            break;
         }
         else
         {
           DestStrings[i] = malloc(length+1);
           strcpy(DestStrings[i],&srcbuffer[j]);
           j++;
         }
    }