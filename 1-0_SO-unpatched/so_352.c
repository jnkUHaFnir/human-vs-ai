    #include <limits.h>
    #define STRINGIFY(x) #x
    #define EXPAND_AND_STRINGIFY(x) STRINGIFY(X)    
    ...
    unsigned long intValue = getValueInt(self);
    size_t maxLength = (sizeof EXPAND_AND_STRINGIFY(ULONG_MAX)) + 1;
    char *buf = malloc(maxLength);
    
    int result = snprintf(buf, maxLength, "%lu", intValue);
    if (result > maxLength)
    {
        // shouldn't ever get here, but just in case the buffer is too small
        // we reallocate it to the correct size and try again.
        buf = malloc(result);
        snprintf(buf, result, "%lu", intValue);
    }
    return buf;