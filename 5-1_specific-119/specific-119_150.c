float * foo = NULL;
float * bar = NULL;

void update()
{
    ...
    foo = (float *)malloc( a * 2 * sizeof(float));
    if(foo == NULL) {
        // Handle allocation failure
    }
    ...
    bar = (float *)realloc( foo, a * 2 * sizeof(float));
    if(bar == NULL) {
        free(foo); // Free the original memory if realloc fails
        // Handle reallocation failure
    }
    ...
    free( foo ); // Free memory allocated by malloc, not realloc
    ...
}

