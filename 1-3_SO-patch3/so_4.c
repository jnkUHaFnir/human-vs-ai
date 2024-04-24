    int numStrsInList(const char* strList) 
    {
       // returns the number of strings in a null terminated array of 
       // contiguous null-terminated strings.
       const char* s;
       int result = 0;
       if (!strList) return -1;
    
       for (s = strlist; s[0] != 0; s += (strlen(s) + 1))
         ++result;
    
       return result;
    }