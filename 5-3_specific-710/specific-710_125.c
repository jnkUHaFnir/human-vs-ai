#include <stdio.h>
#include <stdlib.h>

int main (void)
{
    char buffer[512];

    _snprintf(buffer, sizeof(buffer), "SomeString"); // Using _snprintf instead of snprintf

    return 0;
}
