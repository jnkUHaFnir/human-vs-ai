#include <stdio.h>
#include <stdlib.h>

#define snprintf(buffer, size, format, ...) _snprintf_s(buffer, size, _TRUNCATE, format, __VA_ARGS__)

int main(void)
{
    char buffer[512];

    snprintf(buffer, sizeof(buffer), "%s", "SomeString");

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    char buffer[512];
    
    _snprintf_s(buffer, sizeof(buffer), _TRUNCATE, "SomeString");
    
    return 0;
}
