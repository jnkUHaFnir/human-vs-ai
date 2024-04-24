void update()
{
    ...
    foo = (float *)malloc( a * 2 * sizeof(float));
    ...
    bar = (float *)realloc( foo, a * 2 * sizeof(float)); // Note that bar may point to the same location as foo
    if(bar == NULL) {
        // Handle realloc failure
        // Don't free foo here as realloc already frees it in case of failure
    } else if(bar != foo) { // Check if bar points to a different location than foo
        free(foo); // Free foo only if bar is pointing to a different memory location
    }
    ...
    // You can safely use bar from here onwards
}
