void update()
{
    ...
    foo = (float *)malloc(a * 2 * sizeof(float));
    ...
    bar = (float *)realloc(foo, a * 4 * sizeof(float)); // Note: Changed to a * 4 to emphasize resizing
    if(bar != NULL)
    {
        // Realloc was successful, foo is invalidated and should not be used or freed.
        foo = bar; // If you still want to use foo in the future, you can reassign it.
    }
    else
    {
        // Realloc failed, original memory block pointed to by foo is still valid
        // You can decide to free foo here or do error handling
        free(foo);
        // Handle realloc failure (may need to set foo to NULL to prevent future use)
    }
    
    // Operations on the valid memory (now pointed to by foo/bar)
    ...

    if(bar != NULL)
    {
        free(bar); // No error expected here as bar (or foo, if reassigned) points to valid memory
    }
}
