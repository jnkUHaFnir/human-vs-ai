    #ifdef _MSC_VER
    
    #define snprintf c99_snprintf
    
    inline int c99_snprintf(char* str, size_t size, const char* format, ...)
    {
    	int count;
    	va_list ap;
    
    	va_start(ap, format);
    	count = c99_vsnprintf(str, size, format, ap);
    	va_end(ap);
    
    	return count;
    }
    
    inline int c99_vsnprintf(char* str, size_t size, const char* format, va_list ap)
    {
    	int count = -1;
    
    	if (str != NULL)
    		count = _vsnprintf_s(str, size, _TRUNCATE, format, ap);
    	if (count == -1)
    		count = _vscprintf(format, ap);
    
    	return count;
    }
    
    #endif // _MSC_VER