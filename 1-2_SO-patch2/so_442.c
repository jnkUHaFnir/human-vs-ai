    char* DestStrings[MAX_STRINGS];
    int j = 0;
    int length = 0; 
    inr prevLength =0;
    int offset = 8;
    for(int i = 0;i<MAX_STRINGS;i++) 
    {
         length += strlen(&srcbuffer[j+offset+length]); 
         if(length == prevLength)                          
         { 
            
            break;
         }
         else
         {
           prevLength = length;
           DestStrings[i] = malloc(length+1);
           strcpy(DestStrings[i],&srcbuffer[j+offset+length]);
           j++;
         }
    }