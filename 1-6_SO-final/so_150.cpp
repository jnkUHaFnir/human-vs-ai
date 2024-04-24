    float * foo = NULL;
    
    void update()
    {
        ...
        foo = (float *)malloc( a * 2 * sizeof(float));
        ...
        foo = (float *)realloc( foo, a * 2 * sizeof(float));
        ...
        if(foo != NULL)
        {
            free(foo);
        }
    }