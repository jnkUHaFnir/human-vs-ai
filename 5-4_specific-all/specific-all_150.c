#include <stdio.h>
#include <stdlib.h>

float * foo = NULL;
float * bar = NULL;

void update()
{
    int a = 5; // for example
    foo = (float *)malloc( a * 2 * sizeof(float));
    // Check if foo is allocated successfully before reallocating
    if(foo == NULL)
    {
        // handle allocation failure
        return;
    }
    
    // do something with foo
    
    bar = (float *)realloc(foo, a * 2 * sizeof(float));
    if(bar == NULL)
    {
        // handle reallocation failure, foo still pointing to the original memory block
        // no need to free foo here to avoid double-free
        return;
    }
    
    // do something with bar
    
    // free the memory only once after reallocating
    free(bar);
    bar = NULL;
}

int main()
{
    update();
    return 0;
}
