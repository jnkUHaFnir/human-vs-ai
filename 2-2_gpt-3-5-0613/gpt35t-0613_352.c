#include <stdarg.h>

int gc_asprintf(char **strp, const char *format, ...)
{
    int size;
    va_list args;

    va_start(args, format);
    size = vsnprintf(NULL, 0, format, args);
    va_end(args);

    if (size < 0)
    {
        return -1;
    }

    *strp = GC_MALLOC(size + 1);
    if (*strp == NULL)
    {
        return -1;
    }

    va_start(args, format);
    size = vsnprintf(*strp, size + 1, format, args);
    va_end(args);
    
    return size;
}
static string printInt(Object self) {
    string str;
    gc_asprintf(&str, "%lu", getValueInt(self));
    return str;
}
