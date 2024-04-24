    #ifdef _MSC_VER 
        // from Visual Studio 2005 onwards
        // https://msdn.microsoft.com/en-us/library/2ts7cx93%28v=vs.80%29.aspx
        #include <stdio.h>    
        #define snprintf _snprintf
    #endif