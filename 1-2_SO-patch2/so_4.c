    int numStrsInList(const char* strList, int maxlen) 
    {
       // returns the number of strings in a null terminated array of 
       // contiguous null-terminated strings.
       // maxlen is the maximum overall length of the buffer, 
       // can be 0 to defeat length checking
       const char* s;
       int result = 0;
       if (!strList) return -1;
    
       for (s = strlist; s[0] != 0; s += (strlen(s) + 1))
       {
         if (maxlen && (s - strlist) > maxlen) return -1;
         ++result;
       }
    
       return result;
    }