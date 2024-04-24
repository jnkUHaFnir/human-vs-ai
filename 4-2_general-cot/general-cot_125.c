#include <stdio.h>

int main (void)
{
    char buffer[512];

    _snprintf(buffer, sizeof(buffer), "SomeString");

    // Ensure null-termination
    buffer[sizeof(buffer) - 1] = '\0';

    return 0;
}
