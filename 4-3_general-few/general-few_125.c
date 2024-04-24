#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char buffer[512];
    
    _snprintf(buffer, sizeof(buffer), "SomeString");
    
    return 0;
}
