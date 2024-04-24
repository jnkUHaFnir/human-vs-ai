float* foo = NULL;
float* bar = NULL;

void update()
{
    ...
    foo = (float *)malloc(a * 2 * sizeof(float));
    ...
    bar = (float *)realloc(foo, a * 2 * sizeof(float));
    ...
    free(foo);
    foo = NULL; // Set foo to NULL after freeing it

    ...
    // Only free bar if it's not NULL
    if (bar != NULL)
    {
        free(bar);
        bar = NULL; // Set bar to NULL after freeing it
    }
}
