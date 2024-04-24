float * foo = NULL;
float * bar = NULL;

void update()
{
    ...
    foo = (float *)malloc( a * 2 * sizeof(float));
    ...
    // If realloc fails it returns NULL and original memory allocation (foo) is not freed
    float * new_ptr = (float *)realloc( foo, a * 2 * sizeof(float));
    if (new_ptr != NULL) {
        // Realloc succeeded, update bar to point to the reallocated memory
        bar = new_ptr;
    } else {
        // Realloc failed, bar should continue to use the original memory pointed by foo and you have to free it later.
        bar = foo;
    }
    ...
    // Now you should only free bar, as it points to the memory you've been working with
    // No need to check for NULL as free can handle a NULL pointer
    free(bar);
    // Set both pointers to NULL to avoid using them after freeing
    bar = NULL;
    foo = NULL;
    ...
}
