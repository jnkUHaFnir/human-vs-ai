void update()
{
    ...
    foo = (float *) malloc(a * 2 * sizeof(float));
    ...
    foo = (float *) realloc(foo, a * 2 * sizeof(float));
    ...
    // You don't need to free foo here since the old foo has been reallocated
    ...
    if (foo != NULL)
    {
        free(foo);
    }
}
