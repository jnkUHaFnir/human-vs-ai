void update()
{
    ...
    foo = (float *)malloc( a * 2 * sizeof(float));
    ...
    bar = (float *)realloc( foo, a * 2 * sizeof(float));
    ...
    // Do your operations on bar
    ...
    free( foo );
}
