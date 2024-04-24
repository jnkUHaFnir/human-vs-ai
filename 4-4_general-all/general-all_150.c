float * foo = NULL;
float * bar = NULL;

void update()
{
    ...
    foo = (float *)malloc(a * 2 * sizeof(float));
    ...
    bar = (float *)realloc(foo, a * 2 * sizeof(float));
    ...
    free(foo); // Free the original memory allocated by malloc

    if (bar != NULL && bar != foo)
    {
        free(bar); // Free the memory only if it has been reallocated to a different location
    }
}
