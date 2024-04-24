void update()
{
    ...
    foo = (float *)malloc( a * 2 * sizeof(float));
    if(foo == NULL)
    {
        // handle allocation failure
    }
    
    ...
    
    float * temp = (float *)realloc( foo, a * 2 * sizeof(float));
    if(temp == NULL)
    {
        // handle reallocation failure, original pointer 'foo' still valid
    }
    else
    {
        // 'temp' can now be assigned back to 'foo'
        foo = temp;
    }
    
    ...
    
    free( foo ); // only free the original pointer allocated with malloc
    ...
}
