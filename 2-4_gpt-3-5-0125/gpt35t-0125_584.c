#include <stdio.h>
#include <string.h>
#include <stdarg.h>

void continue_snprintf(char* buf, size_t size, const char* format, ...)
{
    va_list args;
    va_start(args, format);

    // Find the length of the formatted string
    int length = vsnprintf(buf, size, format, args);

    va_end(args);

    // Move the buffer pointer and size accordingly
    buf += length;
    size -= length;

    // Make sure there is space for the null terminator
    if (size > 1)
    {
        // Repeat the formatting with the adjusted buffer
        va_start(args, format);
        vsnprintf(buf, size, format, args);
        va_end(args);
    }
}

int main()
{
    char buf1[16] = {0};
    char buf2[16] = {0};
    
    continue_snprintf(buf1, sizeof buf1, "Lorem ipsum %d dolor sit", 123456);
    assert(strcmp(buf1, "Lorem ipsum 123") == 0);  // ok

    continue_snprintf(buf2, sizeof buf2, "%d dolor sit", 123456);
    assert(strcmp(buf2, "456 dolor sit") == 0);  // expected result

    return 0;
}
